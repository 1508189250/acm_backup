/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-05 19:03
 # Filename: ZOJ1107 HDU1078 FatMouse and Cheese.cpp
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
#define	MAX 110
using namespace std;

int mat[MAX][MAX],dp[MAX][MAX];
int diff[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,k;

int func(const int &x,const int &y)
{
	if(dp[x][y]!=-1)
		return dp[x][y];
	int max_sum=0;
	for(int i=0;i<4;++i)
		for(int j=1;j<=k;++j)
		{
			int tx=x+j*diff[i][0];
			int ty=y+j*diff[i][1];
			if(tx>=0 && tx<n && ty>=0 && ty<n && mat[x][y]<mat[tx][ty]) //无需记录下一个点是否走过，因为题目要求下一个点的食物比当前点的食物多
				max_sum = max(max_sum,func(tx,ty));
		}
	dp[x][y]=max_sum+mat[x][y];
	return dp[x][y];
}


int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	while(scanf("%d%d",&n,&k) && !(n==-1 && k==-1))
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&mat[i][j]);
    memset(dp,-1,sizeof(dp));
		int ans=func(0,0);
		printf("%d\n",ans);
	}

  return 0;
}
