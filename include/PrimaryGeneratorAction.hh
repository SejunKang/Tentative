#ifndef PRIMARYGENERATORACTION_HH
#define PRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
	public:
		PrimaryGeneratorAction();
		virtual ~PrimaryGeneratorAction();
		virtual void GeneratePrimaries(G4Event *event);
	
	private:
		G4ParticleGun *ParGun;
};
#endif
