/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-05 21:22
 # Filename: ZOJ2297 Survival.cpp
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
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 22
#define MAX_LEN 1<<22
using namespace std;

int consume[MAX],recovered[MAX],dp[MAX_LEN];

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
  int n;
  int orichi;

  while(~scanf("%d",&n))
  {
    --n;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;++i)
    {
      scanf("%d%d",&consume[i],&recovered[i]);
    }
    dp[0]=100;
    scanf("%d",&orichi);
    int max_len=1<<n;

    for(int j=0;j<max_len;++j)
      for(int i=0;i<n ;++i)
      {
        int temp=1<<i;
        if(!(j&temp))
          if(dp[j]-consume[i]>=0)
          {
            dp[j|temp]=max( dp[j|temp] , dp[j]-consume[i]+recovered[i]);
            dp[j|temp]=min(100,dp[j|temp]);
          }
      }
      if( dp[max_len-1]-orichi>=0)
        printf("clear!!!\n");
      else
        printf("try again\n");
  }

  return 0;
}
