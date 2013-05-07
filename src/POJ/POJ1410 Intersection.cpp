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
#include <float.h>
#define EPS 1e-10
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
  double x,y;
}point[5];

/************************************************************************/
/* 线段的定义                                                           */
/************************************************************************/
struct LINE{
  POINT a,b;
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
/* 计算向量ac在ab的方向的叉积                                           */
/************************************************************************/
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

/************************************************************************/
/* 确定两条线段是否相交（含端点相交）                                   */
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
/* 确定两条线段是否相交（含端点相交）                                   */
/************************************************************************/
int   intersect(const POINT  &a,const POINT &b,const POINT &c,const POINT &d)  
{  
  return((max(a.x,b.x)>=min(c.x,d.x))&&  
    (max(c.x,d.x)>=min(a.x,b.x))&&  
    (max(a.y,b.y)>=min(c.y,d.y))&&  
    (max(c.y,d.y)>=min(a.y,b.y))&&  
    (crossProduct(a,b,c)*crossProduct(a,d,b)>=0)&&  
    (crossProduct(c,d,a)*crossProduct(c,b,d)>=0));  
} 
/************************************************************************/
bool inline Euqal_Point(const POINT & p1,const POINT & p2)  
{  
  return(_equal(p1.x,p2.x) && _equal(p1.y,p2.y));  
} 
/************************************************************************/
/*一种线段相交判断函数，当且仅当u,v相交并且交点不是u,v的端点时函数为true*/
/************************************************************************/
bool segIntersect(const LINE & u,const LINE &v)  
{  
  return((intersect(u,v))&&  
    (!Euqal_Point(u.a,v.a))&&  
    (!Euqal_Point(u.a,v.b))&&  
    (!Euqal_Point(u.b,v.a))&&  
    (!Euqal_Point(u.b,v.b)));  
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

bool inPolygon(const POINT &p,const POINT *pArray,const int &n)
{
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

//     if(PointOnSegment(p1,p2,p))
//       return true;
    if(_equal(p1.y,p2.y))
      continue;

//     		int tmp=-1;
//      		if(PointOnSegment(tline.a,tline.b,p1))
//      			tmp=i;
//      		else if(PointOnSegment(tline.a,tline.b,p2))
//      			tmp=(i+1)%n;
//      
//      		if (tmp>-1 && _equal(pArray[tmp].y,max(pArray[i].y,pArray[i+1].y)))
//      		{
//      			++sum;
//      		}
//      		else if (tmp==-1 && segIntersect(side,tline))
//      		{
//      			++sum;
//      		}

    if (intersect(side,tline) && !PointOnSegment(tline.a,tline.b,p1))
    {
      ++sum;
    }

  }
  return sum%2;
}

bool func(const POINT *pArray,const POINT &start,const POINT &end)
{
	for(int i=0;i<4;++i)
		if(intersect(pArray[i],pArray[i+1],start,end))
			return true;
	if(inPolygon(start,pArray,4))
		return true;
	if(inPolygon(end,pArray,4))
		return true;
	return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

  POINT m,n;
  int n_count;
	scanf("%d",&n_count);
	while(n_count--)
	{
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&m.x,&m.y,&n.x,&n.y,&point[0].x,&point[0].y,&point[2].x,&point[2].y);
		point[1].x=point[0].x;
		point[1].y=point[2].y;
		point[3].x=point[2].x;
		point[3].y=point[0].y;
		point[4]=point[0];

    if(m.x>n.x || m.x==n.x && m.y>n.y)
      swap(m,n);
		if(func(point,m,n))
			printf("T\n");
		else
			printf("F\n");
	}

  return 0;
}
