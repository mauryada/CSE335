#include "stdafx.h"
#include "MachineDrawable.h"
#include "MachineFactory.h"
#include "Timeline.h"



CMachineDrawable::~CMachineDrawable()
{
}


CMachineDrawable::CMachineDrawable(const std::wstring &name, int machineNum) : CDrawable(name)
{
	CMachineFactory factory;
	mMachine = factory.CreateMachine();
	mMachine->SetMachineNumber(machineNum);
	mMachine->SetMachineFrame(0);
	mMachine->SetFrameRate(30);
	mMachine->SetSpeed(1);

}

void CMachineDrawable::Draw(Gdiplus::Graphics *graphics)
{
	float scale = 0.8f;
	auto save = graphics->Save();
	graphics->TranslateTransform((float)mPlacedPosition.X, (float)mPlacedPosition.Y);
	graphics->ScaleTransform(scale, scale);
	mMachine->SetMachineFrame(mMachineAnimChannelPoint.GetTimeline()->GetCurrentFrame());
	mMachine->DrawMachine(graphics);

	graphics->Restore(save);
}


void CMachineDrawable::SetTimeline(CTimeline *timeline)
{
	CDrawable::SetTimeline(timeline);
	timeline->AddChannel(&mMachineAnimChannelPoint);
}


void CMachineDrawable::SetPosition(Gdiplus::Point position)
{
	mMachine->SetLocation(position.X, position.Y);

}

