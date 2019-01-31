#include "stdafx.h"
#include "WorkingMachine.h"


CWorkingMachine::CWorkingMachine()
{
}


CWorkingMachine::~CWorkingMachine()
{
}

void CWorkingMachine::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponents.push_back(component);
	component->SetMachine(this);
}

void CWorkingMachine::AddMotor(std::shared_ptr<CMotor> motor)
{
	mMotors.push_back(motor);
	motor->SetMachine(this);
}

void CWorkingMachine::DrawMachine(Gdiplus::Graphics * graphics, int x, int y)
{
	

	for (auto motor : mMotors)
	{
		motor->Draw(graphics, x, y);
	}

	for (auto component : mComponents)
	{
		component->Draw(graphics, x, y);
	}
}

void CWorkingMachine::SetMachineTime(double time)
{
	for (auto motor : mMotors)
	{
		motor->SetMotorTime(time);
		motor->SetMotorRotation();
	}
}