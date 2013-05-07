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
#define MAX 120
#define EPS 1e-10
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
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
/* 两直线是否平行                                                       */
/************************************************************************/
bool isParallel(const POINT &a,const POINT &b,const POINT &c,const POINT &d)
{
	return _equal((b.y-a.y)*(d.x-c.x),(d.y-c.y)*(b.x-a.x));
}

/************************************************************************/
/* 两直线是否共线                                                       */
/************************************************************************/
bool isColinear(const POINT &a,const POINT &b,const POINT &c,const POINT &d)
{
	return (_equal(crossProduct(a,b,c),0.00)
		&& _equal(crossProduct(a,b,d),0.00));
}

/************************************************************************/
/* 两直线的交点                                                         */
/************************************************************************/
POINT intersectPoint(const POINT &a,const POINT &b,const POINT &c,const POINT &d)
{
	POINT ans;
	if(_equal(a.y,b.y))
	{
		ans.y=a.y;
		double f=(d.x-c.x)/(d.y-c.y);
		ans.x=f*(ans.y-c.y)+c.x;
		return ans;
	}
	if (_equal(c.y,d.y))
	{
		ans.y=c.y;
		double e=(b.x-a.x)/(b.y-a.y);
		ans.x=e*(ans.y-a.y)+a.x;
		return ans;
	}
	double e=(b.x-a.x)/(b.y-a.y);
	double f=(d.x-c.x)/(d.y-c.y);
	ans.y = (e*a.y-a.x-f*c.y+c.x)/(e-f);
	ans.x = e*ans.y-e*a.y+a.x;
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n;
	POINT a,b,c,d;

	while(~scanf("%d",&n))
	{
		printf("INTERSECTING LINES OUTPUT\n");
		while(n--)
		{
			scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
			if(isColinear(a,b,c,d))
			{
				printf("LINE\n");
				continue;
			}
			if(isParallel(a,b,c,d))
			{
				printf("NONE\n");
				continue;
			}
			
			POINT ans=intersectPoint(a,b,c,d);
			printf("POINT %.2lf %.2lf\n",ans.x,ans.y);
		}
		printf("END OF OUTPUT\n");
	}

	return 0;
}
