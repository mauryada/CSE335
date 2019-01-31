/**
 * \file ActualMachine.h
 *
 * \author Daewoo Maurya
 *
 * 
 */

#pragma once
#include "Machine.h"

class CWorkingMachine;

/**
 * Actual machine calss to override machine functionality
 */
class CActualMachine :
	public CMachine
{
public:

	/// Constructor
	CActualMachine();

	/// desctructor
	virtual ~CActualMachine();

	///Copy constructor disabled
	CActualMachine(const CActualMachine &) = delete;

	/// Assignment operator/disabled
	void operator=(const CActualMachine &) = delete;

	/**
	* Draw the machine
	* \param graphics Graphics object
	*/
	virtual void DrawMachine(Gdiplus::Graphics * graphics) override;

	/**
	* Set the current frame
	* \param frame Frame number
	*/
	virtual void SetMachineFrame(int frame) override;

	/**
	* Set the speed
	* \param speed Speed fraction from 0 to 1
	*/
	virtual void SetSpeed(double speed) override { mSpeed = speed; }



	/**
	* Set the machine number
	* \param machine The machine name kinda
	*/
	virtual int GetMachineNumber() override;

	/**
	* Set the machine number
	* \param machine The number name of the machine
	*/

	virtual void SetMachineNumber(int machine) override;

	/**
	* Set the position for the machine
	* \param x X location
	* \param y Y location
	*/
	virtual void SetLocation(int x, int y) override;

	/**
	* Set the expected frame rate
	* \param rate Frame rate in frames per second
	*/
	virtual void SetFrameRate(double rate) override;

private:

	/// frame rate of the machine
	double mFrameRate;

	/// speed of the machine
	double mSpeed;

	/// time elapsed
	double mTime;

	/// Position of the machine
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

	///Machine numer kinda like name
	int mMachineNumber;

	std::shared_ptr<CWorkingMachine> mWorkingMachine;
};

