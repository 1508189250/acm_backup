/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-15 20:06
 # Filename: ZOJ1450 Minimal Circle.cpp
 # Description : 
 ******************************************************************************/
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
#define EPS 1e-6
using namespace std;

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

// 计算向量ac在ab的方向的叉积
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

// 计算两点的距离
double inline Distance(const POINT &lhs,const POINT &rhs)
{
  return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}
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

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n;
	POINT center;
	double radius;
	while(scanf("%d",&n) && n)
	{
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&point[i].x,&point[i].y);
    random_shuffle(point,point+n);
		center=point[0];
		radius=0.0;
		
		for(int i=1;i<n;++i)
			if(_greater(Distance(center,point[i]),radius))
			{
				center=point[i];
				radius=0.0;
				for(int j=0;j<i;++j)
					if(_greater(Distance(center,point[j]),radius))
					{
						center.x=(point[i].x+point[j].x)/2;
						center.y=(point[i].y+point[j].y)/2;
						radius=Distance(center,point[j]);
						
						for(int k=0;k<j;++k)
							if(_greater(Distance(center,point[k]),radius))
							{
								center = circumCenter(point[i],point[j],point[k]);
                radius = Distance(center,point[k]);
							}
          }
			}
      printf("%.2lf %.2lf %.2lf\n",center.x,center.y,radius);
	}

  return 0;
}
