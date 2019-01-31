#include "stdafx.h"
#include "Motor.h"


CMotor::CMotor(int radius)
{
	Circle(radius);
	this->SetImage(L"images/shaft.png");
	mMotorPoly.SetImage(L"images/motor2.png");
	//mMotorPoly.SetImage(L"images/shaft.png");
	//mMotorPoly.SetImage(L"images/motor2.png");
	mMotorPoly.CenteredSquare(mSize);
}
	
	


CMotor::~CMotor()
{
}


void CMotor::Draw(Gdiplus::Graphics* graphics, int x, int y)
{
	
	mMotorPoly.DrawPolygon(graphics, x + GetPosition().X, y + GetPosition().Y); //DrawPolygon(graphics, x + mPosition.X, y + mPosition.Y);
	//mMotorPoly.SetImage(L"images/motor2.png"); //maybe
	CComponent::Draw(graphics, x, y);
}

void CMotor::SetMotorTime(double time)
{
	mAxelRotation = time*mSpeed;
}

void CMotor::SetMotorRotation()
{
	CComponent::SetRotation(mAxelRotation);
	this->SetRotation(mAxelRotation);
	mSource.MoveComponent(mAxelRotation);
}
