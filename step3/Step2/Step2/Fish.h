/**
* \file Fish.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Fish
*/


#pragma once
#include "Item.h"

///Class that is derived from Item and makes other fishes.
class CFish :
	public CItem
{
public:
	/// Default constructor (disabled)
	CFish() = delete;

	/// Copy constructor (disabled)
	CFish(const CFish &) = delete;
	
	///Destructor
	virtual ~CFish();
	
	///Sets the speedX of the fish.
	void setSpeedX(double x) { mSpeedX = x; }
	///Sets the speedY of the fish.
	void setSpeedY(double y) { mSpeedY = y; }


private:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;

protected:
	///A constructor for the fish.
	CFish(CAquarium * aquarium, const std::wstring & filename);
	///This is for saving it to the xml document.
	std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);
	///This makes the animation work.
	void Update(double elapsed);
};

