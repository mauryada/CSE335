
/**
* \file Item.h
*
* \author Jaiwant Bhushan
*
* Class the defines an Item
*/


#pragma once

class CAquarium;


///This class is the item class which defines every other item such as fish to be defined
class CItem
{
protected:
	CItem(CAquarium *aquarium);

	

public:

	///Function to check weather the item is a predator or not
	virtual bool IsItPredator();

	/// Draw this item
	/// \param graphics Graphics device to draw on
	virtual void Draw(Gdiplus::Graphics *graphics) = 0;

	/** Test this item to see if it has been clicked on
	* \param x X location on the aquarium to test
	* \param y Y location on the aquarium to test
	* \return true if clicked on */
	virtual bool HitTest(int x, int y) = 0;

	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;


	~CItem();
	/** The X location of the item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	void SetLocation(double x, double y) { mX = x; mY = y; }

private:
	/// The aquarium this item is contained in
	CAquarium   *mAquarium;

	// Item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item
};

