#include "P1DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Element.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"


P1DetectorConstruction::P1DetectorConstruction()
 : G4VUserDetectorConstruction()
{}
P1DetectorConstruction::~P1DetectorConstruction(){
}

G4VPhysicalVolume* P1DetectorConstruction::Construct(){
//------------------------------instance of G4NistManager
	G4NistManager* man = G4NistManager::Instance();

//------------------------------create world box 
	G4double world_hx = 5.0*m;
	G4double world_hy = 5.0*m;
	G4double world_hz = 5.0*m;
	G4Box* worldBox = new G4Box("World", world_hx, world_hy, world_hz);
	
	G4Material *Vacuum = man->FindOrBuildMaterial("G4_Galactic");

	G4LogicalVolume* worldLog = new G4LogicalVolume(worldBox, Vacuum, "World");

	G4VPhysicalVolume* fPhysWorld = new G4PVPlacement(0, G4ThreeVector(), worldLog, "World", 0, false, 0, true);

//------------------------------kapton foil
//-----------------------------------------------define kapton
	G4String name, symbol;
	G4double a, z, density;	
	G4int ncomponents, natoms;
	G4double fractionmass;

	a = 1.01*g/mole;
	G4Element* elH = new G4Element(name="Hydrogen", symbol="H", z=1., a);

	a = 12.01*g/mole;
	G4Element* elC = new G4Element(name="Carbon", symbol="C", z=6., a);

	a = 14.01*g/mole;
	G4Element* elN = new G4Element(name="Nitrogen", symbol="N", z=7., a);

	a = 16.00*g/mole;
	G4Element* elO = new G4Element(name="Oxygen", symbol="O", z=8., a);

	density = 1.42*g/cm3;
	G4Material* Kapton = new G4Material(name="Kapton", density, ncomponents=4);
	Kapton->AddElement(elH, fractionmass=2.6362*perCent);
	Kapton->AddElement(elC, fractionmass=69.1133*perCent);
	Kapton->AddElement(elN, fractionmass=7.3270*perCent);
	Kapton->AddElement(elO, fractionmass=20.9235*perCent);

//-----------------------------------------------create kapton foil (2)
	G4double foil_hx = 0.5*cm;
	G4double foil_hy = 0.5*cm;
	G4double foil_hz = 0.0025*mm;
	G4Box* foilBox = new G4Box("Foil", foil_hx, foil_hy, foil_hz);

	G4LogicalVolume* foilLog = new G4LogicalVolume(foilBox, Kapton, "Foil");

	G4double pos_x = 0.0*mm;
	G4double pos_y = 0.0*mm;
	G4double pos_z = 0.005*mm;
	//G4VPhysicalVolume* fPhysTopFoil = 
	new G4PVPlacement(0, G4ThreeVector(pos_x, pos_y, pos_z), foilLog, "TopFoil", worldLog, false, 0, true);
	pos_z = -0.005*mm;
	//G4VPhysicalVolume* fPhysBottomFoil = 
	new G4PVPlacement(0, G4ThreeVector(pos_x, pos_y, pos_z), foilLog, "BottomFoil", worldLog, false, 0, true);
//-----------------------------------------------visualization attributes
	G4VisAttributes* kaplonVisAtt = new G4VisAttributes(G4Colour(0.0,1.0,1.0));
	foilLog->SetVisAttributes(kaplonVisAtt);

//------------------------plastic scintilator 
//-----------------------------------------------define polyvinyltoluene
	density = 1.032*g/cm3;	
	G4Material* PVT = new G4Material(name="PVT", density, ncomponents=2);
	PVT->AddElement(elH, fractionmass=8.5*perCent);
	PVT->AddElement(elC, fractionmass=91.5*perCent);

//-----------------------------------------------create scintilator (2) 
	G4double scint_hx = 0.5*cm;
	G4double scint_hy = 0.5*cm;
	G4double scint_hz = 0.25*mm;
	G4Box* scintBox = new G4Box("Scint", scint_hx, scint_hy, scint_hz);

	G4LogicalVolume* scintLog = new G4LogicalVolume(scintBox, PVT, "Scint");

	pos_z = 0.258*mm;
	//G4VPhysicalVolume* fPhysTopScint = 
	new G4PVPlacement(0, G4ThreeVector(pos_x, pos_y, pos_z), scintLog, "TopScint", worldLog, false, 0, true);
	pos_z = -0.258*mm;
	//G4VPhysicalVolume* fPhysBottomScint = 
	new G4PVPlacement(0, G4ThreeVector(pos_x, pos_y, pos_z), scintLog, "BottomScint", worldLog, false, 0, true);
//------------------------------------------------visualization attributes
	G4VisAttributes* scintVisAtt = new G4VisAttributes(G4Colour(1.0,1.0,0.0));
	scintLog->SetVisAttributes(scintVisAtt);

//------------------------aerogel
//----------------------------------------define aerogel
	density = 1.000*g/cm3;
	G4Material* H2O = new G4Material(name="Water", density, ncomponents=2);
	H2O->AddElement(elH, natoms=2);
	H2O->AddElement(elO, natoms=1);
	
	a = 28.09*g/mole;
	G4Element* elSi = new G4Element(name="Silicon", symbol="Si", z=14., a);
	
	density = 2.200*g/cm3;
	G4Material* SiO2 = new G4Material(name="SiliconOxide", density, ncomponents=2);
	SiO2->AddElement(elSi, natoms=1);
	SiO2->AddElement(elO, natoms=2);

	G4Material *Air = man->FindOrBuildMaterial("G4_AIR");	
	
	density = 0.020*g/cm3;	
	G4Material* Aerogel = new G4Material(name="Aerogel", density, ncomponents=3);
	Aerogel->AddMaterial(SiO2, fractionmass=62.5*perCent);
	Aerogel->AddMaterial(Air, fractionmass=37.4*perCent);
	Aerogel->AddElement(elC, fractionmass=0.1*perCent);

//----------------------------------------create aerogel
	G4double aerogel_hx = 0.5*cm;
	G4double aerogel_hy = 0.5*cm;
	G4double aerogel_hz = 0.5*cm;
	G4Box* aeroBox = new G4Box("Aero", aerogel_hx, aerogel_hy, aerogel_hz);
	
	G4LogicalVolume* aeroLog = new G4LogicalVolume(aeroBox, Aerogel, "Aero");
	
	pos_z = 0.555*cm;
	//G4VPhysicalVolume* fPhysTopAero = 
	new G4PVPlacement(0, G4ThreeVector(pos_x, pos_y, pos_z), aeroLog, "TopAero", worldLog, false, 0, true);
	pos_z = -0.555*cm;
	//G4VPhysicalVolume* fPhysBottomAero = 
	new G4PVPlacement(0, G4ThreeVector(pos_x, pos_y, pos_z), aeroLog, "BottomAero", worldLog, false, 0, true); 
//----------------------------------------visualization attributes
	G4VisAttributes* aeroVisAtt = new G4VisAttributes(G4Colour(1.0,0.0,0.0));
	aeroLog->SetVisAttributes(aeroVisAtt);



return fPhysWorld;
}

