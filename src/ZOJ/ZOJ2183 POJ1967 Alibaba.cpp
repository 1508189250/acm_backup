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
#define MAX 10010
using namespace std;

int dis[MAX],dead[MAX];

int func(const int &x,const int &n)
{
  int ans=INT_MAX;
  int sum=0;
  bool flag=true;
  for(int i=x;i>=0;--i)
    if(dead[i]<=dis[x]-dis[i])
    {
      flag=false;
      break;
    }
    if(flag)
    {
      sum=2*(dis[x]-dis[0]);
      for(int i=x+1;i<n;++i)
        if(dead[i]<=sum+dis[i]-dis[x])
        {
          flag=false;
          break;
        }
    }
    if(flag)
      ans=min(ans,sum+dis[n-1]-dis[x]);
    sum=0;
    flag=true;
    for(int i=x;i<n;++i)
      if(dead[i]<=dis[i]-dis[x])
      {
        flag=false;
        break;
      }
    if(flag)
    {
      sum=2*(dis[n-1]-dis[x]);
      for(int i=x-1;i>=0;--i)
        if(dead[i]<=sum+dis[x]-dis[i])
        {
          flag=false;
          break;
        }
    }
    if(flag)
      ans=min(ans,sum+dis[x]-dis[0]);
    return ans;
}


int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
  int n;
  while(~scanf("%d",&n))
  {
    for(int i=0;i<n;++i)
      scanf("%d%d",&dis[i],&dead[i]);
    int ans=INT_MAX;
    for(int i=0;i<n;++i)
      ans=min(ans,func(i,n));
    if (ans==INT_MAX)
    {
      printf("No solution\n");
    } 
    else
    {
      printf("%d\n",ans);
    }
  }

  return 0;
}
