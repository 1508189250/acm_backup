/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-05-03 19:14
 # Filename: ZOJ3310 Unrequited Love.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
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
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 1000010
using namespace std;

int dp[MAX][2],value[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;

  while(~scanf("%d",&n) && n)
  {
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
      scanf("%d",&value[i]);

    //第一次dp，第一个mm收到情书
    dp[1][1]=value[1];
    for(int i=2;i<=n;++i)
    {
      dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
      dp[i][1]=dp[i-1][0]+value[i];
    }
    int ans=dp[n][0];

    //第二次dp，第一个mm没有收到情书
    memset(dp,0,sizeof(dp));
    for(int i=2;i<=n;++i)
    {
      dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
      dp[i][1]=dp[i-1][0]+value[i];
    }
    ans=max(ans,max(dp[n][0],dp[n][1]));

    printf("%d\n",ans);
  }

  return 0;
}
