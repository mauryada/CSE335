/**
* \file Farm.h
*
* \author Jaiwant Bhushan
*
* Class that describes a Farm.
*
* This class holds a collection of animals that make
* up the inventory of a farm.
*/

#pragma once

#include <vector>
#include "Cow.h"


/**
* Class that describes a farm.
*
* Holds a collection of animals that make up the farm
* inventory.
*/

class CFarm
{
public:
	CFarm();
	virtual ~CFarm();
	
	void AddAnimal(CAnimal *animal);
	/**
	* Display the farm inventory.
	*/
	void DisplayInventory();
	int NumOfLegs();

private:
	/// A list with the inventory of all animals on the farm
	std::vector<CAnimal *> mInventory;
};

