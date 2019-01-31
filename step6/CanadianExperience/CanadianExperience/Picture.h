/**
* \file Picture.h
*
* \author Jaiwant Bhushan
*
* The picture we are drawing
*/

#pragma once
#include <vector>
#include "Actor.h"
#include "Timeline.h"



class CPictureObserver;

/**
* The picture we are drawing.
*
* There will be one picture object that contains all of
* our actors, which then contains the drawables.
*/
class CPicture
{
public:
	CPicture();
	virtual ~CPicture();
	/// Copy Constructor (Disabled)
	CPicture(const CPicture &) = delete;
	/// Assignment Operator (Disabled)
	CPicture &operator=(const CPicture &) = delete;
	/** The picture size
	* \returns Size */
	Gdiplus::Size GetSize() { return mSize; }

	/** The picture size
	* \param size The new picture size */
	void SetSize(Gdiplus::Size size) { mSize = size; }

	///Adds the observer
	void AddObserver(CPictureObserver *observer);
	/** The picture size 
	* \param actor the new actor
	*/
	void AddActor(std::shared_ptr<CActor> picture);
	void RemoveObserver(CPictureObserver *observer);
	void UpdateObservers();
	/** The picture size
	* \param graphics The new picture size */
	void Draw(Gdiplus::Graphics *graphics);

	void SetAnimationTime(double time);


	/** Iterator that iterates over some collection */
	class Iter
	{
	public:
		///This is the constructor of the iter
		Iter(CPicture *pic, int pos) : mPic(pic), mPos(pos) {}

		///This is the not equal to operator
		bool operator!=(const Iter &other) const
		{
			return mPos != other.mPos;
		}

		/** Get value at current position
		* \returns Value at mPos in the collection */
		std::shared_ptr<CActor> operator *() const { return mPic->mActors[mPos]; }

		/** Increment the iterator
		* \returns Reference to this iterator */
		const Iter& operator++()
		{
			mPos++;
			return *this;
		}


	private:
		CPicture *mPic;   ///< Collection we are iterating over
		int mPos;       ///< Position in the collection
	};

	///This is the begin of iter
	Iter begin() { return Iter(this, 0); }
	///This is the end of iter
	Iter end() { return Iter(this, mActors.size()); }

	/** Get a pointer to the Timeline object
	* \returns Pointer to the Timeline object
	*/
	CTimeline *GetTimeline() { return &mTimeline; }


private:
	/// The picture size
	Gdiplus::Size mSize = Gdiplus::Size(800, 600);
	/// The observers of this picture
	std::vector<CPictureObserver *> mObservers;
	///This is teh actor list
	std::vector<std::shared_ptr<CActor>> mActors;
	/// The animation timeline
	CTimeline mTimeline;
};

