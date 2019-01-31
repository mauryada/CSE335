#pragma once
#include "TileVisitor.h"


///Class that makes a building counter.
class CBuildingCounter :
	public CTileVisitor
{
public:
	CBuildingCounter();
	virtual ~CBuildingCounter();


	/** Visit a CTileBuilding object
	* \return building Building we are visiting */
	int GetNumBuildings() const { return mNumBuildings; }

	/** Visit a CTileBuilding object
	* \param building Building we are visiting */
	void CBuildingCounter::VisitBuilding(CTileBuilding *building)
	{
		mNumBuildings++;
	}

private:
	/// Buildings counter
	int mNumBuildings = 0;
};

