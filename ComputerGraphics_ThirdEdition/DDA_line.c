/* 
	ֱ�ߵ�ɨ��ת��������ֵ΢�ַ�
	DDA ��Digital Differential Analyzer��
*/
/*ȡ������*/
inline int round(const float a){
	return int (a+0.5);//���������a��0.5��ȡ��
}
/*DDA���߷���*/
void lineDDA(int xa, int ya ,int xb, intyb){ 
	int dx=xb-xa,    //��x�仯����ֵ��dx
		dy=yb-ya,    //��y�仯����ֵ��dy
		steps,       //����ѭ��������������
		k;			 //����������
	float xIncrement,  //����x΢������
		  yIncrement,  //����y΢������
		  x=xa,			//��A��xֵintתfloat����x
		  y=ya;			//��A��yֵintתfloat����y
		  
	//�ж�x�仯������ֵ�Ƿ����y�仯������ֵ
	if(abs(dx)>abs(dy))
		//����ǣ���x�仯������ֵ����steps
		steps=abs(dx);  
	else 
		//���򣬽�y�仯������ֵ����steps
		steps=abs(dy);  
		
	xIncrement=dx/(float)steps; //����x΢��������x������
	yIncrement=dy/(float)steps; //����y΢��������y������
	
	setPixel(round(x),round(y)); //�����������
	
	//��������ʣ�µĵ�
	for(k=0;k<steps;k++){	//����������ֵС�ڲ���ʱִ��
		x+=xIncrement;      //��x��һ��x������ֵ��x
		y+=yIncrement;		//��y��һ��y������ֵ��y
		setPixel(round(x),round(y)); //���ƶ�Ӧ�㣨round(x),round(y)������
	}
}