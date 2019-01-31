/**
 * \file Component.h
 *
 * \author Daewoo Maurya
 *
 * 
 */

#pragma once
#include "Polygon.h"

class CWorkingMachine;

/**
 * This class represents the components of the machine
 */
class CComponent :
	public CPolygon
{
public:
	CComponent();
	virtual ~CComponent();

	virtual void Draw(Gdiplus::Graphics* graphics, int x, int y);

	void SetMachine(CWorkingMachine *machine) { mMachine = machine; }

	void SetPosition(Gdiplus::Point position) { mPosition = position; }

	Gdiplus::Point GetPosition() { return mPosition; }

private:
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	CWorkingMachine* mMachine = nullptr;


};

