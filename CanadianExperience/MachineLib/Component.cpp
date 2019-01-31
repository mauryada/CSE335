#include "stdafx.h"
#include "Component.h"


CComponent::CComponent()
{
}


CComponent::~CComponent()
{
}


void CComponent::Draw(Gdiplus::Graphics *graphics, int x, int y)
{
	DrawPolygon(graphics, x + mPosition.X, y + mPosition.Y);
}


