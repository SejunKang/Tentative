#ifndef RUNACTION_HH
#define RUNACTION_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
class RunAction : public G4UserRunAction
{
	public:
		RunAction();
		virtual ~RunAction();
		virtual void BeginOfRunAction(G4Run *run);
		virtual void EndOfRunAction(G4Run *run);
};

#endif
