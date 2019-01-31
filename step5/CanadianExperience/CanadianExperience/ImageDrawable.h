#pragma once
#include "Drawable.h"
#include <memory>


/**
* This is all the drawable images
*/
class CImageDrawable :
	public CDrawable
{
public:
	///Constructor
	CImageDrawable(const std::wstring & name, const std::wstring & filename);
	virtual ~CImageDrawable();
	///This is the draw
	void Draw(Gdiplus::Graphics * graphics);
	///This is the hittest
	bool HitTest(Gdiplus::Point pos);
	///This is the get center
	Gdiplus::Point GetCenter() { return mCenter; }
	///This sets the center
	void SetCenter(Gdiplus::Point point) { mCenter = point; }
protected:
	/// The image for this drawable
	std::unique_ptr<Gdiplus::Bitmap> mImage;
private:
	///This is the center variable
	Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
};

