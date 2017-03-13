/*中点法画圆*/
MidpointCircle()
int r,color;
{
	/*
		判别式：d=F(M)=F(xp+1,yp-0.5)
					  =(xp+1)^2+(yp-0.5)^2-R^2
				取点情况	  判别式增量
		d>=0:    取右下       F(xp+1,yp-0.5)-F(xp+2,yp-1.5)=2*(xp-yp)+5
		d<0:  	取右		  F(xp+1,yp-0.5)-F(xp+2,yp-0.5)=2*xp+3	
		从(0,R)画到(R/√2,R/√2)
	*/
	/*Version1.0
	int x,y;
	float d;
	x=0;
	y=r;
	d=1.25-r;       		//d0=F(1,R-0.5)=1+(R-0.5)^2-R^2=1.25-R
	drawpixel(x,y,color);
	while(x<y){
		if(d<0){            //d<0,取右面的点
			d+=2*x+3;       
			x++;
		}else{			    //d>=0,取右下方的点
			d+=2*(x-y)+5;
			x++;
			y--;
		}
		drawpixel(x,y,color);
	}*/
	/*Version2.0 用e=d-0.25代替d，d=1.25-r对应于e=1-r，则d<0对应于e<-0.25...
				 完全用整数实现的中点画圆算法
	int x,y,d;
	x=0;
	y=r;
	d=1-r;       		//d0=F(1,R-0.5)=1+(R-0.5)^2-R^2=1.25-R
	drawpixel(x,y,color);
	while(x<y){
		if(d<0){            //d<0,取右面的点
			d+=2*x+3;       
			x++;
		}else{			    //d>=0,取右下方的点
			d+=2*(x-y)+5;
			x++;
			y--;
		}
		drawpixel(x,y,color);
	}*/
	/*Version3.0 不包含乘法*/
	int x,y,dx,dy,d;
	x=0; y=r; 
	dx=3; dy=2-r-r; d=1-r;      /*代码调试，R=4 dx=3 dy=2-5-5=-8 d=1-5=-4*/
	drawpixel(x,y,color);       //(0,5)      
								/*------------while()-----------------------------------------------*/
	while(x<y){                 //0<5          1<5      2<5    	 3<5		    4<5 		False-->break;
		if(d<0){				//d=-4<0      -1<0               -1<0
			d+=dx;				//d=-4+3=-1   -1+3=2  			 -1+9=8
			dx+=2;				//dx=3+2=5    5+2=7				 9+2=11
			x++;                //x=0+1=1     1+1=2				 3+1=4
		}else{					//					   2>=0                     8>=0
			d+=(dx+dy);         //					   -8+7=-1					8+11-6=13
			dx+=2;              //					   7+2=9					11+2=13
			dy+=2;  		    //					   -8+2=-6					-6+2=-4
			x++; 				//					   2+1=3					4+1=5
			y--;				//					   5-1=4					4-1=3
		}
		drawpixel(x,y,color);  //(1,5)       (2,5)     (3,4)     (4,4)			(5,3)
	}
}/*MidpointCircle*/