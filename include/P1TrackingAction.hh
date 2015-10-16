#ifndef P1TrackingAction_h
#define P1TrackingAction_h 1

#include "G4UserTrackingAction.hh"

class P1TrackingAction : public G4UserTrackingAction{

public: 
	P1TrackingAction();
	~P1TrackingAction();

	void PreUserTrackingAction(const G4Track*);
	void PostUserTrackingAction(const G4Track*);
};


#endif 
