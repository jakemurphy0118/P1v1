#include "P1RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "P1SteppingAction.hh"

P1RunAction::P1RunAction(P1Histo* histo)
: G4UserRunAction(), fHisto(histo)
{}

P1RunAction::~P1RunAction()
{}

void P1RunAction::BeginOfRunAction(const G4Run* aRun){
	G4cout << "BEGIN RUN \n\n\n\n";
	nStopped = 0;
	nThrough = 0;
	
	fHisto->book();

}

void P1RunAction::EndOfRunAction(const G4Run* aRun){
	//----------------output the percentage of e+ incident on the aerogel that were stopped-----------
	G4cout << "Number of e+ stopped: " << nStopped << G4endl;
	G4cout << "Number of e+ through: " << nThrough << G4endl;	
	G4cout << "The percentage of e+ stopped incident on aerogel is: " << 100* nStopped/(nStopped + nThrough) 
	<< "%" << G4endl;

	fHisto->save();
}


