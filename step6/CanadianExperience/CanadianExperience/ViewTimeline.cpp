/**
 * \file ViewTimeline.cpp
 *
 * \author Jaiwant Bhushan
 */


#include "stdafx.h"
#include "CanadianExperience.h"
#include "ViewTimeline.h"
#include "DoubleBufferDC.h"
#include "Timeline.h"
#include "Picture.h"
#include <sstream>
#include "MainFrm.h"

using namespace std;
using namespace Gdiplus;

/// The window height
const int WindowHeight = 65;

/// The spacing between ticks in the timeline
const int TickSpacing = 3;

/// The length of a short tick mark
const int TickShort = 10;

/// The length of a long tick mark
const int TickLong = 20;

/// The amount of space to leave under the tick marks
const int TickUnder = 10;

/// Space to the left of the scale
const int BorderLeft = 10;

/// Space to the right of the scale
const int BorderRight = 10;


IMPLEMENT_DYNCREATE(CViewTimeline, CScrollView)

/** Constructor */
CViewTimeline::CViewTimeline()
{
	mPointer = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/pointer.png"));
	assert(mPointer->GetLastStatus() == Ok);
}

/** Destructor */
CViewTimeline::~CViewTimeline()
{
}


BEGIN_MESSAGE_MAP(CViewTimeline, CScrollView)
    ON_WM_CREATE()
    ON_WM_ERASEBKGND()
    ON_COMMAND(ID_EDIT_SETKEYFRAME, &CViewTimeline::OnEditSetkeyframe)
    ON_COMMAND(ID_EDIT_DELETEKEYFRAME, &CViewTimeline::OnEditDeletekeyframe)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


/** Handle the initial update for this window */
void CViewTimeline::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

    int sbHeight = GetSystemMetrics(SM_CXHSCROLL);
    CSize sizeTotal(200, Height - sbHeight - 20);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/** Draw this window 
 * \param pDC Device context */
void CViewTimeline::OnDraw(CDC* pDC)
{
	// Get the timeline
	CTimeline *timeline = GetPicture()->GetTimeline();

	// Set the scroll system correctly
	CSize sizeTotal(timeline->GetNumFrames() * TickSpacing + BorderLeft + BorderRight, WindowHeight);
	SetScrollSizes(MM_TEXT, sizeTotal);

    CDoubleBufferDC dbDC(pDC);

    Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context
	CRect rect;
	GetClientRect(&rect);
	int hit = rect.Height();
	int wid = rect.Width();

	Pen pen(Color(0, 128, 0), 1);

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 6);

	

	for (int i = 0; i <= timeline->GetNumFrames(); i++) 
	{
		// Convert the tick number to seconds in a string
		std::wstringstream str;
		str << i / timeline->GetFrameRate();
		std::wstring wstr = str.str();

		RectF size;
		PointF origin(0.0f, 0.0f);
		graphics.MeasureString(wstr.c_str(), wstr.size(),
			&font, origin, &size);

	
		

		bool onSecond = (i % timeline->GetFrameRate()) == 0;

		if (onSecond)
		{
			SolidBrush brush(Color(0, 0, 0));
			graphics.DrawString(wstr.c_str(),  // String to draw
				-1,         // String length, -1 means it figures it out on its own
				&font,      // The font to use
				PointF(BorderLeft + TickSpacing*i-3, hit - TickLong - TickUnder-10),   // Where to draw
				&brush);    // The brush to draw the text with

			graphics.DrawLine(&pen, BorderLeft + TickSpacing*i, hit  - TickLong-TickUnder, BorderLeft + TickSpacing*i, hit - TickUnder);
		}
		else
		{
			graphics.DrawLine(&pen, BorderLeft + TickSpacing*i, hit - TickShort-TickUnder  , BorderLeft + TickSpacing*i, hit - TickUnder);
		}

		
	}
	
	graphics.DrawImage(mPointer.get(), BorderLeft+TickSpacing*timeline->GetCurrentTime()*timeline->GetFrameRate()-4, hit - TickLong - TickUnder, mPointer->GetWidth(), mPointer->GetHeight());

	

    // TODO: Drawing code goes here
}


/** Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context 
 * \return FALSE */
BOOL CViewTimeline::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}

/** Handle the Edit>Set Keyframe menu option */
 void CViewTimeline::OnEditSetkeyframe()
 {
     // TODO: Add your command handler code here
 }


 /** Handle the Edit>Delete Keyframe menu option */
 void CViewTimeline::OnEditDeletekeyframe()
 {
     // TODO: Add your command handler code here
 }

 /** Force an update of this window when the picture changes.
 */
 void CViewTimeline::UpdateObserver()
 {
	 Invalidate();
 }

 ///Mouse button down
 void CViewTimeline::OnLButtonDown(UINT nFlags, CPoint point)
 {
	 // Convert mouse coordinates to logical coordinates
	 CClientDC dc(this);
	 OnPrepareDC(&dc);
	 dc.DPtoLP(&point);

	 int x = point.x;

	 // Get the timeline
	 CTimeline *timeline = GetPicture()->GetTimeline();
	 int pointerX = (int)(timeline->GetCurrentTime() *
		 timeline->GetFrameRate() * TickSpacing + BorderLeft);

	 mMovingPointer = x >= pointerX - (int)mPointer->GetWidth() / 2 &&
		 x <= pointerX + (int)mPointer->GetWidth() / 2;

	 if (mMovingPointer)
	 {
		 int xx = 0;
	 }

	 __super::OnLButtonDown(nFlags, point);
 }



 ///Mouse move
 void CViewTimeline::OnMouseMove(UINT nFlags, CPoint point)
 {
	 // Convert mouse coordinates to logical coordinates
	 CClientDC dc(this);
	 OnPrepareDC(&dc);
	 dc.DPtoLP(&point);

	 // TODO: Add your message handler code here and/or call default



	 __super::OnMouseMove(nFlags, point);
 }
