// 1504060127Doc.h : interface of the CMy1504060127Doc class
/*---------------------------------------------------------------*/
/*-------------------直线扫描与转换------------------------------*/ 
/*--------------Date:20170307------------------------------------*/
/*--------------Author:cell1006----------------------------------*/
/*--------------More:https://github.com/cell1006-----------------*/
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1504060127DOC_H__2A90B0C2_F972_4BC4_AD91_CE32885EA631__INCLUDED_)
#define AFX_1504060127DOC_H__2A90B0C2_F972_4BC4_AD91_CE32885EA631__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1504060127Doc : public CDocument
{
protected: // create from serialization only
	CMy1504060127Doc();
	DECLARE_DYNCREATE(CMy1504060127Doc)

// Attributes
public:
	CPoint group[100]; //定义目标点数组
// Operations
public:
	void DDALine(CClientDC*DCPoint);//定义DDA画线函数
	void MIDLine(CClientDC*DCPoint);//定义中点画线函数
	void BLine(CClientDC*DCPoint);//定义Bresenham画线函数
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1504060127Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1504060127Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1504060127Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1504060127DOC_H__2A90B0C2_F972_4BC4_AD91_CE32885EA631__INCLUDED_)
