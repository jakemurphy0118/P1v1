#ifndef P1PrimaryGeneratorAction_h
#define P1PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4GeneralParticleSource;
class G4Event;

class P1PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
  P1PrimaryGeneratorAction();
  virtual ~P1PrimaryGeneratorAction();

  virtual void GeneratePrimaries(G4Event*);
  
  private:
  G4GeneralParticleSource*  fParticleSource;
};

#endif

