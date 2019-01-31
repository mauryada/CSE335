/**
* \file FishBeta.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Beta fish
*/

#pragma once
#include "Item.h"
#include "Fish.h"
#include <memory>

/**
* Implements a Beta fish
*/
class CFishBeta :
	public CFish
{
public:
	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta &) = delete;
	///This is the default constructor
	CFishBeta(CAquarium * aquarium);
	///This returns the type of fish
	virtual string whatType() { return "beta"; }
	///This is destructor.
	virtual ~CFishBeta();
	///This is to save to the xml file
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;


};

