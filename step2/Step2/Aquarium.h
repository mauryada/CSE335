/**
* \file Aquarium.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Aquarium
*/


#pragma once

#include<memory>
#include <vector>
#include "Item.h"


///This class is the aquarium class that holds all the items;
class CAquarium
{
public:
	CAquarium();
	void Add(std::shared_ptr<CItem> item);
	std::shared_ptr<CItem> HitTest(int x, int y);
	virtual ~CAquarium();
	
	/// This function moves the current item to the front of the list.
	void MoveToFront(std::shared_ptr<CItem> item);
	
	///This function deletes the fish from the list.
	virtual void KillTheFish(std::shared_ptr<CItem> item);

	///This basically draws using graphics
	void OnDraw(Gdiplus::Graphics * graphics);

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image  
	///mItems is the vector that holds all items of type CItem
	std::vector<std::shared_ptr<CItem> > mItems; /// All of the items to populate our aquarium
};


