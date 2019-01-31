#include "stdafx.h"
#include "Shape.h"
#include "Roller.h"


CShape::CShape()
{
	mSink.SetComponent(this);
}


CShape::~CShape()
{
}

void CShape::SetRotation(double rotation)
{
	CComponent::SetRotation(rotation);
}

void CShape::AddPositionSource(CRoller *source)
{
	mPositionSource = source;
}