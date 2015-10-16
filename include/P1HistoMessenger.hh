#ifndef P1HistoMessenger_h
#define P1HistoMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class P1Histo;

class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithAString;

class P1HistoMessenger : public G4UImessenger
{
public:
  P1HistoMessenger(P1Histo*);
  ~P1HistoMessenger();

  //void SetNewValue(G4UIcommand*, G4String);

private:
  P1Histo* fHisto;

  G4UIdirectory* fP1Dir;
  G4UIdirectory* fHistoDir;
  G4UIcmdWithAString* fHistoTitleCmd;
  G4UIcmdWithADoubleAndUnit* fxLowerBoundCmd;
  G4UIcmdWithADoubleAndUnit* fxUpperBoundCmd;
  G4UIcmdWithADoubleAndUnit* fzLowerBoundCmd;
  G4UIcmdWithADoubleAndUnit* fzUpperBoundCmd;
};
#endif
