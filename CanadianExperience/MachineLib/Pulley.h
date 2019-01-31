#pragma once
//#include "RotationSink.h"
//#include "RotationSink.h"
#include "Component.h"
#include "RotationSource.h"

class CPulley :
	public CComponent
{
public:
	/** \brief Default constructor disabled */
	CPulley() = delete;
	/** \brief Copy constructor disabled */
	CPulley(const CPulley &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CPulley &) = delete;

	CPulley(double radius);

	virtual ~CPulley();
	void Draw(Gdiplus::Graphics* graphics, int x, int y) override;

	//void SetRotation();

	CRotationSink *GetSink() { return &mSink; }

	CRotationSource *GetSource() { return &mSource; }

	void SetRotation(double rotation) override;

	void Drive(std::shared_ptr<CPulley> pulley);

	double GetRadius() { return mRadius; }


private:
	double mRadius = 0;
	CRotationSink mSink;
	CRotationSource mSource;

	CPulley *mDrivingPulley = nullptr;

	std::shared_ptr<CPulley> mDrivenPulley;

};

