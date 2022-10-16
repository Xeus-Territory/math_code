#include <iostream>
#include <stdio.h>
using namespace std;

void BLine1(int x1, int y1, int x2, int y2),
	 BLine2(int x1, int y1, int x2, int y2),
	 BLine3(int x1, int y1, int x2, int y2),
	 BLine4(int x1, int y1, int x2, int y2); 

int main()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double m = (double)(y2 - y1) / (x2 - x1);
	if (m>0 && m<1) BLine1(x1,y1,x2,y2);
	if (m>1) BLine2(x1,y1,x2,y2);
	if (m<0 && m>-1) BLine3(x1,y1,x2,y2);
	if (m<-1) BLine4(x1,y1,x2,y2);
	return 0;
}

void BLine1(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, et, ekt;
	
	dx=x2-x1; dy=y2-y1;
	ekt=dy+dy; e=ekt-dx; et=e-dx;
	for (x=x1, y=y1; x<=x2; x++){
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "e = " << e << endl;
		if (e<0) e+=ekt;
		else {
			e+=et;
			y++;
		}
	} 
}

void BLine2(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, et, ekt;
	
	dx=x2-x1; dy=y2-y1; 
	e=2*dx-dy; ekt=2*dx;  et=2*dx-2*dy;
	for (x=x1, y=y1; y<=y2; y++){
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "e = " << e << endl;
		if (e<0) e+=ekt;
		else {
			e+=et;
			x++;
		}
	} 
}

void BLine3(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, eg, ekg;
	
	dx=x2-x1; dy=y2-y1;
	e=-2*dy-dx; ekg=-2*dy;  eg=-2*dy-2*dx;
	for (x=x1, y=y1; x<=x2; x++){
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "e = " << e << endl;
		if (e<0) e+=ekg;
		else {
			e+=eg;
			y--;
		}
	} 
}

void BLine4(int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, et, ekt;
	
	dx=x2-x1; dy=y2-y1;
	e=2*dx+dy; ekt=2*dx; et=2*dx+2*dy;
	for (x=x1, y=y1; y>=y2; y--){
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "e = " << e << endl;
		if (e<0) e+=ekt;
		else {
			e+=et;
			x++;
		}
	} 
}