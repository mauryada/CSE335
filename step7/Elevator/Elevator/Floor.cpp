#include "stdafx.h"
#include "Floor.h"
#include "Controller.h"

CFloor::CFloor()
{
}


CFloor::~CFloor()
{
}

/** Set the value of Up for a floor.
* \param s The new value for mUp
*/
void CFloor::SetUp(bool s)
{
	mUp = s;
	mController->SetCallLight(mFloor, CElevatorController::Up, mUp);
}

/** Set the value of Panel for a floor.
* \param p The new value for mPanel
*/
void CFloor::SetPanel(bool p)
{
	mPanel = p;
	mController->SetPanelFloorLight(mFloor, mPanel);
}


/** Set the value of Up for a floor.
* \param s The new value for mDown
*/
void CFloor::SetDown(bool s)
{
	mDown = s;
	mController->SetCallLight(mFloor, CElevatorController::Down, mDown);
}