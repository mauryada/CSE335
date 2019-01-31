/**
* \file Bulbasaur.cpp
*
* \author Jaiwant Bhushan
*
* Class that describes a Bulbasaur.
*
* This class describes the various features of the bulbasaur.
*/



#pragma once

#include "stdafx.h"
#include <iostream>
#include "Bulbasaur.h"
#include "Animal.h"

using namespace std;

CBulbasaur::CBulbasaur()
{
}


CBulbasaur::~CBulbasaur()
{
}

void CBulbasaur::ObtainBulbasaurInformation()
{
	int SkillType;
	cout << endl;
	cout << "Input information about the Bulbasaur" << endl;

	// Obtain the name. This is easy, since it's just a
	// string.
	cout << "Name: ";
	cin >> mName;

	cout << "Weight in kg: ";
	cin >> mWeight;

	cout << "Number of candy eaten: ";
	cin >> mCandyNumber;

	cout << "Skill type: 1 for Tackle or 2 for Seed Bomb: ";
	cin >> SkillType;

	if (SkillType) 
	{
		if (SkillType == 1)
		{
			mSkill = "Tackle";
		}
		else if (SkillType == 2)
		{
			mSkill = "Seed Bomb";
		}
		else
		{
			cout << "Invalid Skill type.";
		}
	}
	else 
	{
		cout << "Please enter a valid choice";
	}
}

void CBulbasaur::DisplayAnimal() 
{
	cout << mName << ": ";
	cout << " Weight: " <<mWeight << " kg(s), ";
	cout << "Number of Candy eaten: "<< mCandyNumber << " , ";
	cout << " Skill Type: " << mSkill << "." << endl;

}

int CBulbasaur::NumLegs()
{
	int numoflegs = 4;
	return numoflegs;
}