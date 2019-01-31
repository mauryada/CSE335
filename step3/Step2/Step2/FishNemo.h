/**
* \file FishNemo.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Nemo fish
*/

#pragma once

#include <memory>

#include "Item.h"
#include "Fish.h"


/**
* Implements a Nemo fish
*/
class CFishNemo : public CFish
{
public:
	CFishNemo(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishNemo() = delete;

	/// Copy constructor (disabled)
	CFishNemo(const CFishNemo &) = delete;
	///This returns the type of fish.
	virtual string whatType() { return "nemo"; }

	virtual ~CFishNemo();

	///This saves it to the xml file.
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	
	


};