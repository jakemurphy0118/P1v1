#ifndef P1Histo_h
#define P1Histo_h 1

#include "globals.hh"
#include "TH1.h"

class TTree;
class TFile;
class TH2D;

class P1HistoMessenger;

class P1Histo
{
public:
  P1Histo();
  ~P1Histo();

  void book();
  void save();

  void setHistoTitle(G4String);
  void setxLowerBound(G4double);
  void setxUpperBound(G4double);
  void setzLowerBound(G4double);
  void setzUpperBound(G4double);
  G4String getHistoTitle()
  {
    return fHistoTitle;
  };
  G4double getxLowerBound()
  {
    return fxLowerBound;
  }
  G4double getxUpperBound()
  {
    return fxUpperBound;
  }
  G4double getzLowerBound()
  {
    return fzLowerBound;
  }
  G4double getzUpperBound()
  {
    return fzUpperBound;
  }


  void FillHisto(G4double xbin, G4double zbin, G4double weight = 1.0);
  void Normalize(G4double fac);
 
  void FillNtuple(G4double XValue, G4double YValue, G4double ZValue);

private:
  TFile* fRootFile;
  TH2D* fHisto;
  TTree* fNtuple;

  P1HistoMessenger* fHistoMessenger;



  G4String fHistoTitle;
  G4double fxLowerBound;
  G4double fxUpperBound;
  G4double fzLowerBound;
  G4double fzUpperBound;
  G4double fXValue;
  G4double fYValue;
  G4double fZValue;
};

#endif
