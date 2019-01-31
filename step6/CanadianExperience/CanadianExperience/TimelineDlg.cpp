// TimelineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CanadianExperience.h"
#include "TimelineDlg.h"
#include "afxdialogex.h"


// CTimelineDlg dialog

IMPLEMENT_DYNAMIC(CTimelineDlg, CDialog)

CTimelineDlg::CTimelineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TIMELINEDLG, pParent)
	, mNumFrames(0)
	, mFrameRate(0)
{

}

CTimelineDlg::~CTimelineDlg()
{
}

void CTimelineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUMFRAMES, mNumFrames);
	DDV_MinMaxInt(pDX, mNumFrames, 10, 10000);
	DDX_Text(pDX, IDC_EDIT2, mFrameRate);
	DDV_MinMaxInt(pDX, mFrameRate, 1, 60);
}


BEGIN_MESSAGE_MAP(CTimelineDlg, CDialog)
END_MESSAGE_MAP()


// CTimelineDlg message handlers
