// 1504060127Doc.cpp : implementation of the CMy1504060127Doc class
/*---------------------------------------------------------------*/
/*-------------------ֱ��ɨ����ת��------------------------------*/ 
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
	/*DDA���ߺ���*/
	/*
	CPen pen(0,0,RGB(0,0,255));  //���廭��
	CPen *pOldPen=DCPoint->SelectObject(&pen);  //��ͼ�豸ѡ�±�
												//ͬʱ�����ɱ�
	DCPoint->SetROP2(R2_COPYPEN);               //���û�ͼ����Ϊֱ�ӻ�
	DCPoint->MoveTo(group[0]);                  //�õ�������Ȼ�ȡ����ӵ�group[]�еĵ�һ�㣬���������ƶ����˵�

	DCPoint->LineTo(group[1]);                   //�õ�������Ȼ�ȡ����ӵ�group[]�еĵڶ��㣬�����ߵ��˵�

	DCPoint->SelectObject(pOldPen);              //�ָ��ɱ�
	*/
	/*��1�������������*/
	int x,x0,y0,x1,y1,flag;
	float m,y;
/*-----------------�ظ����룬���ڻ�ȡ�����꣬����������꽫���׼��--------*/
/*-----------------flag=1  0< k < 1  ��׼��--------------------------------*/
/*-----------------flag=2 -1< k < 0  ��yȡ��ת�ɱ�׼��---------------------*/
/*-----------------flag=3  1< k      �Ե�xyת�ɱ�׼��----------------------*/
/*-----------------flag=3     K <-1  �Ե�xy����yȡ��ת�ɱ�׼��-------------*/
/*----���հ����----------Ϊ�˸����ʵ�д�������滻-------------------------*/
/*	��2����3��Ϊ�ظ�����
    ģ�壺
	//��1����������
	int x0,y0,x1,y1,flag;
	//��2��׼�������õ�����
	DCPoint->SetROP2(R2_COPYPEN);
	x0=group[0].x;    y0=group[0].y;
	x1=group[1].x;    y1=group[1].y;
	//��3��������������໭�����߱�׼��
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
	//��4��**�����㷨
	if(flag==1)DCPoint->SetPixel(x,int(y),RGB(0,0,255));
	if(flag==2)DCPoint->SetPixel(x,-int(y),RGB(0,0,255));
	if(flag==3)DCPoint->SetPixel(int(y),x,RGB(0,0,255));
	if(flag==4)DCPoint->SetPixel(int(y),-x,RGB(0,0,255));
*/
	/*��2��׼�����ʣ��õ�����*/
	DCPoint->SetROP2(R2_COPYPEN);//��������ROP2��ΪR2_COPYPEN(ֱ�ӻ�)
	
	//�õ���һ������
	x0=group[0].x;    
	y0=group[0].y;
	//�õ��ڶ�������
	x1=group[1].x;
	y1=group[1].y;

	/*��3��������������໭�����߱�׼��*/
	//�����ص�
	if(x0==x1&&y0==y1)return;
	//��ֱ��
	if(x0==x1){
		if(y0>y1){//�������
			//��������յ�����
			x=y0;
			y0=y1;
			y1=x;
		}
		for(x=y0;x<=y1;x++){
			DCPoint->SetPixel(x0,x,RGB(0,0,255));
		}
		return;
	}
	//ˮƽ��
	if(y0==y1){
		if(x0>x1){//�������
			//����...
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
		//������ʼ����ֹ��
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
		//��yȡ��
		y0=-y0;
		y1=-y1;
	}
	if(y1-y0>x1-x0){//k>1
		flag=3;
		//�Ե�xy
		x=x0;
		x0=y0;
		y0=x;
		x=x1;
		x1=y1;
		y1=x;
	}
	if(y0-y1>x1-x0){//k<-1
		flag=4;
		//�Ե�xy����yȡ��
		x=x0;
		x0=-y0;
		y0=x;
		x=x1;
		x1=-y1;
		y1=x;
	}
/*--------------------------------------------------------------------------*/
	/*��4��DDA�㷨����*/
	m=(float)(y1-y0)/(float)(x1-x0);
	for(x=x0,y=(float)y0;x<=x1;x++,y=y+m){
		if(flag==1)DCPoint->SetPixel(x,int(y),RGB(0,0,255));//��׼��
		//���׼��
		if(flag==2)DCPoint->SetPixel(x,-int(y),RGB(0,0,255));//��yȡ��
		if(flag==3)DCPoint->SetPixel(int(y),x,RGB(0,0,255));//��xy�Ե�
		if(flag==4)DCPoint->SetPixel(int(y),-x,RGB(0,0,255));//��xy�Ե�yȡ��
	}
}
void CMy1504060127Doc::MIDLine(CClientDC*DCPoint){
	/*�е㻭�ߺ���*/
	//��1����������
	int x0,y0,x1,y1,flag;
	int a, b, d1, d2, d, x, y;
	//��2��׼�������õ�����
	DCPoint->SetROP2(R2_COPYPEN);
	x0=group[0].x;    y0=group[0].y;
	x1=group[1].x;    y1=group[1].y;
	//��3��������������໭�����߱�׼��
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
	//��4���е㻭�ߺ����㷨
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
	/*Bresenham���ߺ���*/
	//��1����������
	int x0,y0,x1,y1,flag;
	int x,y,dx,dy,e;//�������Ƶ����꣬����仯�������������б�ֵ
	//��2��׼�������õ�����
	DCPoint->SetROP2(R2_COPYPEN);
	x0=group[0].x;    y0=group[0].y;
	x1=group[1].x;    y1=group[1].y;
	//��3��������������໭�����߱�׼��
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
	//��4��Bresenham���ߺ����㷨
	dx=x1-x0;		//����x�仯����ֵ��dx
	dy=y1-y0;		//����y�仯����ֵ��dy
	e=-dx;			//�������������б�ֵ��ʼֵΪ-dx
	x=x0;			//��x0ֵ������ǰ���Ƶ��x
	y=y0;			//��y0ֵ������ǰ���Ƶ��y
	for(int i=0;i<=dx;i++){//��iС��x�仯��ʱִ��
		if(flag==1)DCPoint->SetPixel(x,int(y),RGB(255,0,0));
	    if(flag==2)DCPoint->SetPixel(x,-int(y),RGB(255,0,0));
		if(flag==3)DCPoint->SetPixel(int(y),x,RGB(255,0,0));
		if(flag==4)DCPoint->SetPixel(int(y),-x,RGB(255,0,0));
		x=x+1;			//xֵ��1�����¸���x(����������)
		e=e+2*dy;		//���������б�ֵ��2��dy�����¸�ֵ�����������б�ֵ
		if(e>=0){//������������б�ֵ�Ǹ���ִ��
			y=y+1;		//yֵ��һ�����¸���y(����������)
			e=e-2*dx;   //���������б�ֵ��2��dx�����¸�ֵ�����������б�ֵ
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
// CMy1504060127Doc commands
