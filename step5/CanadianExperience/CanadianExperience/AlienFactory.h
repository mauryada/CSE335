/**
* \file AlienFactory.h
*
* \author Jaiwant Bhushan
*/

#pragma once
#include "ActorFactory.h"


/**
* Factory class that builds the Alien character
*/
class CAlienFactory :
	public CActorFactory
{
public:
	CAlienFactory();
	virtual ~CAlienFactory();
	std::shared_ptr<CActor> Create();
};

