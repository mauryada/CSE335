#pragma once


#include "Timeline.h"

/// CTimelineDlg dialog
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	/// standard constructor
	CTimelineDlg(CWnd* pParent = NULL);   
	virtual ~CTimelineDlg();

	/**
	* Pass a timeline object to this dialog box class.
	* \param timeline The timeline object.
	*/
	void CTimelineDlg::SetTimeline(CTimeline *timeline)
	{
		mTimeline = timeline;
		mNumFrames = mTimeline->GetNumFrames();
	}
	/** Transfer dialog values to the Timeline object
	*/
	void CTimelineDlg::Take()
	{
		mTimeline->SetNumFrames(mNumFrames);
}

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:
	/// DDX/DDV support
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
private:
	///mframes
	int mNumFrames;
	///rate
	int mFrameRate;
	/// The timeline we are editing
	CTimeline *mTimeline = nullptr;
};
