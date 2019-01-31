/**
* \file Fish2.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Beta fish
*/

#pragma once
#include <memory>
#include "Item.h"

/**
* Implements a Beta fish
*/
class CFish2 : public CItem
{
public:
	bool HitTest(int x, int y);
	void CFish2::Draw(Gdiplus::Graphics *graphics);

	CFish2(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFish2() = delete;

	/// Copy constructor (disabled)
	CFish2(const CFish2 &) = delete;

	///Destructor
	virtual  ~CFish2(); 
private:
	///This is the variable that stores the path to the image
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};