#ifndef P1RunAction_h
#define P1RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "P1Histo.hh"

class G4Run;
class P1Histo;

class P1RunAction : public G4UserRunAction{

public: 
	P1RunAction(P1Histo*);
	virtual ~P1RunAction();

	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);

	void IncrementStopped(){ nStopped++;}
	void IncrementThrough(){ nThrough++;}


private:
	P1Histo* fHisto;
	G4int nStopped;
	G4int nThrough;


	
};
#endif
