/**
* \file Item.h
*
* \author Jaiwant Bhushan
*
* Base class for any item in our aquarium.
*/

#pragma once
#include <memory>
#include <string>
#include "XmlNode.h"

using namespace std;

class CAquarium;

/**
* Base class for any item in our aquarium.
*/
class CItem
{
public:
    /// Default constructor (disabled)
    CItem() = delete;

    /// Copy constructor (disabled)
    CItem(const CItem &) = delete;

	virtual ~CItem();

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

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

	/// Draw this item
	/// \param graphics Graphics device to draw on
	void Draw(Gdiplus::Graphics *graphics);

	///This is to save the file
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);
	///This is to load the file
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);


	/** Test this item to see if it has been clicked on
	* \param x X location on the aquarium to test
	* \param y Y location on the aquarium to test
	* \return true if clicked on */
	bool HitTest(int x, int y);

	/**
	 * Is this item a killer? 
	 * \returns Boolean. The default is false 
	 */
	virtual bool IsKiller() { return false; }
	
	///This tells what type of fish it is.
	virtual string whatType() { return "none"; }

	/// Get the aquarium this item is in
	/// \returns Aquarium pointer
	CAquarium *GetAquarium() { return mAquarium; }

	/// Set the mirror status
	/// \param m New mirror flag
	void SetMirrorHorizontal(bool m) { mMirrorHorizontal = m; }		///This is to set the Horizontal orientation
	void SetMirrorVertical(bool m) { mMirrorVertical = m; }			///This is to set the Vertical orientation
	double GetItemWidth() { return mItemImage->GetWidth(); }		///This is gets the width of the image.
	double GetItemHeight() { return mItemImage->GetHeight(); }		///This is gets the height of the image.

protected:
	///This is the constructor.
	CItem(CAquarium * aquarium, const std::wstring & filename);

private:
    /// The aquarium this item is contained in
    CAquarium   *mAquarium;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

	/// The image of this fish
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	bool mMirrorHorizontal = false;		///< True mirrors the item image
	bool mMirrorVertical = false;		///<True mirros the item image.
};

