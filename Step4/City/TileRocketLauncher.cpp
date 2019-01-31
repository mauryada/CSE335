#include "stdafx.h"
#include "TileRocketLauncher.h"

using namespace std;
using namespace Gdiplus;


const wstring TileBackground = L"rocketB.png";

/// The image of the left pointing hand
std::unique_ptr<Gdiplus::Bitmap> mRocketLaunch;

/** Constructor
* \param city The city this is a member of
*/
CTileRocketLauncher::CTileRocketLauncher(CCity *city) : CTile(city)
{
	SetImage(TileBackground);
	LoadImage(mRocketLaunch, L"rocket.png");
}


/**
* Load an image into a bitmap
* \param image Image pointer to load
* \param name Filename to load from
*/
void CTileRocketLauncher::LoadImage(std::unique_ptr<Gdiplus::Bitmap> &image, std::wstring name)
{
	wstring filename = ImagesDirectory + name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


/**
* Load an image into a bitmap
* \param graphics Image pointer to load
*/
void CTileRocketLauncher::Draw(Gdiplus::Graphics *graphics)
{
	CTile::Draw(graphics);

	if (true)
	{
		int wid = mRocketLaunch->GetWidth();
		int hit = mRocketLaunch->GetHeight();

		graphics->DrawImage(mRocketLaunch.get(),
			(int)(GetX()), (int)(GetY()),
			wid, hit);
	}

}


/**
*  Destructor
*/
CTileRocketLauncher::~CTileRocketLauncher()
{
}


/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileRocketLauncher::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CTile::XmlSave(node);

	itemNode->SetAttribute(L"type", L"rocketLauncher");
	itemNode->SetAttribute(L"file", GetFile());

	return itemNode;
}


/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
*/
void CTileRocketLauncher::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	CTile::XmlLoad(node);
	SetImage(node->GetAttributeValue(L"file", L""));
}