/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-17 19:59
 * Filename : ZOJ2059 The Twin Towers.cpp
 * Description : http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=2059
 * *****************************************************************************/
// ZOJ2059 The Twin Towers.cpp : Defines the entry point for the console application.
//
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#define MAX 2010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n,dp[MAX],pre[MAX];
	int x;

	while(scanf("%d",&n))
	{
    if(n<0)
      break;
		memset(dp,-1,sizeof(dp));
    memset(pre,-1,sizeof(pre));
		dp[0]=0;
    pre[0]=0;
    int sum=0;
		while(n--)
		{
			scanf("%d",&x);
			for(int i=0;i<=sum;++i)
			{
				if(pre[i]>=0)
				{
          //加在较高的塔上
					if(i+x<=MAX)
						dp[i+x]=max(pre[i+x],pre[i]);
          //加在较低的塔上，较低的塔仍然比较高的塔低
					if(x<i)
						dp[i-x]=max(pre[i]+x,dp[i-x]);
					else
						dp[x-i]=max(pre[i]+i,dp[x-i]);  //加在较低的塔上，变得比较高的塔高
				}
			}
      sum+=x;
			memcpy(pre,dp,sizeof(dp));
		}
		if(pre[0])
			printf("%d\n",pre[0]);
		else
			printf("Sorry\n");
	}
	return 0;
}
