#include "P1PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4GeneralParticleSource.hh"

#include "globals.hh"

P1PrimaryGeneratorAction::P1PrimaryGeneratorAction()
  : G4VUserPrimaryGeneratorAction(), fParticleSource(0)
{
  fParticleSource = new G4GeneralParticleSource();
}

P1PrimaryGeneratorAction::~P1PrimaryGeneratorAction()
{
  delete fParticleSource;
}

void P1PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  fParticleSource->GeneratePrimaryVertex(anEvent);
}
