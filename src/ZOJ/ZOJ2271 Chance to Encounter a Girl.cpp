/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-30 19:19
 # Filename: ZOJ2271 Chance to Encounter a Girl.cpp
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
#define	MAX 120
using namespace std;

double dp[MAX][MAX],pre[MAX][MAX];

int check(const int &x,const int &y,const int &n)
{
	int ans=0;
	if(x+1<n)
		++ans;
	if(x>0)
		++ans;
	if(y+1<n)
		++ans;
	if(y>0)
		++ans;
	return ans;
}

void travel(const int &n)
{
	memset(dp,0.0,sizeof(dp));
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(pre[i][j]>0.0)
		{
			double temp=pre[i][j]/check(i,j,n);
			if(i+1<n)
				dp[i+1][j]+=temp;
			if(i>0)
				dp[i-1][j]+=temp;
			if(j+1<n)
				dp[i][j+1]+=temp;
			if(j>0)
				dp[i][j-1]+=temp;
		}
	memcpy(pre,dp,sizeof(dp));
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
		memset(pre,0.0,sizeof(pre));
		pre[n/2][n/2]=1;

		double ans=0.0;
		for(int i=0;i<n;++i)
		{
			travel(n);
			ans+=pre[i][n/2];
			pre[i][n/2]=0.0;
		}
		printf("%.4lf\n",ans);
	}

  return 0;
}
