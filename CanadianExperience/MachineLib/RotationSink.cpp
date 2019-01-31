#include "stdafx.h"
#include "RotationSink.h"
#include "Component.h"


CRotationSink::CRotationSink()
{
}


CRotationSink::~CRotationSink()
{
}

void CRotationSink::SetRotation(double rotation)
{
	mComponent->SetRotation(rotation*mSpeed);
}

void CRotationSink::MoveComponent(double rotation)
{ 
	mComponent->SetRotation(rotation*mSpeed); 
}