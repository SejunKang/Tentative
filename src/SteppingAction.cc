#include "SteppingAction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Step.hh"
#include "G4TrackStatus.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"

SteppingAction::SteppingAction(EventAction *event)
{
}

SteppingAction::~SteppingAction()
{
}

void SteppingAction::UserSteppingAction(G4Step *step)
{
}
