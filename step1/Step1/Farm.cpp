/**
* \file Farm.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include "Farm.h"


/**
* Constructor.
*/
CFarm::CFarm()
{
}

/** Add an animal to the farm inventory.
*
* \param cow A cow to add to the inventory
*/
void CFarm::AddAnimal(CAnimal *animal)
{
	mInventory.push_back(animal);
}




/**
* Display the farm inventory.
*/
void CFarm::DisplayInventory()
{
	for (auto animal : mInventory)
	{
		animal->DisplayAnimal();
	}
}

/**
* Destructor.
*/
CFarm::~CFarm()
{
	// Iterate over all of the animals, destroying 
	// each one.
	for (auto animal : mInventory)
	{
		delete animal;
	}

	// And clear the list
	mInventory.clear();
}

int CFarm::NumOfLegs()
{
	int SumOfLegs = 0;
	for (auto animal : mInventory)
	{
		SumOfLegs += animal->NumLegs();
	}
	return SumOfLegs;
}