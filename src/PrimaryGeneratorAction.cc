#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4RandomTools.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
	ParGun = new G4ParticleGun();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
	delete ParGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event *event)
{
}

