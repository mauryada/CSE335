
/**
* \file PictureFactory.h
*
* \author Jaiwant Bhushan
*
*/

#pragma once
#include "Picture.h"
#include <memory>
/**
* A factory class that builds our picture.
*/

class CPictureFactory
{
public:
	CPictureFactory();
	virtual ~CPictureFactory();
	std::shared_ptr<CPicture> Create();
};

