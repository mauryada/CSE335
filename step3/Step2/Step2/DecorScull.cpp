/**
* \file FishBeta.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include <string>
#include "DecorScull.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring DecorScullImageName(L"images/scull.png");

/**
* Constructor
* \param aquarium Aquarium this fish is a member of

CFishBeta::CFishBeta(CAquarium *aquarium) : CItem(aquarium)
{
mFishImage = unique_ptr<Bitmap>(Bitmap::FromFile(FishBetaImageName.c_str()));
if (mFishImage->GetLastStatus() != Ok)
{
wstring msg(L"Failed to open ");
msg += FishBetaImageName;
AfxMessageBox(msg.c_str());
}
}
*/

/** Constructor
* \param aquarium The aquarium this is a member of
*/
CDecorScull::CDecorScull(CAquarium *aquarium) :
	CItem(aquarium, DecorScullImageName)
{
}


/**
* Destructor
*/
CDecorScull::~CDecorScull()
{
}

/**
* Save this item to an XML node
* \param node The node we are going to be a child of
* \return type is a node that gets saved
*/
std::shared_ptr<xmlnode::CXmlNode>
CDecorScull::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"scull");
	return itemNode;
}


