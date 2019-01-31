/**
* \file PictureObserver.h
*
* \author Jaiwant Bhushan
*
* The picture observer
*/

#pragma once
#include <memory>

/**
* Observer base class for a picture.
*
* This class implements the base class functionality for
* an observer in the observer pattern.
*/

class CPicture;

/**
* This is the picture observer
*/
class CPictureObserver
{
public:
	virtual ~CPictureObserver();

	void SetPicture(std::shared_ptr<CPicture> picture);

	/// Copy Constructor (Disabled)
	CPictureObserver(const CPictureObserver &) = delete;
	/// Assignment Operator (Disabled)
	CPictureObserver &operator=(const CPictureObserver &) = delete;
	/// This function is called to update any observers
	virtual void UpdateObserver() = 0;
	///This is for getting the mPicture
	std::shared_ptr<CPicture> GetPicture() { return mPicture; }

private:
	/// Picture we are observing
	std::shared_ptr<CPicture> mPicture;

protected:
	CPictureObserver();
};

