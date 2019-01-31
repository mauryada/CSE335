/**
* \file FishNemo.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include <string>
#include "FishNemo.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishNemoImageName(L"images/nemo.png");




/** Constructor
* \param aquarium The aquarium this is a member of
*/
CFishNemo::CFishNemo(CAquarium *aquarium) :
	CFish(aquarium, FishNemoImageName)
{
	setSpeedX(((double)rand() / RAND_MAX) * 35);
	setSpeedY(((double)rand() / RAND_MAX) * 35);
}

/**
* Destructor
*/
CFishNemo::~CFishNemo()
{
}

/**
* Save this item to an XML node
* \param node The node we are going to be a child of
* \return node which gets saved to the xml file
*/
std::shared_ptr<xmlnode::CXmlNode>
CFishNemo::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"nemo");
	return itemNode;
}




