/*
	直线的扫描转换——Bresenham法
*/
Integer_Bresenham_Line(x0,y0,x1,y1,color)
int x0,y0,x1,y1,color;//声明已知点坐标，绘制颜色值
{
	int x,y,dx,dy,e;//声明绘制点坐标，坐标变化量，误差项符号判别值
	dx=x1-x0;		//计算x变化量赋值给dx
	dy=y1-y0;		//计算y变化量赋值给dy
	e=-dx;			//设置误差项符号判别值初始值为-dx
	x=x0;			//将x0值赋给当前绘制点的x
	y=y0;			//将y0值赋给当前绘制点的y
	for(i=0;i<=dx;i++){//当i小于x变化量时执行
		drawpixel(x,y,color);//调用drawpixel()绘制坐标为(x,y)的点
		x=x+1;			//x值加1后重新赋给x(列坐标右移)
		e=e+2*dy;		//误差项符号判别值加2倍dy后重新赋值给误差项符号判别值
		/*为什么是e=e+2dy？
			因为直线斜率0<k<1,所以当dx=dy(即-dx+2dy=dx)时满足约定行增(y+=1)条件？
							  所以至少执行两次列增(x+=1)才能执行一次行增(y+=1)？
		*/
		if(e>=0){//如果误差项符号判别值非负则执行
			y=y+1;		//y值加一后重新赋给y(行坐标上移)
			e=e-2*dx;   //误差项符号判别值减2倍dx后重新赋值给误差项符号判别值
		}
	}
}