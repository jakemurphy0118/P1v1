#ifndef P1SteppingAction_h
#define P1SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"
#include "P1Histo.hh"

class P1DetectorConstruction;
class P1RunAction;
class P1Histo;

class P1SteppingAction : public G4UserSteppingAction
{
public:
  P1SteppingAction(P1DetectorConstruction*, P1RunAction*, P1Histo*);
  virtual ~P1SteppingAction();

  virtual void UserSteppingAction(const G4Step*);


private:
  P1DetectorConstruction* fDetector;
  P1RunAction* fRunAction;
  P1Histo* fHisto;
};

#endif
