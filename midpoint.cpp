#include <iostream>
#include <stdio.h>
using namespace std;

void 	MLine1(int x1, int y1, int x2, int y2),
		MLine2(int x1, int y1, int x2, int y2),
		MLine3(int x1, int y1, int x2, int y2),
		MLine4(int x1, int y1, int x2, int y2);

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double m = (double)(y2 - y1) / (x2 - x1);
	if (m>0 && m<1) MLine1(x1,y1,x2,y2);
	if (m>1) MLine2(x1,y1,x2,y2);
	if (m<0 && m>-1) MLine3(x1,y1,x2,y2);
	if (m<-1) MLine4(x1,y1,x2,y2);
}

void MLine1(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt;
	
	dx=x2-x1; dy=y2-y1;
	p=dy-dx/2; pkt=dy;  pt=dy-dx;
	for (x=x1, y=y1; x<=x2; x++){
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "p = " << p << endl;
		if (p<0) p+=pkt;
		else {
			p+=pt;
			y++;
		}
	} 
}

void MLine2(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt;
	
	dx=x2-x1; dy=y2-y1;
	p=dx-dy/2; pkt=dx;  pt=dx-dy;
	for (x=x1, y=y1; y<=y2; y++){
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "p = " << p << endl;
		if (p<0) p+=pkt;
		else {
			p+=pt;
			x++;
		}
	} 
}

void MLine3(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pg, pkg;
	
	dx=x2-x1; dy=y2-y1;
	p=-dy-dx/2; pkg=-dy;  pg=-dy-dx;
	for (x=x1, y=y1; x<=x2; x++){
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "p = " << p << endl;
		if (p<0) p+=pkg;
		else {
			p+=pg;
			y--;
		}
	} 
}

void MLine4(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, p, pt, pkt;
	
	dx=x2-x1; dy=y2-y1;
	p=dx+dy/2; pkt=dx;  pt=dx+dy;
	for (x=x1, y=y1; y>=y2; y--){
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "p = " << p << endl;
		if (p<0) p+=pkt;
		else {
			p+=pt;
			x++;
		}
	} 
}