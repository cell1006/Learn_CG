// 1504060127Doc.cpp : implementation of the CMy1504060127Doc class
/*---------------------------------------------------------------*/
/*-------------------直线扫描与转换------------------------------*/ 
/*--------------Date:20170307------------------------------------*/
/*--------------Author:cell1006----------------------------------*/
/*--------------More:https://github.com/cell1006-----------------*/
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "1504060127.h"

#include "1504060127Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1504060127Doc

IMPLEMENT_DYNCREATE(CMy1504060127Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy1504060127Doc, CDocument)
	//{{AFX_MSG_MAP(CMy1504060127Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1504060127Doc construction/destruction

CMy1504060127Doc::CMy1504060127Doc()
{
	// TODO: add one-time construction code here

}

CMy1504060127Doc::~CMy1504060127Doc()
{
}

BOOL CMy1504060127Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy1504060127Doc serialization

void CMy1504060127Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy1504060127Doc diagnostics

#ifdef _DEBUG
void CMy1504060127Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1504060127Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG
void CMy1504060127Doc::DDALine(CClientDC*DCPoint){
	/*DDA画线函数*/
	/*
	CPen pen(0,0,RGB(0,0,255));  //定义画笔
	CPen *pOldPen=DCPoint->SelectObject(&pen);  //绘图设备选新笔
												//同时保留旧笔
	DCPoint->SetROP2(R2_COPYPEN);               //设置绘图方法为直接画
	DCPoint->MoveTo(group[0]);                  //拿到鼠标事先获取并添加到group[]中的第一点，并将画笔移动至此点

	DCPoint->LineTo(group[1]);                   //拿到鼠标事先获取并添加到group[]中的第二点，并画线到此点

	DCPoint->SelectObject(pOldPen);              //恢复旧笔
	*/
	/*【1】声明所需变量*/
	int x,x0,y0,x1,y1,flag;
	float m,y;
/*-----------------重复代码，用于获取点坐标，并分类点坐标将其标准化--------*/
/*-----------------flag=1  0< k < 1  标准类--------------------------------*/
/*-----------------flag=2 -1< k < 0  对y取反转成标准类---------------------*/
/*-----------------flag=3  1< k      对调xy转成标准类----------------------*/
/*-----------------flag=3     K <-1  对调xy并对y取反转成标准类-------------*/
/*----紧凑版代码----------为了复用率得写个方法替换-------------------------*/
/*	【2】【3】为重复代码
    模板：
	//【1】声明变量
	int x0,y0,x1,y1,flag;
	//【2】准备画笔拿到坐标
	DCPoint->SetROP2(R2_COPYPEN);
	x0=group[0].x;    y0=group[0].y;
	x1=group[1].x;    y1=group[1].y;
	//【3】将所有情况分类画出或者标准化
    if(x0==x1&&y0==y1)return;
	if(x0==x1){
		if(y0>y1){x=y0; y0=y1; y1=x;}
		for(x=y0;x<=y1;x++){ DCPoint->SetPixel(x0,x,RGB(0,0,255)); }
		return;
	}
	if(y0==y1){
		if(x0>x1){x=x0; x0=x1; x1=x; }
		for(x=x0;x<=x1;x++){ DCPoint->SetPixel(x,y0,RGB(0,0,255));}
		return;
	}
	if(x0>x1){ x=x0; x0=x1; x1=x;  x=y0; y0=y1; y1=x; }
	flag=0;
	if((x1-x0>y1-y0)&&(y1-y0>0))flag=1;
	if((x1-x0>y0-y1)&&(y0-y1>0)){ flag=2; y0=-y0; y1=-y1; }
	if(y1-y0>x1-x0){ flag=3; x=x0; x0=y0; y0=x; x=x1; x1=y1; y1=x; }
	if(y0-y1>x1-x0){ flag=4; x=x0; x0=-y0; y0=x; x=x1; x1=-y1; y1=x; }	
	//【4】**核心算法
	if(flag==1)DCPoint->SetPixel(x,int(y),RGB(0,0,255));
	if(flag==2)DCPoint->SetPixel(x,-int(y),RGB(0,0,255));
	if(flag==3)DCPoint->SetPixel(int(y),x,RGB(0,0,255));
	if(flag==4)DCPoint->SetPixel(int(y),-x,RGB(0,0,255));
*/
	/*【2】准备画笔，拿到坐标*/
	DCPoint->SetROP2(R2_COPYPEN);//画笔设置ROP2码为R2_COPYPEN(直接画)
	
	//拿到第一点坐标
	x0=group[0].x;    
	y0=group[0].y;
	//拿到第二点坐标
	x1=group[1].x;
	y1=group[1].y;

	/*【3】将所有情况分类画出或者标准化*/
	//两点重叠
	if(x0==x1&&y0==y1)return;
	//垂直线
	if(x0==x1){
		if(y0>y1){//起点在上
			//交换起点终点坐标
			x=y0;
			y0=y1;
			y1=x;
		}
		for(x=y0;x<=y1;x++){
			DCPoint->SetPixel(x0,x,RGB(0,0,255));
		}
		return;
	}
	//水平线
	if(y0==y1){
		if(x0>x1){//起点在右
			//交换...
			x=x0;
			x0=x1;
			x1=x;
		}
		for(x=x0;x<=x1;x++){
			DCPoint->SetPixel(x,y0,RGB(0,0,255));
		}
		return;
	}
	if(x0>x1){
		//交换起始、终止点
		x=x0;
		x0=x1;
		x1=x;

		x=y0;
		y0=y1;
		y1=x;
	}
	flag=0;
	if((x1-x0>y1-y0)&&(y1-y0>0))flag=1;//0<k<1
	if((x1-x0>y0-y1)&&(y0-y1>0)){//-1<k<0
		flag=2;
		//对y取反
		y0=-y0;
		y1=-y1;
	}
	if(y1-y0>x1-x0){//k>1
		flag=3;
		//对调xy
		x=x0;
		x0=y0;
		y0=x;
		x=x1;
		x1=y1;
		y1=x;
	}
	if(y0-y1>x1-x0){//k<-1
		flag=4;
		//对调xy并对y取反
		x=x0;
		x0=-y0;
		y0=x;
		x=x1;
		x1=-y1;
		y1=x;
	}
/*--------------------------------------------------------------------------*/
	/*【4】DDA算法核心*/
	m=(float)(y1-y0)/(float)(x1-x0);
	for(x=x0,y=(float)y0;x<=x1;x++,y=y+m){
		if(flag==1)DCPoint->SetPixel(x,int(y),RGB(0,0,255));//标准类
		//逆标准化
		if(flag==2)DCPoint->SetPixel(x,-int(y),RGB(0,0,255));//逆y取反
		if(flag==3)DCPoint->SetPixel(int(y),x,RGB(0,0,255));//逆xy对调
		if(flag==4)DCPoint->SetPixel(int(y),-x,RGB(0,0,255));//逆xy对调y取反
	}
}
void CMy1504060127Doc::MIDLine(CClientDC*DCPoint){
	/*中点画线函数*/
	//【1】声明变量
	int x0,y0,x1,y1,flag;
	int a, b, d1, d2, d, x, y;
	//【2】准备画笔拿到坐标
	DCPoint->SetROP2(R2_COPYPEN);
	x0=group[0].x;    y0=group[0].y;
	x1=group[1].x;    y1=group[1].y;
	//【3】将所有情况分类画出或者标准化
    if(x0==x1&&y0==y1)return;
	if(x0==x1){
		if(y0>y1){x=y0; y0=y1; y1=x;}
		for(x=y0;x<=y1;x++){ DCPoint->SetPixel(x0,x,RGB(0,255,0)); }
		return;
	}
	if(y0==y1){
		if(x0>x1){x=x0; x0=x1; x1=x; }
		for(x=x0;x<=x1;x++){ DCPoint->SetPixel(x,y0,RGB(0,255,0));}
		return;
	}
	if(x0>x1){ x=x0; x0=x1; x1=x;  x=y0; y0=y1; y1=x; }
	flag=0;
	if((x1-x0>y1-y0)&&(y1-y0>0))flag=1;
	if((x1-x0>y0-y1)&&(y0-y1>0)){ flag=2; y0=-y0; y1=-y1; }
	if(y1-y0>x1-x0){ flag=3; x=x0; x0=y0; y0=x; x=x1; x1=y1; y1=x; }
	if(y0-y1>x1-x0){ flag=4; x=x0; x0=-y0; y0=x; x=x1; x1=-y1; y1=x; }	
	//【4】中点画线核心算法
	a=y0-y1;
	b=x1-x0; 
	d=2*a+b;
	d1=2*a; 
	d2=2* (a+b);
	x=x0; 
	y=y0;
	if(flag==1)DCPoint->SetPixel(x,int(y),RGB(0,255,0));
	if(flag==2)DCPoint->SetPixel(x,-int(y),RGB(0,255,0));
	if(flag==3)DCPoint->SetPixel(int(y),x,RGB(0,255,0));
	if(flag==4)DCPoint->SetPixel(int(y),-x,RGB(0,255,0));
	while (x<x1){ 
		if (d<0) {
			x++; 
			y++; 
			d+=d2; 
		}else {
			x++; 
			d+=d1;
		}
		if(flag==1)DCPoint->SetPixel(x,int(y),RGB(0,255,0));
	    if(flag==2)DCPoint->SetPixel(x,-int(y),RGB(0,255,0));
		if(flag==3)DCPoint->SetPixel(int(y),x,RGB(0,255,0));
		if(flag==4)DCPoint->SetPixel(int(y),-x,RGB(0,255,0));
	} 
}
void CMy1504060127Doc::BLine(CClientDC*DCPoint){
	/*Bresenham画线函数*/
	//【1】声明变量
	int x0,y0,x1,y1,flag;
	int x,y,dx,dy,e;//声明绘制点坐标，坐标变化量，误差项符号判别值
	//【2】准备画笔拿到坐标
	DCPoint->SetROP2(R2_COPYPEN);
	x0=group[0].x;    y0=group[0].y;
	x1=group[1].x;    y1=group[1].y;
	//【3】将所有情况分类画出或者标准化
    if(x0==x1&&y0==y1)return;
	if(x0==x1){
		if(y0>y1){x=y0; y0=y1; y1=x;}
		for(x=y0;x<=y1;x++){ DCPoint->SetPixel(x0,x,RGB(255,0,0)); }
		return;
	}
	if(y0==y1){
		if(x0>x1){x=x0; x0=x1; x1=x; }
		for(x=x0;x<=x1;x++){ DCPoint->SetPixel(x,y0,RGB(255,0,0));}
		return;
	}
	if(x0>x1){ x=x0; x0=x1; x1=x;  x=y0; y0=y1; y1=x; }
	flag=0;
	if((x1-x0>y1-y0)&&(y1-y0>0))flag=1;
	if((x1-x0>y0-y1)&&(y0-y1>0)){ flag=2; y0=-y0; y1=-y1; }
	if(y1-y0>x1-x0){ flag=3; x=x0; x0=y0; y0=x; x=x1; x1=y1; y1=x; }
	if(y0-y1>x1-x0){ flag=4; x=x0; x0=-y0; y0=x; x=x1; x1=-y1; y1=x; }	
	//【4】Bresenham画线核心算法
	dx=x1-x0;		//计算x变化量赋值给dx
	dy=y1-y0;		//计算y变化量赋值给dy
	e=-dx;			//设置误差项符号判别值初始值为-dx
	x=x0;			//将x0值赋给当前绘制点的x
	y=y0;			//将y0值赋给当前绘制点的y
	for(int i=0;i<=dx;i++){//当i小于x变化量时执行
		if(flag==1)DCPoint->SetPixel(x,int(y),RGB(255,0,0));
	    if(flag==2)DCPoint->SetPixel(x,-int(y),RGB(255,0,0));
		if(flag==3)DCPoint->SetPixel(int(y),x,RGB(255,0,0));
		if(flag==4)DCPoint->SetPixel(int(y),-x,RGB(255,0,0));
		x=x+1;			//x值加1后重新赋给x(列坐标右移)
		e=e+2*dy;		//误差项符号判别值加2倍dy后重新赋值给误差项符号判别值
		if(e>=0){//如果误差项符号判别值非负则执行
			y=y+1;		//y值加一后重新赋给y(行坐标上移)
			e=e-2*dx;   //误差项符号判别值减2倍dx后重新赋值给误差项符号判别值
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
// CMy1504060127Doc commands
