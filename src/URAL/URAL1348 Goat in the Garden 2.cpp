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
#define EPS 1e-10
using namespace std;

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

/************************************************************************/
/* 点c到线段ab的最短距离                                                   */
/************************************************************************/
double GetDistance(const POINT &a,const POINT &b,const POINT &c)
{
	double x= Distance(a,c);
	if(_equal(x,0.0))
		return 0.0;

	double y = Distance(b,c);
	if(_equal(y,0.0))
		return 0.0;

	double z = Distance(a,b);
	if(_equal(z,0.0))
		return x;

	//如果是钝角
	if(_less_or_equal(y*y+z*z,x*x))
		return y;

	if(_less_or_equal(x*x+z*z,y*y))
		return x;

  //海伦公式
	double s=(x+y+z)/2;
	s=sqrt(s*(s-x)*(s-y)*(s-z));
	return 2*s/z;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
  POINT a,b,c;
  double len;

  while(~scanf("%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&len))
  {
    double temp = GetDistance(a,b,c);
    if(_less_or_equal(temp,len))
      printf("0.00\n");
    else
      printf("%.2lf\n",temp-len);

    temp = max(Distance(a,c),Distance(b,c));

    if(_less_or_equal(temp,len))
      printf("0.00\n");
    else
      printf("%.2lf\n",temp-len);

  }

  return 0;
}
