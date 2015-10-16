#include <TH2D.h>
#include <TFile.h>
#include <TTree.h>
#include <CLHEP/Units/SystemOfUnits.h>

#include "P1Histo.hh"
#include "P1HistoMessenger.hh"
#include "G4UnitsTable.hh"
//---------------NEEDS EDITING-------------------------------------------------------------
P1Histo::P1Histo()
  : fRootFile(0), fNtuple(0), fxLowerBound(0), fxUpperBound(0), fzLowerBound(0), fzUpperBound(0), fXValue(0), fYValue(0), fZValue(0)
{
  fHisto = 0;
  fNtuple = 0;
  fHistoMessenger = new P1HistoMessenger(this);
}

P1Histo::~P1Histo()
{
  if (fRootFile) delete fRootFile;
  delete fHistoMessenger;
}

void P1Histo::setHistoTitle(G4String val)
{
  fHistoTitle = val;
}

void P1Histo::setxLowerBound(G4double val)
{
  fxLowerBound = val;
}

void P1Histo::setxUpperBound(G4double val)
{
  fxUpperBound = val;
}

void P1Histo::setzLowerBound(G4double val)
{
  fzLowerBound = val;
}

void P1Histo::setzUpperBound(G4double val)
{
  fzUpperBound = val;
}


void P1Histo::book()
{
  G4String fileName = "P1Output.root";

  fRootFile = new TFile(fileName, "RECREATE");

  fHisto = new TH2D("P1Histo", fHistoTitle, 100, fxLowerBound, fxUpperBound, 100, fzLowerBound, fzUpperBound);

  fNtuple = new TTree("P1Tree", "Stop Position Tree");
  fNtuple->Branch("X", &fXValue, "X Position");
  fNtuple->Branch("Y", &fYValue, "Y Position");
  fNtuple->Branch("Z", &fZValue, "Z Position");
}

void P1Histo::save()
{
  if (fRootFile)
    {
      fRootFile->Write();
      fRootFile->Close();
    }
}

void P1Histo::FillHisto(G4double xbin, G4double zbin, G4double weight)
{
  fHisto->Fill(xbin, zbin, weight);
}

void P1Histo::Normalize(G4double fac)
{
  fHisto->Scale(fac);
}

void P1Histo::FillNtuple(G4double XValue, G4double YValue, G4double ZValue)
{
  fXValue = XValue;
  fYValue = YValue;
  fZValue = ZValue;
  fNtuple->Fill();
}


