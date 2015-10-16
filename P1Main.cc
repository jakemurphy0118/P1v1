#include "P1DetectorConstruction.hh"
#include "P1PrimaryGeneratorAction.hh"
#include "P1RunAction.hh"
//#include "S1EventAction.hh"
#include "P1SteppingAction.hh"
//#include "S1Histo.hh"
//#include "S1PhysicsList.hh"
#include "P1TrackingAction.hh"
#include "P1Histo.hh"
#include "P1HistoMessenger.hh"
#include "Shielding.hh"

#include "G4UImanager.hh"
#include "G4RunManager.hh"
#include "G4VisExecutive.hh"

int main(int argc, char** argv){
	G4RunManager* runManager = new G4RunManager;
	
	P1DetectorConstruction* detector = new P1DetectorConstruction;
	runManager->SetUserInitialization(detector);

	G4VUserPhysicsList* shielding = new Shielding;
  	runManager->SetUserInitialization(shielding);

	P1Histo* histo = new P1Histo();
	
	P1PrimaryGeneratorAction* generatorAction = new P1PrimaryGeneratorAction;
	runManager->SetUserAction(generatorAction);

	P1TrackingAction* trackAction = new P1TrackingAction;
	runManager->SetUserAction(trackAction);

	P1RunAction* runAction = new P1RunAction(histo);
 	runManager->SetUserAction(runAction);

 	//S1EventAction* eventAction = new S1EventAction(runAction, histo);
  	//runManager->SetUserAction(eventAction);

  	P1SteppingAction* steppingAction = new P1SteppingAction(detector, runAction, histo);
 	runManager->SetUserAction(steppingAction);

#ifdef G4VIS_USE
	G4VisManager* visManager = new G4VisExecutive;
  	visManager->Initialize();
#endif

	G4UImanager* UIManager = G4UImanager::GetUIpointer();
	if (argc != 1)
    	{
      		G4String command = "/control/execute ";
      		G4String fileName = argv[1];
      		UIManager->ApplyCommand(command+fileName);
    	}
  
  	delete runManager;

#ifdef G4VIS_USE
  	delete visManager;
#endif
  
  	return 0;
}
