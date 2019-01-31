#include "stdafx.h"
#include "HeadTop.h"

using namespace std;
using namespace Gdiplus;

CHeadTop::CHeadTop(const std::wstring &name, const std::wstring &filename) :
	CImageDrawable(name, filename)
{
}


CHeadTop::~CHeadTop()
{
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
	// Make p relative to the image center
	p = p - GetCenter();

	// Rotate as needed and offset
	return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/// \param graphics Graphics
void CHeadTop::Draw(Gdiplus::Graphics * graphics)
{
	/// Constant ratio to convert radians to degrees
	const double RtoD = 57.295779513;
	
	CImageDrawable::Draw(graphics);

	Point p = TransformPoint(Point(70, 66));
	Point pEnd = TransformPoint(Point(90, 68));
	Pen pen(Color::Black, 2);
	graphics->DrawLine(&pen, p, pEnd);

	Point p2 = TransformPoint(Point(20, 66));
	Point p2End = TransformPoint(Point(40, 63));
	Pen pen2(Color::Black, 2);
	graphics->DrawLine(&pen2, p2, p2End);

	float wid = 15.0f;
	float hit = 20.0f;

	SolidBrush brush(Color(0, 0, 0));

	auto state = graphics->Save();
	graphics->TranslateTransform((Gdiplus::REAL)(p2.X+10),(Gdiplus::REAL)(p2.Y+10));
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);

	auto state2 = graphics->Save();
	graphics->TranslateTransform((Gdiplus::REAL)(p.X + 10), (Gdiplus::REAL)(p.Y + 10));
	graphics->RotateTransform((float)(-mPlacedR * RtoD));
	graphics->FillEllipse(&brush, -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state2);
	

}

