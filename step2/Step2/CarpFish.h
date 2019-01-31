/**
* \file CarpFish.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Carp fish
*/

#pragma once
#include <memory>
#include "Item.h"

/**
* Implements a Beta fish
*/
class CCarpFish : public CItem
{
public:
	///Test to see if the mouse click is on the hit.
	bool HitTest(int x, int y);
	
	///This draws everything on screen
	void CCarpFish::Draw(Gdiplus::Graphics *graphics);

	///A virtual function that returns weather an item is a predator or not
	virtual bool IsItPredator();

	///Default constructor
	CCarpFish(CAquarium *aquarium);

	/// Default constructor (disabled)
	CCarpFish() = delete;

	/// Copy constructor (disabled)
	CCarpFish(const CCarpFish &) = delete;

	///Destructor
	virtual  ~CCarpFish();

private:
	///This is the variable that stores the path of the image being used 
	std::unique_ptr<Gdiplus::Bitmap> mFishImage; 
};