#include "P1SteppingAction.hh"
//#include "P1EventAction.hh"
#include "P1DetectorConstruction.hh"
#include "P1RunAction.hh"
#include "G4UserSteppingAction.hh"
#include "G4ThreeVector.hh"

#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4SystemOfUnits.hh"

P1SteppingAction::P1SteppingAction(P1DetectorConstruction* detector, P1RunAction* RA, P1Histo* histo)
  : G4UserSteppingAction(), fDetector(detector), fRunAction(RA), fHisto(histo)
{}

P1SteppingAction::~P1SteppingAction()
{}

void P1SteppingAction::UserSteppingAction(const G4Step* aStep){
	
	G4StepPoint* point1 = aStep->GetPreStepPoint();
	G4StepPoint* point2 = aStep->GetPostStepPoint();

	G4Track* theTrack = aStep->GetTrack();
	G4ParticleDefinition* particleType = theTrack->GetDefinition();
	G4String particleName = particleType->GetParticleName();
	G4String volumeName = point1->GetPhysicalVolume()->GetLogicalVolume()->GetName();
	G4ThreeVector pos1, pos2;
	G4double pos2x, pos2y, pos2z, pos2zPlus;


	if(particleName == "e+"){
		if(point1->GetStepStatus() == fGeomBoundary && volumeName == "Aero"){		
			pos1 = point1->GetPosition();
			//G4cout << "Aerogel Entry Position (cm): " << pos1/cm << G4endl;
		}
	
		if(volumeName == "Aero"){
		//------track step status and kinetic energy when in aerogel
			//G4cout << "Step Status is: " << point2->GetStepStatus() << G4endl;
			//G4cout << "KE (keV) is: " << point2->GetKineticEnergy()/keV << G4endl;
			
		//------if step status is 2 (aerogel stopped e+) increment nStopped and get endpoint
			if(point2->GetStepStatus() == 2){
				pos2 = point2->GetPosition();
				pos2x = pos2.x();
				pos2y = pos2.y();	
				pos2z = pos2.z();
		//------fill tree with e+ endpts in aerogel
				fHisto->FillNtuple(pos2x/cm, pos2y/cm, pos2z/cm);
		//------fill histo with x value and absolute value of z value (to get data from both aerogels)		
				if(pos2z < 0.000000){pos2zPlus = -1*pos2z;}
				else {pos2zPlus = pos2z;}
				fHisto->FillHisto(pos2x/cm, pos2zPlus/cm, 1);
				
				fRunAction->IncrementStopped();
				
				G4cout << "\n\n STOPPED \n\n";
			}
		//------if step status is 1 (e+ went through the aerogel) increment nThrough			
			if(point2->GetStepStatus() == 1){
				fRunAction->IncrementThrough();
				G4cout << "\n\n THROUGH \n\n";
			}
	
		}	
	}
}
