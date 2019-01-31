#include "stdafx.h"
#include "RotationSource.h"


CRotationSource::CRotationSource()
{
}


CRotationSource::~CRotationSource()
{
}


void CRotationSource::MoveComponent(double rotation)
{
	for (auto sink : mSink)
	{
		sink->MoveComponent(rotation);
	}
}