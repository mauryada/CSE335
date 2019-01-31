/**
* \file Bulbasaur.h
*
* \author Jaiwant Bhushan
*
* Class that describes a Bulbasaur.
*
* This class describes the various features of the bulbasaur.
*/


#pragma once
#include <string>
#include "Animal.h"

///Bulbasaur class inherited from CAnimal class.
class CBulbasaur : public CAnimal
{
public:
	CBulbasaur();
	virtual ~CBulbasaur();

	///The function to obtain information about the Bulbasaur.
	void ObtainBulbasaurInformation();
	
	///The function to display information about the bulbasaur which uses the DisplayAnimal function.
	void CBulbasaur::DisplayAnimal();
	
	///The function which returns the number of legs for bulbasaur.
	int NumLegs();

private:
	std::string mName; ///The name of the Bulbasaur.
	double mWeight;  ///Weight of the Bulbasaur.
	int mCandyNumber; ///Number of candy eaten.
	std::string mSkill; ///Skill Type.
};

