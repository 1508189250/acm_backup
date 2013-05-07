/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-19 18:57
 # Filename: ZOJ1377 POJ1228 Grandpa's Estate.cpp
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
#define MAX 1020
#define EPS 1e-6
using namespace std;

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

/************************************************************************/
/*double的大小判断                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_ou_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

bool inline cmpByCoordinate(const POINT &lhs,const POINT &rhs)
{
	if (_equal(lhs.y,rhs.y))
		return _less(lhs.x,rhs.x);
	else
		return _less(lhs.y,rhs.y);
}

bool inline cmpByPolarAngle(const POINT &lhs,const POINT &rhs)
{
	double temp=crossProduct(point[0],lhs,rhs);
	if (_equal(temp,0.0))
		return	_less(Distance(lhs,point[0]),Distance(rhs,point[0]));
	else
		return _less(temp,0.0);
}

/************************************************************************/
/* 点c是否在点a与点b的线段上（包括端点）                                */
/************************************************************************/
bool PointOnSegment(const POINT &a,const POINT &b,const POINT &c)
{
	double maxx = max(a.x,b.x);  
	double maxy = max(a.y,b.y);  
	double minx = min(a.x,b.x);  
	double miny = min(a.y,b.y);  
	if( _equal(crossProduct(a,b,c),0.0) && _greater(c.x,minx) && _less(c.x,maxx) && _greater(c.y,miny) && _less(c.y,maxy) )  
		return true;  
	return false;  
}


bool isPolygon(const int &n)
{
	for(int i=2;i<n;++i)
		if(!_equal(crossProduct(point[0],point[1],point[i]),0.0))
			return true;
	return false;
}

double graham(const int &n)
{
	POINT *stk[MAX];

	sort(point,point+n,cmpByCoordinate);
	sort(point+1,point+n,cmpByPolarAngle);	//这样排序使得各点相对于point[0]成扇形分布

	if (!_equal(crossProduct(point[0],point[1],point[2]),0.0))
	{
		return false;
	}
	for(int i=0;i<3;++i)
		stk[i]=&point[i];
	int top=2;

	for(int i=3;i<n;++i)
	{
		while(top!=0)
		{
			POINT *a = stk[top];
			POINT *b = stk[top-1];
			if(_less_or_equal(crossProduct(*a,*b,point[i]),0.0))
				--top;
			else
				break;
		}
		stk[++top]=&point[i];
	}

	++top;
	for(int i=0;i<top;++i)
	{
		bool flag=0;
		for(int k=0;k<n;++k)
			if(&point[k] != stk[i] && &point[k]!= stk[(i+1)%top])
				if(PointOnSegment(*stk[i],*stk[(i+1)%top],point[k]) || _equal(crossProduct(*stk[i],*stk[(i+1)%top],point[k]),0.0))
				{
					flag=1;
					break;
				}
		if(!flag)
			return false;
	}

	return true;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n;
	int ncases;

	scanf("%d",&ncases);


	while(ncases--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&point[i].x,&point[i].y);
		if(n<6)
		{
			printf("NO\n");
			continue;
		}
		if (!isPolygon(n))
		{
			printf("NO\n");
		}
		else if(graham(n))
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}
