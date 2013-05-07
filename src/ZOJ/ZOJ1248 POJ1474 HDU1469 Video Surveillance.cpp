/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-19 20:19
 # Filename: ZOJ1369 POJ1279 Art Gallery.cpp
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
#define EPS 1e-6
using namespace std;
const int MAXN=1510;
int n_point_count;
double r;
int n_e_cnt,n_t_cnt;//此时n_e_cnt为最终切割得到的多边形的顶点数、n_t_cnt暂存顶点个数
struct POINT{
    double x,y;
};
//读入的多边形的顶点（顺时针）、p为存放最终切割得到的多边形顶点的数组、q暂存核的顶点
POINT points[MAXN],p[MAXN],q[MAXN];

// 计算向量ac在ab的方向的叉积
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

// double的大小判断
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

void initial(){
    for(int i = 0; i < n_point_count; ++i)p[i] = points[i];
    p[n_point_count] = p[0];
    n_e_cnt = n_point_count;//n_e_cnt为最终切割得到的多边形的顶点数，将其初始化为多边形的顶点的个数
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
void cut(const POINT &lhs,const POINT &rhs){
  n_t_cnt = 0;
  for(int i = 0; i < n_e_cnt; ++i){
    if(_less_or_equal(crossProduct(lhs,rhs,p[i]),0.0))
      q[n_t_cnt++] = p[i];// c由于精度问题，可能会偏小，所以有些点本应在右侧而没在，
    //故应该接着判断

    if(_less(crossProduct(lhs,rhs,p[i])*crossProduct(lhs,rhs,p[i+1]),0.0)){//原理同上
      q[n_t_cnt++] = intersectPoint(lhs,rhs,p[i],p[i+1]);
    }
  }
  memcpy(p,q,sizeof(POINT)*n_t_cnt);
  p[n_t_cnt]=p[0];
  n_e_cnt = n_t_cnt;
}

//求多边形的面积, 输入逆时针的话返回正值，否则返回负值
double area(POINT *pArray,const int &n){
  double ans=0.0;
  for(int i=0;i<n;++i)
  {
    ans+=pArray[i].x*pArray[(i+1)%n].y-pArray[i].y*pArray[(i+1)%n].x;
  }
  return ans/2;
}
void ReversePoints(POINT *p,const int &n){
  //规整化方向，逆时针变顺时针，顺时针变逆时针
  for(int i=0; i<n/2; i++)  
    swap(p[i],p[n-i-1]);  
}

bool solve(){
  //注意：默认点是顺时针，如果题目不是顺时针，规整化方向
  double lf_area=area(points,n_point_count);
  if (_less_or_equal(lf_area,0.0))
  {
    ReversePoints(points,n_point_count);
  }

  initial();
  for(int i = 0; i < n_point_count; ++i){
    cut(points[i],points[(i+1)%n_point_count]);
  }
  /*
    如果要向内推进r，用该部分代替上个函数
    for(int i = 1; i <= n_point_count; ++i){
        Point ta, tb, tt;
        tt.x = points[i+1].y - points[i].y;
        tt.y = points[i].x - points[i+1].x;
        double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);
        tt.x = tt.x * k;
        tt.y = tt.y * k;
        ta.x = points[i].x + tt.x;
        ta.y = points[i].y + tt.y;
        tb.x = points[i+1].x + tt.x;
        tb.y = points[i+1].y + tt.y;
        double a,b,c;
        getline(ta,tb,a,b,c);
        cut(a,b,c);
    }*/

    return n_e_cnt;
}
int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
  int ncases=1;
  while(scanf("%d",&n_point_count) && n_point_count)
  {
    for (int i=0;i<n_point_count;++i)
    {
      scanf("%lf%lf",&points[i].x,&points[i].y);
    }
    printf("Floor #%d\n",ncases++);
    bool ans=solve();
    if (ans)
      printf("Surveillance is possible.\n\n");
    else
      printf("Surveillance is impossible.\n\n");

  }

  return 0;
}
