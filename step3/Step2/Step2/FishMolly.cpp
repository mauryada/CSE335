/**
* \file FishMolly.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include <string>
#include "FishMolly.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishMollyImageName(L"images/molly.png");




/** Constructor
* \param aquarium The aquarium this is a member of
*/
CFishMolly::CFishMolly(CAquarium *aquarium) :
	CFish(aquarium, FishMollyImageName)
{
	setSpeedX(((double)rand() / RAND_MAX) * 100);
	setSpeedY(((double)rand() / RAND_MAX) * 100);
}

/**
* Destructor
*/
CFishMolly::~CFishMolly()
{
}


/**
* Save this item to an XML node
* \param node The node we are going to be a child of
* \return node which gets saved to the xml file
*/
std::shared_ptr<xmlnode::CXmlNode>
CFishMolly::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"molly");
	return itemNode;
}

