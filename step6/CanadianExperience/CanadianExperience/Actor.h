/**
* \file Actor.h
*
* \author Jaiwant Bhushan
*
*/

#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Drawable.h"


using namespace Gdiplus;

class CPicture;

/**
* Class for actors in our drawings.
*
* An actor is some graphical object that consists of
* one or more parts. Actors can be animated.
*/
class CActor
{
public:

	/** Default constructor disabled */
	CActor() = delete;
	/** Copy constructor disabled */
	CActor(const CActor &) = delete;
	/** Assignment operator disabled */
	void operator=(const CActor &) = delete;

	CActor(const std::wstring &name);
	virtual ~CActor();

	void SetRoot(std::shared_ptr<CDrawable> root);
	std::shared_ptr<CDrawable> HitTest(Point pos);
	void AddDrawable(std::shared_ptr<CDrawable> drawable);
	void Draw(Gdiplus::Graphics *graphics);

	/** Get the actor name
	* \returns Actor name */
	std::wstring GetName() const { return mName; }

	/** The actor position
	* \returns The actor position as a point */
	Gdiplus::Point GetPosition() const { return mPosition; }

	/** The actor position
	* \param pos The new actor position */
	void SetPosition(Gdiplus::Point pos) { mPosition = pos; }


	/** Actor is enabled
	* \returns enabled status */
	bool IsEnabled() const { return mEnabled; }

	/** Set Actor Enabled
	* \param enabled New enabled status */
	void SetEnabled(bool enabled) { mEnabled = enabled; }

	/** Actor is clickable
	* \returns true if actor is clickable */
	bool IsClickable() const { return mClickable; }

	/** Actor clickable
	* \param clickable New clickable status */
	void SetClickable(bool clickable) { mClickable = clickable; }
	///This is to set the picture
	void SetPicture(CPicture *pic) { mPicture = pic; }
	///This is to get the picture
	CPicture* GetPicture() { return mPicture; }
	 
private:
	///THis is the name of the actor
	std::wstring mName;
	///THis is to check weather the enabled 
	bool mEnabled = true;
	///This is the position in point
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	///Weather this is clickable or not
	bool mClickable = true;
	/// The root drawable
	std::shared_ptr<CDrawable> mRoot;
	/// The drawables in drawing order
	std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;
	///Picture pointer
	CPicture *mPicture = nullptr;

};

