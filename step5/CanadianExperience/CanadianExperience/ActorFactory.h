/**
* \file ActorFactory.h
*
* \author Jaiwant Bhushan
*/


#pragma once
#include "Actor.h"

/**
* Abstract base class for actor factories.
*/
class CActorFactory
{
public:
	CActorFactory();
	virtual ~CActorFactory();
	//std::shared_ptr<CActor> Create();
};

