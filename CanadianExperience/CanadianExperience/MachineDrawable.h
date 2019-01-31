#pragma once
#include "Drawable.h"
#include "Machine.h"
#include "AnimChannelPoint.h"

class CMachineDrawable :
	public CDrawable
{
public:

	virtual ~CMachineDrawable();

	/** \brief Default constructor disabled */
	CMachineDrawable() = delete;
	/** \brief Copy constructor disabled */
	CMachineDrawable(const CMachineDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMachineDrawable &) = delete;

	CMachineDrawable(const std::wstring &name, int machineNum);

	virtual void Draw(Gdiplus::Graphics *graphics) override;

	virtual void SetTimeline(CTimeline *timeline) override;

	virtual bool HitTest(Gdiplus::Point position) override { return false; }

	virtual void SetPosition(Gdiplus::Point position) override;

private:
	std::shared_ptr<CMachine> mMachine;

	CAnimChannelPoint mMachineAnimChannelPoint;

};

