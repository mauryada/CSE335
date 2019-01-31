/**
 * \file RotationSink.h
 *
 * \author Daewoo Maurya
 *
 * 
 */

#pragma once

//#include "Component.h"
//#include "Shape.h"

class CComponent;


class CRotationSink
{
public:
	CRotationSink();
	virtual ~CRotationSink();

	
	
	void SetComponent(CComponent* component) { mComponent = component; }

	void MoveComponent(double rotation);

	void CRotationSink::SetRotation(double rotation);

	void SetSpeed(double speed) { mSpeed = speed; }



private:
	CComponent *mComponent = nullptr;
	double mSpeed = 1;
	//CShape *mShape = nullptr;
};

