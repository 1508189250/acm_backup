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

const double PI = acos(-1.0);

// 点的定义
struct POINT
{
  double x,y;
}point[MAX];

// double的大小判断
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

// 两直线的交点
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

// 获取三角形外心算法 
POINT circumCenter(const POINT &pa,const POINT &pb, const POINT &pc)
{
  POINT a,b,c,d;
  a.x=(pa.x+pb.x)/2;	//根据k1=-1/k2获取ab的中垂线,其中k为斜率
  a.y=(pa.y+pb.y)/2;
  b.x=a.x-pa.y+pb.y;
  b.y=a.y+pa.x-pb.x;

  c.x=(pa.x+pc.x)/2;
  c.y=(pa.y+pc.y)/2;
  d.x=c.x-pa.y+pc.y;
  d.y=c.y+pa.x-pc.x;

  return intersectPoint(a,b,c,d);
}

// 点p绕origin旋转angle度后的左边ans
void PointRotation(const POINT &origin,const POINT &p,const double &angle, POINT &ans)
{
	ans.x=origin.x + (p.x-origin.x)*cos(angle) - (p.y-origin.y)*sin(angle);
	ans.y=origin.y + (p.y-origin.y)*cos(angle) + (p.x-origin.x)*sin(angle);
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

  POINT pa,pb,pc;
  int n,n_case=1;

  while(~scanf("%d",&n)&&n)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&pa.x,&pa.y,&pb.x,&pb.y,&pc.x,&pc.y);
		POINT center = circumCenter(pa,pb,pc);
		double alaph = 2*PI/n;

		POINT pre=pa,now;
		double min_x=pa.x,max_x=pa.x,min_y=pa.y,max_y=pa.y;
		for(int i=1;i<n;++i)
		{
			PointRotation(center,pre,i*alaph,now);
			min_x=min(min_x,now.x);
			max_x=max(max_x,now.x);
			min_y=min(min_y,now.y);
			max_y=max(max_y,now.y);
		}
		printf("Polygon %d: %.3lf\n",n_case++,(max_x-min_x)*(max_y-min_y));

	}
  return 0;
}
