/**
* \file Aquarium.cpp
*
* \author Jaiwant Bhushan
*
* Class the implements a Aquarium
*/


#pragma once
#include "stdafx.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "ChildView.h"
#include "Item.h"
#include <algorithm>

using namespace std;
using namespace Gdiplus;


CAquarium::CAquarium()
{
	mBackground = unique_ptr<Gdiplus::Bitmap>(Bitmap::FromFile(L"images/background1.png"));
	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/background1.png");
	}


}

/**
* Add an item to the aquarium
* \param item New item to add
*/
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}


CAquarium::~CAquarium()
{
}


/**
* Called when there is a left mouse button press
* \param nFlags Flags associated with the mouse button press
* \param point Where the button was pressed
*/

///This is when the mouse is pressed down, it pushes the current element to the front of the vector
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	mGrabbedItem = mAquarium.HitTest(point.x, point.y);

	if (mGrabbedItem != nullptr)
	{
		mAquarium.MoveToFront(mGrabbedItem);
	}
}

///This finds the item and adds it to the front.
void CAquarium::MoveToFront(std::shared_ptr<CItem> item) 
{
	auto loc = find(begin(mItems), end(mItems), item);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
	CAquarium::Add(item);
}

///This function checks weather the current fish is on top of the predator fish and then deletes it.
void CAquarium::KillTheFish(std::shared_ptr<CItem> item2)
{
	for (auto item1 : mItems)
	{
		if (item1->IsItPredator() && item1 != item2) 
		{
			if ((item1->GetX() == item2->GetX()) && (item1->GetY() == item2->GetY()))
			{
				auto loc = find(begin(mItems), end(mItems), item2);
				if (loc != end(mItems))
				{
					mItems.erase(loc);
					break;
				}
			}
			
		}
	}
}

