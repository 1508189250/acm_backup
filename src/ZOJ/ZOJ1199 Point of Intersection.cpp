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
#include <ctype.h>
#define MAX 120
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


// 计算两点的距离 
double inline Distance(const POINT &lhs,const POINT &rhs)
{
  return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

// 圆lhs在圆rhs中
bool inline CircleInCircle(const POINT &lhs,const double &lr,const POINT &rhs,const double &rr)
{
	if(_less_or_equal(Distance(lhs,rhs),fabs(lr-rr)))
		return true;
	else return false;
}

//圆与圆相交且不相切
bool inline CircleIntersectCircle(const POINT &lhs,const double &lr,const POINT &rhs,const double &rr)
{
  if(_less(Distance(lhs,rhs),(lr+rr)) && !CircleInCircle(lhs,lr,rhs,rr))
    return true;
  else return false;
}

//圆与圆外切或内切
bool inline CircleTangentCircle(const POINT &lhs,const double &lr,const POINT &rhs,const double &rr)
{
  if(_equal(Distance(lhs,rhs),(lr+rr)) || _equal(Distance(lhs,rhs),fabs(lr-rr)))
    return true;
  else return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n_cases;
	POINT p_a,p_b;
	double r_a,r_b;

	scanf("%d",&n_cases);

	while(n_cases--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&p_a.x,&p_a.y,&r_a,&p_b.x,&p_b.y,&r_b);
		if(CircleInCircle(p_a,r_a,p_b,r_b) || _equal(r_a,r_b))
		{
			printf("Impossible.\n");
			continue;
		}
		double dis=Distance(p_a,p_b);
		if(_less(r_a,r_b))
		{
			swap(r_a,r_b);
			swap(p_a,p_b);
		}
		double x=(p_a.x*r_b-p_b.x*r_a)/(r_b-r_a);
		double y=(p_a.y*r_b-p_b.y*r_a)/(r_b-r_a);
    printf("%.2lf %.2lf\n",x,_equal(y,0.0)?0.00:y);
	}

  return 0;
}
