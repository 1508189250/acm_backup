/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-17 08:54
 # Filename: ZOJ3471 Most Powerful.cpp
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

using namespace std;

int map[15][15];
int dp[1<<11];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n;
	while(scanf("%d",&n)&&n)
	{
		int maxint=1<<n;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&map[i][j]);
		memset(dp,0,sizeof(dp));

		for(int i=0;i<maxint;++i)		//状态从0到2^n-1种
			for(int j=0;j<n;++j)
			{
				if(i & (1<<j)) continue;	//如果在状态i中第j个原子已消失，不计算
				for(int k=0;k<n;++k)
				{
					if(i & (1<<k)) continue;		//如果在状态i中第k个原子已消失，不计算
					if(j==k) continue;			//如果碰撞的两个原子相同，不计算
					dp[i | (1<<k)] = max(dp[i|(1<<k)],dp[i]+map[j][k]);	//状态转移方程
				}
			}
		int ans=0;
		for(int i=0;i<maxint;++i)
			if(dp[i]>ans)
				ans=dp[i];
		printf("%d\n",ans);
	}

	return 0;
}
