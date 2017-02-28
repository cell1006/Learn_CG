/* mid PointLine */
void Midpoint Line (int x0,int y0,int x1, int y1,int color){ 
	int a, b, d1, d2, d, x, y;
	a=y0-y1;
	b=x1-x0; 
	d=2*a+b;
	d1=2*a; 
	d2=2* (a+b);
	x=x0; 
	y=y0;
	drawpixel(x, y, color);
	while (x<x1){ 
		if (d<0) {
			x++£» 
			y++£» 
			d+=d2; 
		}else {
			x++£» 
			d+=d1;
		}

		drawpixel (x, y, color);
	} 
} 