#include "stdafx.h"
#define DEBUG

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
	int ind;
}point[MAX];

/************************************************************************/
/*double的大小判断                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

/************************************************************************/
/* 计算向量ac在ab的方向的叉积                                           */
/************************************************************************/
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

/************************************************************************/
/* 极角排序                                                                     */
/************************************************************************/
bool inline cmpByPolarAngle(const POINT &lhs,const POINT &rhs)
{
  double temp=crossProduct(point[0],lhs,rhs);
  return _less(temp,0.0);
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf",&point[i].x,&point[i].y);
			point[i].ind=i;
		}
		int ind=0;
		for(int i=0;i<n;++i)
			if(point[i].x<point[ind].x ||
					point[i].x==point[ind].x && point[i].y<point[ind].y)
				ind=i;
		swap(point[ind],point[0]);
		sort(point+1,point+n,cmpByPolarAngle);
		printf("%d %d\n",point[0].ind+1,point[n/2].ind+1);
	}

  return 0;
}
