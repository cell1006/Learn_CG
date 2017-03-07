// 1504060127.h : main header file for the 1504060127 application
//

#if !defined(AFX_1504060127_H__C7281DD2_ABC5_4A9B_A82F_A153619DDBF3__INCLUDED_)
#define AFX_1504060127_H__C7281DD2_ABC5_4A9B_A82F_A153619DDBF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1504060127App:
// See 1504060127.cpp for the implementation of this class
//

class CMy1504060127App : public CWinApp
{
public:
	CMy1504060127App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1504060127App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy1504060127App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1504060127_H__C7281DD2_ABC5_4A9B_A82F_A153619DDBF3__INCLUDED_)
