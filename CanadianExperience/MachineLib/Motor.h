/**
 * \file Motor.h
 *
 * \author Daewoo Maurya
 *
 * 
 */

#pragma once
#include "Component.h"
#include "RotationSource.h"

/**
 * This class represents the motor component of the machine
 */
class CMotor :
	public CComponent
{
public:
	CMotor(int radius);
	virtual ~CMotor();

	void Draw(Gdiplus::Graphics* graphics, int x, int y) override;

	void SetMotorTime(double time);

	/// Get a pointer to the source object
	/// \return Pointer to CRotationSource object
	CRotationSource *GetSource() { return &mSource; }

	virtual void SetMotorRotation();

	int GetRadius() { return mRadius; }

private:
	CPolygon mMotorPoly;
	double mAxelRotation = 0;
	double mSpeed = 1;

	int mRadius = 1;

	/// Rotation source for this component
	CRotationSource mSource;

	int mSize = 80;
};

