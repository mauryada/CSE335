/**
* \file FishBeta.h
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
class CFishBeta : public CItem
{
public:
	///The function that returns weather mouse click is on the spot
	bool HitTest(int x, int y);
	///This basically just draws it on the screen.
	void CFishBeta::Draw(Gdiplus::Graphics *graphics);

	///Default Constructor
	CFishBeta(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta &) = delete;

	///Destructor
	virtual  ~CFishBeta();

private:
	///This is the variable that stores the path to the image
	std::unique_ptr<Gdiplus::Bitmap> mFishImage;
};