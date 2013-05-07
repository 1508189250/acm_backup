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
#define MAX 1010
using namespace std;
struct POINT{
  int x,y;
}point[MAX];
// double的大小判断
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

// 点p绕origin旋转angle度后的左边ans
void PointRotation(const POINT &origin,const POINT &p,const double &angle, POINT &ans)
{
  ans.x=origin.x + (p.x-origin.x)*cos(angle) - (p.y-origin.y)*sin(angle);
  ans.y=origin.y + (p.y-origin.y)*cos(angle) + (p.x-origin.x)*sin(angle);
}


  bool CMP(const POINT &lhs,const POINT &rhs)
  {
//     if(_equal(lhs.x,rhs.x))
//       return _less(lhs.y,rhs.y);
//     else
//       return _less(lhs.x,rhs.x);
    if(lhs.x==rhs.x)
      return lhs.y<rhs.y;
    else
      return lhs.x<rhs.x;
  }

const double PI=acos(-1.0);
int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
  int n,block;
  POINT ptemp,ans1,ans2;
//   scanf("%d",&block);
  block=1;
  while(block--)
  {
  while(scanf("%d",&n)&&n)
  {
    for(int i=0;i<n;++i)
    {
      scanf("%d%d",&point[i].x,&point[i].y);
    }
    sort(point,point+n,CMP);
    int ans=0;
    for(int i=0;i <n;++i)
    {
      for(int j=i+1;j<n;++j)
      {
        ans1.y=point[i].x+point[i].y-point[j].x;
        ans1.x=point[i].x+point[j].y-point[i].y;
        ans2.x=point[j].x+point[j].y-point[i].y;
        ans2.y=point[j].y+point[i].x-point[j].x;

        if(!binary_search(point,point+n,ans1,CMP))
          continue;
        if (!binary_search(point,point+n,ans2,CMP))
        {
          continue;
        }
        ++ans;
      }
    }
    printf("%d\n",ans/2);
  }
  if(block)
    printf("\n");
  }

  return 0;
}