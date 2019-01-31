#include "stdafx.h"
#include "Roller.h"
#include "Cam.h"
#include "Shape.h"

using namespace Gdiplus;

CRoller::CRoller(double radius, double angle)
{
	mRadius = radius;
	mRotation = angle;
	Circle(radius);

}


CRoller::~CRoller()
{
}


void CRoller::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	
	Gdiplus::Point sourcePosition = mRollingSource->GetPosition();
	PointF intersection;



	if (mRollingSource->Intersection(0.25, intersection))
	{
		float fx = intersection.X + sourcePosition.X + x;
		float fy = intersection.Y + sourcePosition.Y + y;

		Gdiplus::Pen pen(Gdiplus::Color::Red);

		CComponent::Draw(graphics, fx, fy);

		mPositionSink->SetPosition(Gdiplus::Point(fx+100, fy+100)); //maybe
	}
	

}

void CRoller::AddRollingSource(CCam *rollingSource)
{
	mRollingSource = rollingSource;

}


void CRoller::AddPositionSink(std::shared_ptr<CShape> shape)
{
	mPositionSink = shape;
	shape->AddPositionSource(this);

}