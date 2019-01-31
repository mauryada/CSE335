/**
* \file PolyDrawable.h
*
* \author Jaiwant Bhushan
*
*/

#pragma once
#include "Drawable.h"
#include <vector>

/**
* A drawable based on polygon images.
*
* This class has a list of points and draws a polygon
* drawable based on those points.
*/
class CPolyDrawable :
	public CDrawable
{
public:
	CPolyDrawable(const std::wstring & name);
	virtual ~CPolyDrawable();

	bool HitTest(Gdiplus::Point pos);
	void Draw(Gdiplus::Graphics *graphics);
	///This adds a point
	void AddPoint(Gdiplus::Point point);

	/** Default constructor disabled */
	CPolyDrawable() = delete;
	/** Copy constructor disabled */
	CPolyDrawable(const CPolyDrawable &) = delete;
	/** Assignment operator disabled */
	void operator=(const CPolyDrawable &) = delete;

	/** Set the rotation angle in radians
	* \param r The new rotation angle in radians*/
	void SetColor(Gdiplus::Color r) { mColor = r; }

	/** Get the rotation angle in radians
	* \returns The rotation angle in radians*/
	Gdiplus::Color GetColor() const { return mColor; }



private:
	/// The polygon color
	Gdiplus::Color mColor = Gdiplus::Color::Black;
	/// The array of point objects
	std::vector<Gdiplus::Point> mPoints;

};

