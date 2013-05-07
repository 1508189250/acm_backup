// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#define MAX 1020
#define EPS 1e-10
using namespace std;

const double PI=3.14159265;

struct POINT
{
	double x,y;
}point[MAX];

double inline Distance(const POINT &lhs,const POINT &rhs)
{
	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	
//向量ac在ab的方向
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

bool inline _less(const double &lhs,const double &rhs)
{
	return lhs < rhs - EPS;  
}
bool inline _less_or_equal(const double &lhs,const double &rhs)
{
	return lhs < rhs + EPS;  
}
bool inline _equal(const double &lhs,const double &rhs)
{
	return fabs(lhs-rhs)< EPS;  
}

bool inline cmpByCoordinate(const POINT &lhs,const POINT &rhs)
{
	if(lhs.y != rhs.y)
		return lhs.y<rhs.y;
	else
		return lhs.x<rhs.x;
}

bool inline cmpByPolarAngle(const POINT &lhs,const POINT &rhs)
{
	double temp=crossProduct(point[0],lhs,rhs);
	if (fabs(temp)<EPS)
		return	Distance(lhs,point[0])<Distance(rhs,point[0]);
	else
		return temp<0;
}

double graham(const int &n)
{
	POINT *stk[MAX];

	sort(point,point+n,cmpByCoordinate);
	sort(point+1,point+n,cmpByPolarAngle);	//这样排序使得各点相对于point[0]成扇形分布

	for(int i=0;i<3;++i)
		stk[i]=&point[i];
	int top=2;

	for(int i=3;i<n;++i)
	{
		while(1)
		{
			POINT *a = stk[top];
			POINT *b = stk[top-1];
			if(crossProduct(*a,*b,point[i])<0)
				--top;
			else
				break;
		}
		stk[++top]=&point[i];
	}

	++top;
	double ans=0.0;
	for(int i=0;i<top;++i)
		ans+=stk[i]->x*stk[(i+1)%top]->y-stk[i]->y*stk[(i+1)%top]->x;
	return fabs(ans)/2.0;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n;

	while(~scanf("%d",&n) &&n)
	{
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&point[i].x,&point[i].y);
		if(n<3)
		{
			printf("0\n");
			continue;
		}

		double ans=graham(n);
		printf("%d\n",(int)ans/50);
	}

	return 0;
}
