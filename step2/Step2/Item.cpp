/**
* \file Item.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include "Item.h"
#include "Aquarium.h"


/** Constructor
* \param aquarium The aquarium this item is a member of
*/
CItem::CItem(CAquarium *aquarium) : mAquarium(aquarium)
{
}

///Returns false by default
bool CItem::IsItPredator()
{
	return false;
}

/**
* Destructor
*/
CItem::~CItem()
{
}
