#ifndef P1DetectorConstruction_h
#define P1DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;

class P1DetectorConstruction : public G4VUserDetectorConstruction{

public:
	P1DetectorConstruction();
	virtual ~P1DetectorConstruction();
public:
	virtual G4VPhysicalVolume* Construct();
	//const G4VPhysicalVolume* GetTopAero(){ return fPhysTopAero;}
	//const G4VPhysicalVolume* GetBottomAero(){ return fPhysBottomAero;}
private:
	//G4VPhysicalVolume* fPhysTopFoil;
	//G4VPhysicalVolume* fPhysBottomFoil;
	//G4VPhysicalVolume* fPhysTopScint;
	//G4VPhysicalVolume* fPhysBottomScint;
	//G4VPhysicalVolume* fPhysTopAero;
	//G4VPhysicalVolume* fPhysBottomAero;
	G4VPhysicalVolume* fPhysWorld;

};

#endif
