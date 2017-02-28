/* 
	直线的扫描转换——数值微分法
	DDA （Digital Differential Analyzer）
*/
/*取整方法*/
inline int round(const float a){
	return int (a+0.5);//将传入参数a加0.5后取整
}
/*DDA画线方法*/
void lineDDA(int xa, int ya ,int xb, intyb){ 
	int dx=xb-xa,    //求x变化量赋值给dx
		dy=yb-ya,    //求y变化量赋值给dy
		steps,       //声明循环次数（步数）
		k;			 //声明计数器
	float xIncrement,  //声明x微分增量
		  yIncrement,  //声明y微分增量
		  x=xa,			//将A点x值int转float赋给x
		  y=ya;			//将A点y值int转float赋给y
		  
	//判断x变化量绝对值是否大于y变化量绝对值
	if(abs(dx)>abs(dy))
		//如果是，将x变化量绝对值赋给steps
		steps=abs(dx);  
	else 
		//否则，将y变化量绝对值赋给steps
		steps=abs(dy);  
		
	xIncrement=dx/(float)steps; //计算x微分增量（x步长）
	yIncrement=dy/(float)steps; //计算y微分增量（y步长）
	
	setPixel(round(x),round(y)); //绘制起点象素
	
	//迭代绘制剩下的点
	for(k=0;k<steps;k++){	//当计数器数值小于步数时执行
		x+=xIncrement;      //给x加一个x步长后赋值给x
		y+=yIncrement;		//给y加一个y步长后赋值给y
		setPixel(round(x),round(y)); //绘制对应点（round(x),round(y)）象素
	}
}