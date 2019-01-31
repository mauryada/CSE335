/**
* \file FishBeta.cpp
*
* \author Jaiwant Bhushan
*/

#include "stdafx.h"
#include <string>
#include "FishBeta.h"


using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishBetaImageName(L"images/beta.png");

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
CFishBeta::CFishBeta(CAquarium *aquarium) :
	CFish(aquarium, FishBetaImageName)
{
	setSpeedX(((double)rand() / RAND_MAX) * 10);
	setSpeedY(((double)rand() / RAND_MAX) * 10);
}


/**
* Destructor
*/
CFishBeta::~CFishBeta()
{
}

/**
* Save this item to an XML node
* \param node The node we are going to be a child of
* \return itemNode is the node it returns
*/
std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"beta");

	return itemNode;
}

