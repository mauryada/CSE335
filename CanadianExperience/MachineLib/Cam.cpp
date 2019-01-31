#include "stdafx.h"
#include "Cam.h"

const int SubSteps = 3;
using namespace Gdiplus;

CCam::CCam(int radius, int steps) 
{
	mRadius = radius;
	mSteps = steps;
	mSink.SetComponent(this);
	mPinSize = 6;
}


CCam::~CCam()
{
}


/**
 * Build the cam after all of the pins have been set.
 */
void CCam::Build()
{
	for (int i = 0; i < mSteps * SubSteps; i++)
	{
		double angle = 2 * M_PI * i / double(mSteps * SubSteps);
		double radius = mRadius;

		for (auto pin : mPins)
		{
			if (pin * SubSteps == i || pin * SubSteps == (i - 1))
			{
				radius = mRadius + mPinSize;
				break;
			}
		}

		AddPoint(radius * cos(angle), radius * -sin(angle));
	}
}

void CCam::AddPin(int pin)
{
	mPins.push_back(pin);
}

void CCam::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	CComponent::Draw(graphics, x, y);

	PointF intersection;
	if (Intersection(0.25, intersection))
	{
		float fx = intersection.X + GetPosition().X + x;
		float fy = intersection.Y + GetPosition().Y + y;

		Gdiplus::Pen pen(Gdiplus::Color::Red);

		graphics->DrawLine(&pen, PointF(fx, fy - 20), PointF(fx, fy + 20));
		graphics->DrawLine(&pen, PointF(fx - 20, fy), PointF(fx + 20, fy));
	}

}

void CCam::AddRoller(std::shared_ptr<CRoller> roller) 
{ 
	mRollerSink.push_back(roller); 
	roller->AddRollingSource(this);

}