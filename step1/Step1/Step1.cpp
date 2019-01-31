/**
* \file Step1.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include <iostream>
#include "Farm.h"
#include "Cow.h"
#include "Chicken.h"
#include "Bulbasaur.h"

using namespace std;

/**
* Main entry point.
*
* This is where the program starts.
* \return 0
*/
int main()
{
	// Support memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	
	cout << "Instantiating Farm" << endl;
	CFarm farm;
	// This loops continuously until we are done
	bool done = false;
	while (!done)
	{
		// Output user instructions
		cout << endl;
		cout << "Farm management" << endl;
		cout << "1 - Add cow" << endl;
		cout << "2 - Add Chicken" << endl;
		cout << "3 - Add Bulbasaur" << endl;
		cout << "9 - List inventory" << endl;
		cout << "10 - Count Legs" << endl;
		cout << "99 - Exit" << endl;
		cout << "Select Option: ";

		// Get option from the user
		int option;
		cin >> option;

		// Handle invalid  input
		if (!cin)
		{
			option = 1000;
			cin.clear();
			cin.ignore();  // Discard bad input
		}

		// Handle the possible user options
		switch (option)
		{
		case 1:
		{
			cout << "Adding cow" << endl; //Adding the cow
			CCow *cow = new CCow();
			cow->ObtainCowInformation();
			farm.AddAnimal(cow);
		}
		break;
		
		case 2:
		{
			cout << "Adding chicken" << endl; //Adding the Chicken
			CChicken *chicken = new CChicken();
			chicken->ObtainChickenInformation();
			 farm.AddAnimal(chicken);
		}
		break;

		case 3:
		{
			cout << "Adding Bulbasaur" << endl; //Adding the Bulbasaur
			CBulbasaur *bulbasaur = new CBulbasaur();
			bulbasaur->ObtainBulbasaurInformation();
			farm.AddAnimal(bulbasaur);
		}
		break;
		
		case 9:
			farm.DisplayInventory(); //Displaying the current inventory.
			break;

		case 10:
		{
			cout << "Number of Legs: " << farm.NumOfLegs(); //Displays the total number of legs in the farm.
		}
		break;
		case 99:
			done = true;
			break;

		default:
			cout << "Invalid option" << endl;  //If the option is invalid.
			break;
		}
	}

	return 0; // End of Program.
}