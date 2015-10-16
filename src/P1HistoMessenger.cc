#include "P1HistoMessenger.hh"
#include "P1Histo.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

P1HistoMessenger::P1HistoMessenger(P1Histo* histo)
  : fHisto(histo)
{
  fP1Dir = new G4UIdirectory("/P1/");
  fP1Dir->SetGuidance("UI commands for P1");

  fHistoDir = new G4UIdirectory("/P1/histo/");
  fHistoDir->SetGuidance("Histogram initialization");

  fHistoTitleCmd = new G4UIcmdWithAString("/P1/histo/setHistoTitle", this);
  fHistoTitleCmd->SetGuidance("Provide a title for the histogram");
  fHistoTitleCmd->SetParameterName("title", false);
  fHistoTitleCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

  fxLowerBoundCmd = new G4UIcmdWithADoubleAndUnit("/P1/histo/setxLowerBound", this);
  fxLowerBoundCmd->SetGuidance("Set the x lower bound of the histogram");
  fxLowerBoundCmd->SetParameterName("lBound", false);
  fxLowerBoundCmd->SetRange("lBound>=-5.");
  fxLowerBoundCmd->SetUnitCategory("Distance");
  fxLowerBoundCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

  fxUpperBoundCmd = new G4UIcmdWithADoubleAndUnit("/P1/histo/setxUpperBound",this);
  fxUpperBoundCmd->SetGuidance("Set the x upper bound of the histogram");
  fxUpperBoundCmd->SetParameterName("uBound", false);
  fxUpperBoundCmd->SetUnitCategory("Distance");
  fxUpperBoundCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

  fzLowerBoundCmd = new G4UIcmdWithADoubleAndUnit("/P1/histo/setzLowerBound", this);
  fzLowerBoundCmd->SetGuidance("Set the z lower bound of the histogram");
  fzLowerBoundCmd->SetParameterName("lBound", false);
  fzLowerBoundCmd->SetRange("lBound>=-5.");
  fzLowerBoundCmd->SetUnitCategory("Distance");
  fzLowerBoundCmd->AvailableForStates(G4State_PreInit, G4State_Idle);

  fzUpperBoundCmd = new G4UIcmdWithADoubleAndUnit("/P1/histo/setzUpperBound",this);
  fzUpperBoundCmd->SetGuidance("Set the z upper bound of the histogram");
  fzUpperBoundCmd->SetParameterName("uBound", false);
  fzUpperBoundCmd->SetUnitCategory("Distance");
  fzUpperBoundCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
}

P1HistoMessenger::~P1HistoMessenger()
{
  delete fP1Dir;
  delete fHistoDir;
  delete fHistoTitleCmd;
  delete fxLowerBoundCmd;
  delete fxUpperBoundCmd;
  delete fzLowerBoundCmd;
  delete fzUpperBoundCmd;
}

//void P1HistoMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
//{
//  if ( command == fHistoTitleCmd )
//    {
//      fHisto->setHistoTitle(newValue);
//    }
//  if ( command == fLowerBoundCmd )
//    {
//      fHisto->setLowerBound(fLowerBoundCmd->GetNewDoubleValue(newValue));
//    }
//  if (command == fUpperBoundCmd)
//    {
//      fHisto->setUpperBound(fUpperBoundCmd->GetNewDoubleValue(newValue));
//   }
//}
