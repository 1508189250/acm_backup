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

// 点的定义
struct POINT
{
  double x,y;
};

// double的大小判断
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

// 计算向量ac在ab的方向的叉积
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

// 确定两条线段是否相交（含端点相交）
int   intersect(const POINT  &a,const POINT &b,const POINT &c,const POINT &d)  
{  
  return((max(a.x,b.x)>=min(c.x,d.x))&&  
    (max(c.x,d.x)>=min(a.x,b.x))&&  
    (max(a.y,b.y)>=min(c.y,d.y))&&  
    (max(c.y,d.y)>=min(a.y,b.y))&&  
    (crossProduct(a,b,c)*crossProduct(a,d,b)>=0)&&  
    (crossProduct(c,d,a)*crossProduct(c,b,d)>=0));  
} 
// 点c到线段ab的最短距离 
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

//圆与圆有交点
bool CircleTouchCircle(const POINT &lhs,const double &lr,const POINT &rhs,const double &rr)
{
	double len=Distance(lhs,rhs);
	if(_less_or_equal(len,lr+rr) && _less(fabs(lr-rr),len))
		return true;
	return false;
}

//方形与方形有交点
bool RectangleTouchRectangle(const POINT &lhs_tl,const POINT &lhs_rb,const POINT &rhs_tl,const POINT &rhs_rb)
{
	if(_less_or_equal(lhs_tl.x,rhs_tl.x))
	{
		if(_less(lhs_rb.x,rhs_tl.x)
				|| _less_or_equal(rhs_tl.x,lhs_rb.x)&&_less(rhs_tl.y,lhs_rb.y)
				|| _less_or_equal(rhs_tl.x,lhs_rb.x)&&_less(lhs_tl.y,rhs_rb.y)
				|| (_less_or_equal(lhs_tl.x,rhs_tl.x)&&_less_or_equal(rhs_tl.y,lhs_tl.y)
					&&_less_or_equal(rhs_rb.x,lhs_rb.x)&&_less_or_equal(lhs_rb.y,rhs_rb.y))
			)
			return false;
		else
			return true;
	}
	else
	{
		if(_less(rhs_rb.x,lhs_tl.x)
				|| _less_or_equal(lhs_tl.x,rhs_rb.x)&&_less(lhs_tl.y,rhs_rb.y)
				|| _less_or_equal(lhs_tl.x,rhs_rb.x)&&_less(rhs_tl.y,lhs_rb.y)
				|| (_less_or_equal(rhs_tl.x,lhs_tl.x)&&_less_or_equal(lhs_tl.y,rhs_tl.y)
					&&_less_or_equal(lhs_rb.x,rhs_rb.x)&&_less_or_equal(rhs_rb.y,lhs_rb.y))
			)
			return false;
		else
			return true;
	}
}
//圆与方形有交点
bool CircleTouchRectangle(const POINT &center,const double &radius,const POINT &top_left,const POINT &right_bottom)
{
	POINT top_right,left_bottom;
	top_right.y=top_left.y;
	top_right.x=right_bottom.x;
	left_bottom.x=top_left.x;
	left_bottom.y=right_bottom.y;
	if(_less_or_equal(GetDistance(right_bottom,top_right,center),radius))
		return true;
	if(_less_or_equal(GetDistance(right_bottom,left_bottom,center),radius))
		return true;
	if(_less_or_equal(GetDistance(left_bottom,top_left,center),radius))
		return true;
	if(_less_or_equal(GetDistance(top_left,top_right,center),radius))
		return true;
	return false;
}
int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n_cases;
	char str[10];
  bool ans;
	POINT top_left,right_bottom,center1,center2,top_left2,right_bottom2;
	double radius1,radius2;
	scanf("%d",&n_cases);
	while(n_cases--)
	{
		getchar();
		scanf("%s",str);
		if(str[0]=='c')
		{
			scanf("%lf%lf%lf",&radius1,&center1.x,&center1.y);
      scanf("%s",str);
      if(str[0]=='c')
      {
        scanf("%lf%lf%lf",&radius2,&center2.x,&center2.y);
        ans = CircleTouchCircle(center1,radius1,center2,radius2);
      }
      else
      {
        scanf("%lf%lf%lf%lf",&top_left.x,&top_left.y,&right_bottom.x,&right_bottom.y);
        ans = CircleTouchRectangle(center1,radius1,top_left,right_bottom);
      }

		}
		else
		{
			scanf("%lf%lf%lf%lf",&top_left.x,&top_left.y,&right_bottom.x,&right_bottom.y);
      scanf("%s",str);
      if(str[0]=='c')
      {
        scanf("%lf%lf%lf",&radius1,&center1.x,&center1.y);
        ans = CircleTouchRectangle(center1,radius1,top_left,right_bottom);
      }
      else
      {
        scanf("%lf%lf%lf%lf",&top_left2.x,&top_left2.y,&right_bottom2.x,&right_bottom2.y);
        ans = RectangleTouchRectangle(top_left,right_bottom,top_left2,right_bottom2);
      }
		}
    if(ans)
      printf("yes\n");
    else
      printf("no\n");
	}

  return 0;
}
