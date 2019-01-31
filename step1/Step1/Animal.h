/**
* \file Animal.h
*
* \author Jaiwant Bhushan
*
* Class that describes all animals
*
* This class is about the animals in the farm, other animals are going to be inherited from this class.
*/


#pragma once
///Animal Class
class CAnimal
{
public:
	CAnimal();
	virtual ~CAnimal();
	/** Display an animal. */
	virtual void DisplayAnimal() {}
	/** Number of Legs*/ ///Return type is an integer/
	virtual int NumLegs() 
	{
		///Return a default value of 0.
		return 0;
	}
};

