#include "stdafx.h"
#include "Pulley.h"


CPulley::CPulley(double radius)// : mSink(this)
{
	mSink.SetComponent(this);
	mRadius = radius;
	//CenteredSquare(mRadius * 2);

	Circle(mRadius);
}



CPulley::~CPulley()
{
}

void CPulley::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	Gdiplus::Pen beltPen(Gdiplus::Color::Black, 2);

	auto saveSM = graphics->GetSmoothingMode();
	graphics->SetSmoothingMode(Gdiplus::SmoothingMode::SmoothingModeHighQuality);

	// Code to draw the belt
	if (mDrivenPulley)
	{
		

		int x1 = this->GetPosition().X;
		int y1 = this->GetPosition().Y;

		int x2 = mDrivenPulley->GetPosition().X;
		int y2 = mDrivenPulley->GetPosition().Y;

		auto r1 = mRadius - 3;
		auto r2 = mDrivenPulley->GetRadius() - 3;

		double theta = atan2((y2 - y1) , (x2 - x1));
		double magPulleyDistance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		double phi = asin((r2 - r1) / magPulleyDistance);

		double betaTop = theta + phi + M_PI / 2;
		double betaBottom = theta - phi - M_PI / 2;

		double top_p1_x1 = x + x1 + r1*cos(betaTop);
		double top_p2_x2 = x + x2 + r2*cos(betaTop);

		double top_p1_y1 = y + y1 + r1*sin(betaTop);
		double top_p2_y2 = y + y2 + r2*sin(betaTop);


		double bottom_p1_x1 = x + x1 + r1 * cos(betaBottom);
		double bottom_p2_x2 = x + x2 + r2 * cos(betaBottom);

		double bottom_p1_y1 = y + y1 + r1 * sin(betaBottom);
		double bottom_p2_y2 = y + y2 + r2 * sin(betaBottom);

		
		graphics->DrawLine(&beltPen, Gdiplus::Point(top_p1_x1,top_p1_y1),Gdiplus::Point(top_p2_x2,top_p2_y2));

		graphics->DrawLine(&beltPen, Gdiplus::Point(bottom_p1_x1, bottom_p1_y1), Gdiplus::Point(bottom_p2_x2, bottom_p2_y2));

	}

	graphics->SetSmoothingMode(saveSM);

	
	CComponent::Draw(graphics, x, y);
	
	
	
}

void CPulley::SetRotation(double rotation)
{
	CComponent::SetRotation(rotation);
	mSource.MoveComponent(rotation);
}

void CPulley::Drive(std::shared_ptr<CPulley> pulley)
{
	auto sink = pulley->GetSink();

	mSource.AddSink(sink);
	

	if (!(pulley->GetPosition().X == GetPosition().X && pulley->GetPosition().Y == GetPosition().Y))
	{
		sink->SetSpeed(mRadius / pulley->mRadius);
	}

	mDrivingPulley = this;

	mDrivenPulley = pulley;

}
