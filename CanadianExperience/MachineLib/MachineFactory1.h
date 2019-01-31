/**
 * \file MachineFactory1.h
 *
 * \author Daewoo Maurya
 *
 * 
 */

#pragma once

#include <memory>
#include "WorkingMachine.h"

/**
 * Machine Factory 1
 */
class CMachineFactory1
{
public:
	CMachineFactory1();
	virtual ~CMachineFactory1();

	std::shared_ptr<CWorkingMachine> CreateMachine();
};

