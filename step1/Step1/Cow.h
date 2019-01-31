/**
* \file Cow.h
*
* \author Jaiwant Bhushan
*
* Class that describes a Cow.
*
* This class describes the various features of the cow.
*/
#pragma once
#include <string>
#include "Animal.h"

///CCow Class inherited from CAnimal class.
class CCow : public CAnimal
{
public:
	CCow();
	virtual ~CCow();

	/// The types of cow we can have on our farm
	enum Type { Bull, BeefCow, MilkCow };
	
	void ObtainCowInformation();
	void CCow::DisplayAnimal();
	int NumLegs();
private:
	/// The cow's name
	std::string mName; 

	/// The type of code: Bull, BeefCow, or MilkCow
	Type mType = MilkCow;

	/// The milk production for a cow in gallons per day
	double mMilkProduction = 0;
};

