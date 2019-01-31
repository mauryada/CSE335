#include "stdafx.h"
#include "ActualMachine.h"
#include "MachineFactory1.h"


CActualMachine::CActualMachine()
{
	SetMachineNumber(1);
}


CActualMachine::~CActualMachine()
{
}


void CActualMachine::DrawMachine(Gdiplus::Graphics * graphics)
{
	mWorkingMachine->DrawMachine(graphics, mPosition.X, mPosition.Y);
}

void CActualMachine::SetMachineNumber(int machine)
{
	mMachineNumber = machine;
	if (mMachineNumber == 1)
	{
		CMachineFactory1 factory1;
		mWorkingMachine = factory1.CreateMachine();
	}
}


void CActualMachine::SetMachineFrame(int frame)
{
	mTime = frame / mFrameRate * mSpeed;
	mWorkingMachine->SetMachineTime(mTime);
	
}





int CActualMachine::GetMachineNumber()
{
	return mMachineNumber;
}


void CActualMachine::SetLocation(int x, int y)
{
	mPosition = Gdiplus::Point(x, y);
}


void CActualMachine::SetFrameRate(double rate)
{
	mFrameRate = rate;
}