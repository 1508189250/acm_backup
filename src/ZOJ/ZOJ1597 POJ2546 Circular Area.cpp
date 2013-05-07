// ZOJ1597 POJ2546 Circular Area.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG


#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>

#define PI 3.14159265358

using namespace std;

double inline distence(double a,double b,double c,double d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

double inline angle(const double &a,const double &b,const double &c)
{
	return acos((b*b+c*c-a*a)/(2*b*c));
}

double func(double &x1,double &y1,double &r1,double &x2,double &y2,double &r2)
{
	if(r1<r2)
		swap(x1,x2),swap(y1,y2),swap(r1,r2);
	double dis=distence(x1,y1,x2,y2);
	if(dis<=r1-r2)
	{
		return PI*r2*r2;
	}
	else if(dis>r1-r2 && dis<r1)
	{
		double ang1=2*angle(r2,r1,dis);
		double ang2=2*angle(r1,r2,dis);
		double temp2=ang2*PI*r2*r2/(2*PI);
		temp2+=0.5*(r2*r2*sin((2*PI)-ang2));
		double temp1=ang1*r1*r1*PI/(2*PI);
		temp1-=0.5*(r1*r1*sin(ang1));
		return temp1+temp2;
	}

	else if(dis>=r1&&dis<=r1+r2)
	{
		double ang1=2*angle(r2,r1,dis);
		double ang2=2*angle(r1,r2,dis);
		double temp=0.5*(r1*r1*sin(ang1)+r2*r2*sin(ang2));
		return (ang1*r1*r1+ang2*r2*r2)*PI/(2*PI)-temp;
	}
	else
		return 0;
}
int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	double x1,y1,r1,x2,y2,r2;

	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2)!=EOF)
	{
		printf("%0.3f\n",func(x1,y1,r1,x2,y2,r2));
	}

	return 0;
}
