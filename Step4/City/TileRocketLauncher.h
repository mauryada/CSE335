/**
* \file TileRocketLauncher.h
*
* \author Charles B. Owen
*
*  Class that implements a Rocket Launcher Tile
*/



#pragma once
#include "Tile.h"
/**
*  A Rocket Launcher Tile
*/

class CTileRocketLauncher :
	public CTile
{
public:

	CTileRocketLauncher(CCity *city);

	


	///  Default constructor (disabled)
	CTileRocketLauncher() = delete;

	///  Copy constructor (disabled)
	CTileRocketLauncher(const CTileRocketLauncher &) = delete;

	void LoadImage(std::unique_ptr<Gdiplus::Bitmap>& image, std::wstring name);

	void Draw(Gdiplus::Graphics * graphics);

	~CTileRocketLauncher();

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);
};

