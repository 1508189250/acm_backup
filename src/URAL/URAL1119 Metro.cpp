/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-03 20:20
 # Filename: URAL1119 Metro.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <float.h>
using namespace std;

struct QUARTER
{
  int x,y;
}quarters[110];

bool inline cmp(const QUARTER &lhs,const QUARTER &rhs)
{
  if(lhs.x==rhs.x)
    return lhs.y<rhs.y;
  else
    return lhs.x<rhs.x;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

  const double sqrt_2 = sqrt(2.0)*100.0;
  int n,m,k;
  double dp[1010],pre[1010];
  while(~scanf("%d %d",&n,&m))
  {
    scanf("%d",&k);
    for(int i=0;i<k;++i)
      scanf("%d%d",&quarters[i].x,&quarters[i].y);
    sort(quarters,quarters+k,cmp);

    int ind=0;
    for(int i=0;i<=m;++i)
      pre[i]=i*100.0;

    for(int i=1;i<=n;++i)
    {
     dp[0]=i*100; 
      for(int j=1;j<=m;++j)
        dp[j]=DBL_MAX;
      while(quarters[ind].x==i && ind<k)
      {
        dp[quarters[ind].y]=min(dp[quarters[ind].y-1]+100,min(pre[quarters[ind].y]+100.0,pre[quarters[ind].y-1]+sqrt_2));
        ++ind;
      }
      for(int i=1;i<=m;++i)
        dp[i]=min(dp[i-1]+100,min(dp[i],pre[i]+100.0));
      memcpy(pre,dp,sizeof(dp));
    }
    printf("%d\n",(int)(dp[m]+0.5));
  }

  return 0;
}
