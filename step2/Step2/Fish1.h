/**
* \file Fish1.h
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
class CFish1 : public CItem
{
public:
	bool HitTest(int x, int y);
	void CFish1::Draw(Gdiplus::Graphics *graphics);

	CFish1(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFish1() = delete;

	/// Copy constructor (disabled)
	CFish1(const CFish1 &) = delete;

	///Destructor
	virtual  ~CFish1();
private:
	///This is the variable that stores the path to the image
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};