/**
 * \file Shape.h
 *
 * \author Daewoo Maurya
 *
 * 
 */

#pragma once
#include "Component.h"
#include "RotationSink.h"

class CRoller;

/**
 * Abstract class that represents general shape of the components 
 */
class CShape :
	public CComponent
{
public:
	CShape();
	virtual ~CShape();
	CShape(const CShape &) = delete;
	void operator=(const CShape &) = delete;

	CRotationSink *GetSink() { return &mSink; }

	void SetRotation(double rotation) override;

	void AddPositionSource(CRoller *source);

private:
	CRotationSink mSink;
	CRoller* mPositionSource;
};

