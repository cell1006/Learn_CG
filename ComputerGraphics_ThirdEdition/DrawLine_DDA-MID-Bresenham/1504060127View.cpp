// 1504060127View.cpp : implementation of the CMy1504060127View class
/*---------------------------------------------------------------*/
/*-------------------直线扫描与转换------------------------------*/ 
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
	CMy1504060127Doc*pDoc=GetDocument();//获得文档类指针
	CClientDC ht(this);                 //定义当前绘图设备

	if(MenuID==1){                      //DDA直线
		if(PressNum==0){                //第一次按键将第一点保留在文档类数组中
			pDoc->group[PressNum]=point; //将当前点传入group[]
			PressNum++;                 //进入下一次按键计数
			
			mPointOrign=point;          //将当前点赋给mPointOrign和mPointOld
			mPointOld=point;

			SetCapture();             //启动鼠标捕获
		}else if(PressNum==1){        //第二次按键保留第二点，用文档类画线
			pDoc->group[PressNum]=point;
			PressNum=0;               //按键计数器归零

			pDoc->DDALine(&ht);       //调用DDALine()画图
			ReleaseCapture();         //释放鼠标捕获
		}
	}
	if(MenuID==2){					//中点直线
		if(PressNum==0){                //第一次按键将第一点保留在文档类数组中
			pDoc->group[PressNum]=point; //将当前点传入group[]
			PressNum++;                 //进入下一次按键计数
			
			mPointOrign=point;          //将当前点赋给mPointOrign和mPointOld
			mPointOld=point;

			SetCapture();             //启动鼠标捕获
		}else if(PressNum==1){        //第二次按键保留第二点，用文档类画线
			pDoc->group[PressNum]=point;
			PressNum=0;               //按键计数器归零

			pDoc->MIDLine(&ht);       //调用MIDLine()画图
			ReleaseCapture();         //释放鼠标捕获
		}
	}
	if(MenuID==3){					//Bresenham直线
		if(PressNum==0){                //第一次按键将第一点保留在文档类数组中
			pDoc->group[PressNum]=point; //将当前点传入group[]
			PressNum++;                 //进入下一次按键计数
			
			mPointOrign=point;          //将当前点赋给mPointOrign和mPointOld
			mPointOld=point;

			SetCapture();             //启动鼠标捕获
		}else if(PressNum==1){        //第二次按键保留第二点，用文档类画线
			pDoc->group[PressNum]=point;
			PressNum=0;               //按键计数器归零

			pDoc->BLine(&ht);       //调用BLine()画图
			ReleaseCapture();         //释放鼠标捕获
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
	坐标显示
	橡皮筋技术
*/
void CMy1504060127View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int xx,yy;              //定义坐标缓存器
	char p1[20];            //定义字符缓存器
	
	CClientDC pDC(this);    //指向用于绘制图像文件的设备
	OnPrepareDC(&pDC);      //设置映射
	
	pDC.DPtoLP(&point);     //将设备坐标转换为逻辑坐标
	pDC.SetROP2(R2_NOT);    //R2_NOT模式有在同一个地方画两次相当于什么都没画的功能，第一次画的时候显示颜色并不是你选定的画笔颜色，而是默认的颜色。 

	xx=point.x;				//取出坐标信息
	yy=point.y;

	sprintf(p1,"%4d",xx);   //数字转字符串
	m_wndStatusBar.SetPaneText(2,p1,TRUE);//显示到状态栏
	sprintf(p1,"%4d",yy);
	m_wndStatusBar.SetPaneText(3,p1,TRUE);

	/*在一次直线绘制中下面代码当点坐标变化一次就执行一次*/
	if(MenuID<=3&&PressNum==1){//画直线且已经获取第一点时
		/*橡皮筋核心*/
		if(mPointOld!=point){   //如果鼠标离开保存在mPointOld的点
			                         
									  //第一次执行             |第二次执行          |第三次执行
									  //	                   |               擦掉前面的         
			pDC.MoveTo(mPointOrign);  //画笔移到第一点		   | 画笔移到第一点     |画笔移到第一点
			pDC.LineTo(mPointOld);    //第一点画到第一点	   | 从第一点画到当前点 |从第一点画到当前点
									  //            擦掉上一次的		  
			pDC.MoveTo(mPointOrign);  //画笔移到第一点         | 画笔移到第一点     |画笔移到第一点
			pDC.LineTo(point);        //第一点画到当前点       | 第一点画到当前点   |第一点画到当前点
									
			mPointOld=point;          //            将当前点装入mPonitOld   
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
