/**
 * \file ViewEdit.h
 *
 * \author Jaiwant Bhushan
 *
 * View class the provides a window for editing our pixture
 */

#pragma once
#include "PictureObserver.h"

//#include "Drawable.h"

class CMainFrame;
class CActor;
class CDrawable;

/** View class the provides a window for editing our pixture */
class CViewEdit : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewEdit)

public:
	CViewEdit();           // protected constructor used by dynamic creation
	virtual ~CViewEdit();
	/**
	* Set the mainFrame pointer
	* \param mainFrame Pointer to the CMainFrame window
	*/
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()
private:
	/// The main frame window that uses this view
	CMainFrame  *mMainFrame = nullptr;
	///THis is the selected actor item
	std::shared_ptr<CActor> mSelectedActor;
	///This is the selected drawable item
	std::shared_ptr<CDrawable> mSelectedDrawable;
	/// The last mouse position
	Gdiplus::Point mLastMouse = Gdiplus::Point(0, 0);

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);

    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void UpdateObserver();
};


