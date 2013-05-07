/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-15 21:31
 # Filename: ZOJ1081 Points Within.cpp
 # Description : 
 ******************************************************************************/
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
#include <float.h>

#define MAX 110
#define EPS 1e-10
using namespace std;

struct POINT
{
	double x,y;
}point[MAX];

struct LINE{
	POINT a,b;
};

double inline Distance(const POINT &lhs,const POINT &rhs)
{	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));}

double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	
//向量ac在ab的方向
{	
	double ans=(c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
	return ans;
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

/************************************************************************/
/* 点c是否在点a与点b的线段上（包括端点）                                */
/************************************************************************/
bool PointOnSegment(const POINT &a,const POINT &b,const POINT &c)
{
	if(_equal(crossProduct(a,b,c),0.0) &&
			_less_or_equal(min(a.x,b.x),c.x) &&
			_less_or_equal(c.x,max(a.x,b.x)) &&
			_less_or_equal(min(a.y,b.y),c.y) &&
			_less_or_equal(c.y,max(a.y,b.y)))
		return true;
	else
		return false;
}

/************************************************************************/
/* 确定两条线段是否相交                                                 */
/************************************************************************/
int   intersect(const LINE  &lhs,const LINE &rhs)  
{  
	return((max(lhs.a.x,lhs.b.x)>=min(rhs.a.x,rhs.b.x))&&  
		(max(rhs.a.x,rhs.b.x)>=min(lhs.a.x,lhs.b.x))&&  
		(max(lhs.a.y,lhs.b.y)>=min(rhs.a.y,rhs.b.y))&&  
		(max(rhs.a.y,rhs.b.y)>=min(lhs.a.y,lhs.b.y))&&  
		(crossProduct(lhs.a,lhs.b,rhs.a)*crossProduct(lhs.a,rhs.b,lhs.b)>=0)&&  
		(crossProduct(rhs.a,rhs.b,lhs.a)*crossProduct(rhs.a,lhs.b,rhs.b)>=0));  
}  

/************************************************************************/
/* 判断两个点是否相等                                                   */
/************************************************************************/
bool inline Euqal_Point(const POINT & p1,const POINT & p2)  
{  
	return(_equal(p1.x,p2.x) && _equal(p1.y,p2.y));  
}  


bool inPolygon(const POINT &p,const POINT *pArray,const int &n)
{
	if(n==1)
		return(_equal(pArray[0].x,p.x)&&_equal(pArray[0].y,p.y));
	if(n==2)
		return PointOnSegment(pArray[0],pArray[1],p);

	int sum=0;
	LINE tline;
	tline.a=p;
	tline.b.x=DBL_MAX;
	tline.b.y=p.y;

	for(int i=0;i<n;++i)
	{
		const POINT p1=pArray[i];
		const POINT p2=pArray[(i+1)%n];
		LINE side;
		side.a=p1;
		side.b=p2;

		if(PointOnSegment(p1,p2,p))
			return true;
		if(_equal(p1.y,p2.y))
			continue;

// 		int tmp=-1;
// 		if(PointOnSegment(tline.a,tline.b,p1))
// 			tmp=i;
// 		else if(PointOnSegment(tline.a,tline.b,p2))
// 			tmp=(i+1)%n;
// 
// 		if (tmp>-1 && _equal(pArray[tmp].y,max(pArray[i].y,pArray[i+1].y)))
// 		{
// 			++sum;
// 		}
// 		else if (tmp==-1 && segIntersect(side,tline))
// 		{
// 			++sum;
// 		}

		if (intersect(side,tline))
		{
			++sum;
		}

	}
	return sum%2;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,m;
	int ncases=1,flag=1;
	POINT p;

	while(scanf("%d",&n) && n)
	{
		if (flag)
			flag=0;
		else
			printf("\n");

		scanf("%d",&m);
		printf("Problem %d:\n",ncases++);
		for (int i=0;i<n;++i)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
		}

		while(m--)
		{
			scanf("%lf%lf",&p.x,&p.y);
			if (inPolygon(p,point,n))
			{
				printf("Within\n");
			} 
			else
			{
				printf("Outside\n");
			}
		}
	}

	return 0;
}
