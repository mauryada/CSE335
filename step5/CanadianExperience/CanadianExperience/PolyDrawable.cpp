/**
* \file PolyDrawable.cpp
*
* \author Jaiwant Bhushan
* Implementation of PolyDrawable class
*/

#include "stdafx.h"
#include "PolyDrawable.h"

using namespace Gdiplus;


/** Constructor
* \param name The drawable name */
CPolyDrawable::CPolyDrawable(const std::wstring &name) : CDrawable(name)
{
}

CPolyDrawable::~CPolyDrawable()
{
}

/** Test to see if we hit this object with a mouse click
* \param pos Click position
* \returns true it hit
*/
bool CPolyDrawable::HitTest(Gdiplus::Point pos)
{
	// Transform the points
	vector<Point> points;
	for (auto point : mPoints)
	{
		points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
	}

	GraphicsPath path;
	path.AddPolygon(&points[0], (int)points.size());
	return path.IsVisible(pos) ? true : false;
}

void CPolyDrawable::AddPoint(Gdiplus::Point point)
{
	mPoints.push_back(point);
}
/** Draw our polygon.
* \param  graphics The graphics context to draw on
*/
void CPolyDrawable::Draw(Gdiplus::Graphics *graphics)
{
	SolidBrush brush(mColor);

	// Transform the points
	vector<Point> points;
	for (auto point : mPoints)
	{
		points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
	}

	graphics->FillPolygon(&brush, &points[0], (int)points.size());
}
