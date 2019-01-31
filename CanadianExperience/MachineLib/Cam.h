/**
 * \file Cam.h
 *
 * \author Daewoo Maurya
 *
 * 
 */

#pragma once
#include "RotationSink.h"
#include "Component.h"
#include <vector>
#include "Roller.h"


/**
 * 
 */
class CCam :
	public CComponent
{
public:
	CCam() = delete;
	virtual ~CCam();

	void operator=(const CCam &) = delete;
	CCam(const CCam &) = delete;

	CCam(int radius, int steps);

	void Build();
	void AddPin(int pin);
	CRotationSink *GetSink() { return &mSink; }
	void Draw(Gdiplus::Graphics* graphics, int x, int y);

	void SetPinSize(double pinSize) { mPinSize = pinSize; }

	void AddRoller(std::shared_ptr<CRoller> roller);

	

private:
	std::vector<int> mPins;
	double mRadius;
	int mSteps;
	CRotationSink mSink;
	double mPinSize; //maybe

	std::vector<std::shared_ptr<CRoller>> mRollerSink;
};

