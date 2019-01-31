/**
 * \file Roller.h
 *
 * \author Daewoo Maurya
 *
 * 
 */

#pragma once
#include "Component.h"

class CCam;
class CShape;

/**
 * 
 */
class CRoller :
	public CComponent
{
public:
	CRoller(double radius, double angle);
	virtual ~CRoller();

	void Draw(Gdiplus::Graphics* graphics, int x, int y);

	void AddRollingSource(CCam *rollingSource);

	CCam* GetRollingSource() { return mRollingSource; }

	void AddPositionSink(std::shared_ptr<CShape> shape);


private:
	double mRadius;
	double mRotation;

	CCam* mRollingSource = nullptr;

	std::shared_ptr<CShape> mPositionSink;

};

