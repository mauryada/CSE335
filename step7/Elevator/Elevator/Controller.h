#pragma once
#include "ElevatorController.h"
#include "Floor.h"

class CController :
	public CElevatorController
{
public:
	CController();
	virtual ~CController();
	virtual void OnOpenPressed() override;
	virtual void OnClosePressed() override;
	virtual void OnCallUpPressed(int floor) override;
	virtual void OnCallDownPressed(int floor) override;

	int WhatFloorUp();

	int WhatFloorToGoTo();

	int WhatFloorDown();

	/// The state machine states
	enum States { Idle, DoorOpening, DoorOpen, DoorClosing, Moving, Stop };
	virtual void Service() override;
	

private:
	int mFloor = 1;
	States mState = Idle;   ///< The current state
	void SetState(States state);
	double mStateTime = 0;  ///< The time in a current state
							/// An object for each floor
	CFloor mFloors[NumFloors];

	boolean mGoingUp = true;
	
};

