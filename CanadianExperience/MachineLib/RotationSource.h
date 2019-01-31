#pragma once

#include <vector>
#include "RotationSink.h"


class CRotationSource
{
public:
	CRotationSource();
	virtual ~CRotationSource();

	/// Copy constructor (disabled)
	CRotationSource(const CRotationSource &) = delete;

	/// Assignment operator (disabled)
	void operator=(const CRotationSource &) = delete;

	void AddSink(CRotationSink* sink) { mSink.push_back(sink); }

	void MoveComponent(double rotation);

private:
	std::vector<CRotationSink*> mSink;
};

