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
#include <numeric>
#include <functional>
#define EPS 1e-6
using namespace std;

const double PI=acos(-1.0);
/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
  double x,y;
};
/************************************************************************/
/*double的大小判断                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

/************************************************************************/
/* 计算两点的距离                                                       */
/************************************************************************/
double inline Distance(const POINT &lhs,const POINT &rhs)
{
  return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

double inline Point2LineDistence(const double &x,const double &y,const double &a,const double &b,const double &c)
{
	return fabs((a*x+b*y+c)/sqrt(a*a+b*b));
}

double CircleIntersectCircle(const double &x0,const double &y0,const double &r0,const double &x,const double &y,const double &r)
{
	double dis=sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));
  if(_greater_or_equal(dis,r0+r))
		return 0.0;
  if(_less_or_equal(dis,r0-r))
		return PI*r*r;
  if(_less_or_equal(dis,r-r0))
		return PI*r0*r0;

  double cosa=(r0*r0+dis*dis-r*r)/(2.0*r0*dis);
  double alaph=acos(cosa);
  double area0=alaph*r0*r0;

  cosa = (r*r+dis*dis-r0*r0)/(2.0*r*dis);
  alaph=acos(cosa);
  double area1=alaph*r*r;
  double S=0.5*sqrt((r+r0+dis)*(r+r0-dis)*(r+dis-r0)*(r0+dis-r));
  return area0+area1-S;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	double xx,yy,rr,x,y,r,R;

	while(~scanf("%lf%lf%lf%lf%lf%lf%lf",&xx,&yy,&rr,&x,&y,&r,&R))
	{
		double temp=CircleIntersectCircle(xx,yy,rr,x,y,r);
		double tmp=CircleIntersectCircle(xx,yy,rr,x,y,R);
		printf("%.3lf\n",tmp-temp);
	}

  return 0;
}
