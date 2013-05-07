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

struct POINT
{
	double x,y;
}point[MAX];

/************************************************************************/
/* 计算向量ac在ab的方向的叉积                                           */
/************************************************************************/
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

/************************************************************************/
/*double的大小判断                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)
{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs){
	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs){	
	return fabs(lhs-rhs)< EPS;  }

/************************************************************************/
/* 确定两条线段是否相交（含端点相交）                                   */
/************************************************************************/
int intersect(const POINT  &a,const POINT &b,const POINT &c,const POINT &d)  
{  
	return((max(a.x,b.x)>=min(c.x,d.x))&&  
		(max(c.x,d.x)>=min(a.x,b.x))&&  
		(max(a.y,b.y)>=min(c.y,d.y))&&  
		(max(c.y,d.y)>=min(a.y,b.y))&&  
		(crossProduct(a,b,c)*crossProduct(a,d,b)>=0)&&  
		(crossProduct(c,d,a)*crossProduct(c,b,d)>=0));  
}

/************************************************************************/
/* 判断是否多边形                                                       */
/************************************************************************/
bool isPolygon(POINT *pArray,const int &n)
{
	if(n==1 || n==2)
		return false;

	for(int i=0;i<n;++i)
	{
		POINT *a=&pArray[i];
		POINT *b=&pArray[(i+1)%n];
		for(int j=i+2;j<n;++j)
		{
			if((j+1)%n==i)
				continue;
			POINT *c=&pArray[j];
			POINT *d=&pArray[(j+1)%n];
			if(intersect(*a,*b,*c,*d))
				return false;
		}
	}
	return true;
}

/************************************************************************/
/* 求多边形的面积                                                       */
/************************************************************************/
double area(POINT *pArray,const int &n)
{
	double ans=0.0;

	for(int i=0;i<n;++i)
	{
		ans+=pArray[i].x*pArray[(i+1)%n].y-pArray[i].y*pArray[(i+1)%n].x;
	}

	return fabs(ans)/2;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,ncases=1;

	while(scanf("%d",&n)&&n)
	{
		if(ncases>1)
			printf("\n");

		printf("Figure %d: ",ncases++);

		for(int i=0;i<n;++i)
			scanf("%lf%lf",&point[i].x,&point[i].y);

		if(!isPolygon(point,n))
		{
			printf("Impossible\n");
			continue;
		}

		printf("%.2lf\n",area(point,n));

	}

	return 0;
}
