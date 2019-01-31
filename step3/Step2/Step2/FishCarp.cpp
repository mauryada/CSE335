/**
* \file FishCarp.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include <string>
#include "FishCarp.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishCarpImageName(L"images/carp.png");



/** Constructor
* \param aquarium The aquarium this is a member of
*/
CFishCarp::CFishCarp(CAquarium *aquarium) :
	CFish(aquarium, FishCarpImageName)
{
	setSpeedX(((double)rand() / RAND_MAX) * 70);
	setSpeedY(((double)rand() / RAND_MAX) * 70);
}


/**
* Destructor
*/
CFishCarp::~CFishCarp()
{
}


/**
* Save this item to an XML node
* \param node The node we are going to be a child of
* \return node the node it returns gets saved
*/
std::shared_ptr<xmlnode::CXmlNode>
CFishCarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"carp");
	return itemNode;
}

