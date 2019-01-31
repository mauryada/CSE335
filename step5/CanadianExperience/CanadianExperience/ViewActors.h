/**
 * \file ViewActors.h
 *
 * \author Jaiwant Bhushan
 *
 * Class that provides a view windows for actors.
 */

#pragma once
#include "PictureObserver.h"

class CMainFrame;

/** Class that provides a view windows for actors. */
class CViewActors : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewActors)
public:
    static const int Width = 150;  ///< Width we want for this window 
	/**
	* Set the mainFrame pointer
	* \param mainFrame Pointer to the CMainFrame window
	*/
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }

protected:
	CViewActors();           // protected constructor used by dynamic creation
	virtual ~CViewActors();


protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()
private:
	/// The main frame window that uses this view
	CMainFrame  *mMainFrame = nullptr;

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void UpdateObserver();
};


