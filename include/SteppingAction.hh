#ifndef STEPPINGACTION_HH
#define STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "EventAction.hh"

class SteppingAction : public G4UserSteppingAction
{
	public:
		SteppingAction(EventAction *event);
		virtual ~SteppingAction();
		virtual void UserSteppingAction(G4Step *step);

	private:
		EventAction *m_event;
};

#endif

