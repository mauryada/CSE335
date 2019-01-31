/**
* \file PictureObserver.h
*
* \author Jaiwant Bhushan
*
* The implementation of picture observer
*/

#include "stdafx.h"
#include "PictureObserver.h"
#include "Picture.h"

CPictureObserver::CPictureObserver()
{
}


CPictureObserver::~CPictureObserver()
{
}


/** Set the picture for this observer
* \param picture The picture to set */
void CPictureObserver::SetPicture(std::shared_ptr<CPicture> picture)
{
	mPicture = picture;
	mPicture->AddObserver(this);
}