/**
* \file FishCarp.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Carp fish
*/

#pragma once

#include <memory>

#include "Item.h"
#include "Fish.h"


/**
* Implements a Carp fish
*/
class CFishCarp : public CFish
{
public:
	CFishCarp(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishCarp() = delete;

	/// Copy constructor (disabled)
	CFishCarp(const CFishCarp &) = delete;
	///This returns a string to tell what kind of fish it is.
	virtual string whatType() { return "carp"; }

	~CFishCarp();
    

	/**
	* Is this item a killer?
	* \returns true - it will kill!
	*/
	virtual bool IsKiller() { return true; }
	///This is to save it to the xml file
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;


};