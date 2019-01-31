/**
* \file FishMolly.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Molly fish
*/

#pragma once

#include <memory>

#include "Item.h"
#include "Fish.h"

/**
* Implements a Molly fish
*/
class CFishMolly : public CFish
{
public:
	CFishMolly(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishMolly() = delete;

	/// Copy constructor (disabled)
	CFishMolly(const CFishMolly &) = delete;
	///This returns the type of fish
	virtual string whatType() { return "molly"; }

	~CFishMolly();
	///This is to save it to the xml file.
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
    

};