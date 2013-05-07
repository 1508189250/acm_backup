#ifdef _MSC_VER
// #define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#define MAX 120
#define EPS 1e-6
using namespace std;

// 点的定义
struct POINT{
  double x,y;
  void get()
  {
    scanf("%lf%lf",&x,&y);
  }
};

// 两直线的交点
POINT intersectPoint(const POINT &a,const POINT &b,const POINT &c,const POINT &d)
{
  POINT ans;
  if(a.y==b.y)
  {
    ans.y=a.y;
    double f=(d.x-c.x)/(d.y-c.y);
    ans.x=f*(ans.y-c.y)+c.x;
    return ans;
  }
  if (c.y==d.y)
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

POINT func(const POINT &a,const POINT &b,const POINT &c)
{
  POINT ua,ub,va,vb;
  ua=c;
  ub.x=b.y-a.y+c.x;
  ub.y=c.y+a.x-b.x;
  va=b;
  vb.y=b.y-c.x+a.x;
  vb.x=c.y-a.y+b.x;
  return intersectPoint(ua,ub,va,vb);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int n;
  POINT a,b,c;
  scanf("%d",&n);

  while(n--)
  {
    a.get();
    b.get();
    c.get();

    POINT ans=func(a,b,c);
    if(fabs(ans.x)<EPS)
      ans.x=0.0;
    if(fabs(ans.y)<EPS)
      ans.y=0.0;
    printf("%.4lf %.4lf\n",ans.x,ans.y);
  }

  return 0;
}
