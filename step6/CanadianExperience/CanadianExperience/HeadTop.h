#pragma once
#include "ImageDrawable.h"


/**
* This is the head top
*/
class CHeadTop :
	public CImageDrawable
{
public:
	///This is the constructor
	CHeadTop(const std::wstring & name, const std::wstring & filename);
	virtual ~CHeadTop();
	///THis is the transform point function
	Gdiplus::Point TransformPoint(Gdiplus::Point p);
	///This is to draw
	void Draw(Gdiplus::Graphics * graphics);
	///THis is the override of movable
	virtual bool IsMovable() { return true; }
};

