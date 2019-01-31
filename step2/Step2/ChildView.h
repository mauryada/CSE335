/**
* \file ChildView.h
*
* \author Jaiwant Bhushan
*
* Class that implements the child window our program draws in.
*
* The window is a child of the main frame, which holds this
* window, the menu bar, and the status bar.
*/
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "Aquarium.h"


// CChildView window
/**
* The child window our program draws in.
*/
class CChildView : public CWnd
{
private:
	/// An object that describes our aquarium
	CAquarium  mAquarium;
	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;


// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAddfishBetafish();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//afx_msg void OnAddfishFish1();
	//afx_msg void OnAddfishFish3();
	afx_msg void OnAddfishFishone();
	afx_msg void OnAddfishFishtwo();
	afx_msg void OnAddfishCarpfish();
};
