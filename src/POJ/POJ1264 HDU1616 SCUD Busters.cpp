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
#define MAX 120
#define EPS 1e-10
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT{  double x,y;};
struct LINE{  POINT a,b;};

/************************************************************************/
/*double的大小判断                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

double inline Distance(const POINT &lhs,const POINT &rhs)
{
  return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

POINT anchor;
bool inline cmpByPolarAngle(const POINT &lhs,const POINT &rhs)
{
  double temp=crossProduct(anchor,lhs,rhs);
  if (_equal(temp,0.0))
    return	_less(Distance(lhs,anchor),Distance(rhs,anchor));
  else
    return _less(temp,0.0);
}

class COUNTRY
{
public:
  int site;
  double area;
  POINT point[MAX];
  int stk[MAX];
  int top;


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

  bool inline Euqal_Point(const POINT & p1,const POINT & p2)  
  {  
    return(_equal(p1.x,p2.x) && _equal(p1.y,p2.y));  
  }  
  bool inPolygon(const POINT &p)
  {
    int sum=0;
    LINE tline;
    tline.a=p;
    tline.b.x=DBL_MAX;
    tline.b.y=p.y;
    for(int i=0;i<top;++i)
    {
      const POINT p1=point[stk[i]];
      const POINT p2=point[stk[(i+1)%top]];
      LINE side;
      side.a=p1;
      side.b=p2;

      if(PointOnSegment(p1,p2,p))
        return true;
      if(_equal(p1.y,p2.y))
        continue;
      if (segIntersect(side,tline))
      {
        ++sum;
      }
    }
    return sum%2;
  }

  void func(void)
  {
    int temp=0;
    for (int i=1;i<site;++i)
      if(_less(point[i].x,point[temp].x) || (_equal(point[i].x,point[temp].x) && _less(point[i].y,point[temp].y)))
        temp=i;
    swap(point[temp],point[0]);

    anchor = point[0];
    sort(point+1,point+site,cmpByPolarAngle);	//这样排序使得各点相对于point[0]成扇形分布
    stk[0]=0;
    stk[1]=1;
    top=1;
    for(int i=2;i<site;++i)
    {
      while(top!=0)
      {
        POINT *a = &point[stk[top]];
        POINT *b = &point[stk[top-1]];
        if(_less_or_equal(crossProduct(*a,*b,point[i]),0.0))
          --top;
        else
          break;
      }
      stk[++top]=i;
    }
    ++top;

    area = 0.0;
    for(int i=0;i<top;++i)
    {
      area +=point[stk[i]].x*point[stk[(i+1)%top]].y - point[stk[i]].y * point[stk[(i+1)%top]].x;
    }
    area=fabs(area)/2;
  }
}countries[MAX];


int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n_temp,n_count;
	bool attacked[MAX];

	n_count=0;
	while(scanf("%d",&n_temp) && n_temp>=0)
	{
		countries[n_count].site=n_temp;
		for(int i=0;i<n_temp;++i)
			scanf("%lf%lf",&countries[n_count].point[i].x,&countries[n_count].point[i].y);
    countries[n_count].func();
    ++n_count;
	}

	double ans=0.0;
	POINT p;
	memset(attacked,false,sizeof(attacked));
	
	while(~scanf("%lf %lf",&p.x,&p.y))
	{
		for(int i=0;i<n_count;++i)
			if(!attacked[i] && countries[i].inPolygon(p))
			{
        attacked[i]=true;
				ans+=countries[i].area;
        break;
			}
	}

	printf("%.2lf\n",ans);

  return 0;
}
