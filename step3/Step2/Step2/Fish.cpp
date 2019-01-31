#include "stdafx.h"
#include "Fish.h"
#include "Aquarium.h"


/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;
const double MaxSpeedY = 50;

CFish::~CFish()
{
}

/**
* Constructor
* \param aquarium The aquarium we are in
* \param filename Filename for the image we use
*/
CFish::CFish(CAquarium *aquarium, const std::wstring &filename) :
	CItem(aquarium, filename)
{
	
	mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
	mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedY;
}


std::shared_ptr<xmlnode::CXmlNode>
CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"speedX", mSpeedX);
	itemNode->SetAttribute(L"speedY", mSpeedY);
	return itemNode;
}



/**
* Handle updates in time of our fish
*
* This is called before we draw and allows us to
* move our fish. We add our speed times the amount
* of time that has elapsed.
* \param elapsed Time elapsed since the class call
*/
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	double tempWidthRight = GetAquarium()->GetWidth() - 10 - (this->GetItemWidth() / 2);
	double tempWidthLeft = 10 + this->GetItemWidth()/2;
	double tempHeightBottom = GetAquarium()->GetHeight() - 10 - (this->GetItemHeight() / 2);
	double tempHeightUp = 10 + this->GetItemHeight() / 2;

	if (mSpeedX > 0 && GetX() >= tempWidthRight)
	{
		mSpeedX = -mSpeedX;
		SetMirrorHorizontal(mSpeedX < 0);
	}
	if (mSpeedX < 0 && GetX() <= tempWidthLeft)
	{
		mSpeedX = -mSpeedX;
		SetMirrorHorizontal(mSpeedX < 0);
	}
	if (mSpeedY > 0 && GetY() >= tempHeightBottom)
	{
		mSpeedY = -mSpeedY;
		SetMirrorVertical(mSpeedY < 0);
	}
	if (mSpeedY < 0 && GetY() <= tempHeightUp)
	{
		mSpeedY = -mSpeedY;
		SetMirrorVertical(mSpeedY < 0);
	}

}
