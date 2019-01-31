/**
* \file DecorScull.h
*
* \author Jaiwant Bhushan
*
* Class the implements a Scull
*/

#pragma once
#include "Item.h"
#include <memory>

///This is the skull class.
class CDecorScull :
	public CItem
{
public:
	/** CDecorScull();
	virtual ~CDecorScull(); **/

	/// Default constructor (disabled)
	CDecorScull() = delete;

	/// Copy constructor (disabled)
	CDecorScull(const CDecorScull &) = delete;
	///Default constructor
	CDecorScull(CAquarium * aquarium);
	///Destructor
	virtual ~CDecorScull();
	///This saves the item to the xml file. Return type is a node that gets saved.
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
};

