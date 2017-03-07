// 1504060127View.cpp : implementation of the CMy1504060127View class
/*---------------------------------------------------------------*/
/*-------------------ֱ��ɨ����ת��------------------------------*/ 
/*--------------Date:20170307------------------------------------*/
/*--------------Author:cell1006----------------------------------*/
/*--------------More:https://github.com/cell1006-----------------*/
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "1504060127.h"

#include "1504060127Doc.h"
#include "1504060127View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CStatusBar m_wndStatusBar;
/////////////////////////////////////////////////////////////////////////////
// CMy1504060127View

IMPLEMENT_DYNCREATE(CMy1504060127View, CView)

BEGIN_MESSAGE_MAP(CMy1504060127View, CView)
	//{{AFX_MSG_MAP(CMy1504060127View)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_DDALINE, OnDrawDdaline)
	ON_COMMAND(ID_DRAW_MIDLINE, OnDrawMidline)
	ON_COMMAND(ID_DRAW_BLINE, OnDrawBline)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1504060127View construction/destruction

CMy1504060127View::CMy1504060127View()
{
	// TODO: add construction code here

}

CMy1504060127View::~CMy1504060127View()
{
}

BOOL CMy1504060127View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy1504060127View drawing

void CMy1504060127View::OnDraw(CDC* pDC)
{
	CMy1504060127Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy1504060127View diagnostics

#ifdef _DEBUG
void CMy1504060127View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1504060127View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1504060127Doc* CMy1504060127View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1504060127Doc)));
	return (CMy1504060127Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1504060127View message handlers

void CMy1504060127View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMy1504060127Doc*pDoc=GetDocument();//����ĵ���ָ��
	CClientDC ht(this);                 //���嵱ǰ��ͼ�豸

	if(MenuID==1){                      //DDAֱ��
		if(PressNum==0){                //��һ�ΰ�������һ�㱣�����ĵ���������
			pDoc->group[PressNum]=point; //����ǰ�㴫��group[]
			PressNum++;                 //������һ�ΰ�������
			
			mPointOrign=point;          //����ǰ�㸳��mPointOrign��mPointOld
			mPointOld=point;

			SetCapture();             //������겶��
		}else if(PressNum==1){        //�ڶ��ΰ��������ڶ��㣬���ĵ��໭��
			pDoc->group[PressNum]=point;
			PressNum=0;               //��������������

			pDoc->DDALine(&ht);       //����DDALine()��ͼ
			ReleaseCapture();         //�ͷ���겶��
		}
	}
	if(MenuID==2){					//�е�ֱ��
		if(PressNum==0){                //��һ�ΰ�������һ�㱣�����ĵ���������
			pDoc->group[PressNum]=point; //����ǰ�㴫��group[]
			PressNum++;                 //������һ�ΰ�������
			
			mPointOrign=point;          //����ǰ�㸳��mPointOrign��mPointOld
			mPointOld=point;

			SetCapture();             //������겶��
		}else if(PressNum==1){        //�ڶ��ΰ��������ڶ��㣬���ĵ��໭��
			pDoc->group[PressNum]=point;
			PressNum=0;               //��������������

			pDoc->MIDLine(&ht);       //����MIDLine()��ͼ
			ReleaseCapture();         //�ͷ���겶��
		}
	}
	if(MenuID==3){					//Bresenhamֱ��
		if(PressNum==0){                //��һ�ΰ�������һ�㱣�����ĵ���������
			pDoc->group[PressNum]=point; //����ǰ�㴫��group[]
			PressNum++;                 //������һ�ΰ�������
			
			mPointOrign=point;          //����ǰ�㸳��mPointOrign��mPointOld
			mPointOld=point;

			SetCapture();             //������겶��
		}else if(PressNum==1){        //�ڶ��ΰ��������ڶ��㣬���ĵ��໭��
			pDoc->group[PressNum]=point;
			PressNum=0;               //��������������

			pDoc->BLine(&ht);       //����BLine()��ͼ
			ReleaseCapture();         //�ͷ���겶��
		}
	}
	CView::OnLButtonDown(nFlags, point);
}

void CMy1504060127View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnRButtonDown(nFlags, point);
}
/*
	������ʾ
	��Ƥ���
*/
void CMy1504060127View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int xx,yy;              //�������껺����
	char p1[20];            //�����ַ�������
	
	CClientDC pDC(this);    //ָ�����ڻ���ͼ���ļ����豸
	OnPrepareDC(&pDC);      //����ӳ��
	
	pDC.DPtoLP(&point);     //���豸����ת��Ϊ�߼�����
	pDC.SetROP2(R2_NOT);    //R2_NOTģʽ����ͬһ���ط��������൱��ʲô��û���Ĺ��ܣ���һ�λ���ʱ����ʾ��ɫ��������ѡ���Ļ�����ɫ������Ĭ�ϵ���ɫ�� 

	xx=point.x;				//ȡ��������Ϣ
	yy=point.y;

	sprintf(p1,"%4d",xx);   //����ת�ַ���
	m_wndStatusBar.SetPaneText(2,p1,TRUE);//��ʾ��״̬��
	sprintf(p1,"%4d",yy);
	m_wndStatusBar.SetPaneText(3,p1,TRUE);

	/*��һ��ֱ�߻�����������뵱������仯һ�ξ�ִ��һ��*/
	if(MenuID<=3&&PressNum==1){//��ֱ�����Ѿ���ȡ��һ��ʱ
		/*��Ƥ�����*/
		if(mPointOld!=point){   //�������뿪������mPointOld�ĵ�
			                         
									  //��һ��ִ��             |�ڶ���ִ��          |������ִ��
									  //	                   |               ����ǰ���         
			pDC.MoveTo(mPointOrign);  //�����Ƶ���һ��		   | �����Ƶ���һ��     |�����Ƶ���һ��
			pDC.LineTo(mPointOld);    //��һ�㻭����һ��	   | �ӵ�һ�㻭����ǰ�� |�ӵ�һ�㻭����ǰ��
									  //            ������һ�ε�		  
			pDC.MoveTo(mPointOrign);  //�����Ƶ���һ��         | �����Ƶ���һ��     |�����Ƶ���һ��
			pDC.LineTo(point);        //��һ�㻭����ǰ��       | ��һ�㻭����ǰ��   |��һ�㻭����ǰ��
									
			mPointOld=point;          //            ����ǰ��װ��mPonitOld   
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CMy1504060127View::OnDrawDdaline() 
{
	// TODO: Add your command handler code here
	PressNum=0;
	MenuID=1;
}

void CMy1504060127View::OnDrawMidline() 
{
	// TODO: Add your command handler code here
	PressNum=0;
	MenuID=2;
	
}

void CMy1504060127View::OnDrawBline() 
{
	// TODO: Add your command handler code here
	PressNum=0;
	MenuID=3;	
}
