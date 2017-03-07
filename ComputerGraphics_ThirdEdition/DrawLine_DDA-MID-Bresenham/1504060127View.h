// 1504060127View.h : interface of the CMy1504060127View class
/*---------------------------------------------------------------*/
/*-------------------直线扫描与转换------------------------------*/ 
/*--------------Date:20170307------------------------------------*/
/*--------------Author:cell1006----------------------------------*/
/*--------------More:https://github.com/cell1006-----------------*/
/////////////////////////////////////////////////////////////////////////////


#if !defined(AFX_1504060127VIEW_H__B442DFA0_2543_405F_92FA_BE6EAD2A281C__INCLUDED_)
#define AFX_1504060127VIEW_H__B442DFA0_2543_405F_92FA_BE6EAD2A281C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1504060127View : public CView
{
protected: // create from serialization only
	int MenuID,PressNum;
	CPoint mPointOrign,mPointOld; //声明直线端点
	CMy1504060127View();
	DECLARE_DYNCREATE(CMy1504060127View)

// Attributes
public:
	CMy1504060127Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1504060127View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1504060127View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1504060127View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawDdaline();
	afx_msg void OnDrawMidline();
	afx_msg void OnDrawBline();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 1504060127View.cpp
inline CMy1504060127Doc* CMy1504060127View::GetDocument()
   { return (CMy1504060127Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1504060127VIEW_H__B442DFA0_2543_405F_92FA_BE6EAD2A281C__INCLUDED_)
