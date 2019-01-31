/**
 * \file WorkingMachine.h
 *
 * \author Daewoo Maurya
 *
 * 
 */

#pragma once
#include "Component.h"
#include "Motor.h"

/**
 * The working machine class
 */
class CWorkingMachine
{
public:
	CWorkingMachine();
	virtual ~CWorkingMachine();
	
	/**
	* Sets the time for the machine
	* \param time The current time
	*/
	void SetMachineTime(double time);

	/**
	* Draws the Machine 
	* \param graphics The graphics object
	* \param x the X location
	* \param y the y location
	*/
	void DrawMachine(Gdiplus::Graphics* graphics, int x, int y);

	void AddComponent(std::shared_ptr<CComponent> component);

	void AddMotor(std::shared_ptr<CMotor> motor);

private:
	/// the frame we are working on
	int mFrame;

	std::vector<std::shared_ptr<CComponent>> mComponents;

	std::vector<std::shared_ptr<CMotor>> mMotors;
};

