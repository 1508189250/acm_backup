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
int n_e_cnt,n_t_cnt;//��ʱn_e_cntΪ�����и�õ��Ķ���εĶ�������n_t_cnt�ݴ涥�����
struct POINT{
    double x,y;
};
//����Ķ���εĶ��㣨˳ʱ�룩��pΪ��������и�õ��Ķ���ζ�������顢q�ݴ�˵Ķ���
POINT points[MAXN],p[MAXN],q[MAXN];

// ��������ac��ab�ķ���Ĳ��
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

// double�Ĵ�С�ж�
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

void initial(){
    for(int i = 0; i < n_point_count; ++i)p[i] = points[i];
    p[n_point_count] = p[0];
    n_e_cnt = n_point_count;//n_e_cntΪ�����и�õ��Ķ���εĶ������������ʼ��Ϊ����εĶ���ĸ���
}
// ��ֱ�ߵĽ���
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
      q[n_t_cnt++] = p[i];// c���ھ������⣬���ܻ�ƫС��������Щ�㱾Ӧ���Ҳ��û�ڣ�
    //��Ӧ�ý����ж�

    if(_less(crossProduct(lhs,rhs,p[i])*crossProduct(lhs,rhs,p[i+1]),0.0)){//ԭ��ͬ��
      q[n_t_cnt++] = intersectPoint(lhs,rhs,p[i],p[i+1]);
    }
  }
  memcpy(p,q,sizeof(POINT)*n_t_cnt);
  p[n_t_cnt]=p[0];
  n_e_cnt = n_t_cnt;
}

//�����ε����, ������ʱ��Ļ�������ֵ�����򷵻ظ�ֵ
double area(POINT *pArray,const int &n){
  double ans=0.0;
  for(int i=0;i<n;++i)
  {
    ans+=pArray[i].x*pArray[(i+1)%n].y-pArray[i].y*pArray[(i+1)%n].x;
  }
  return ans/2;
}
void ReversePoints(POINT *p,const int &n){
  //������������ʱ���˳ʱ�룬˳ʱ�����ʱ��
  for(int i=0; i<n/2; i++)  
    swap(p[i],p[n-i-1]);  
}

bool solve(){
  //ע�⣺Ĭ�ϵ���˳ʱ�룬�����Ŀ����˳ʱ�룬����������
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
    ���Ҫ�����ƽ�r���øò��ִ����ϸ�����
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
