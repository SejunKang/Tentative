#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

ActionInitialization::ActionInitialization()
{
}

ActionInitialization::~ActionInitialization()
{
}

void ActionInitialization::BuildForMaster()
{
	SetUserAction(new RunAction);
}

void ActionInitialization::Build() const
{
	EventAction *event = new EventAction();
	SetUserAction(new PrimaryGeneratorAction);
	SetUserAction(new RunAction);
	SetUserAction(event);
	SetUserAction(new SteppingAction(event));
}
