/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-04 21:18
 # Filename: POJ1088 »¬Ñ©.cpp
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

int diff[]={-1,0,1,0,0,-1,0,1};
int height[MAX][MAX],dp[MAX][MAX];
struct NODE{int x,y,h;}node[MAX*MAX];

bool inline cmp(const NODE &lhs,const NODE &rhs)
{
	return lhs.h<rhs.h;
}

int main(void)
{
#ifdef DEBUG  
	freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
	freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int r,c;

	while(~scanf("%d%d",&r,&c))
	{
		memset(height,0,sizeof(height));
		for(int i=0;i<=r+1;++i)
			height[i][0]=height[i][c+1]=INT_MAX;
		for(int i=0;i<=c+1;++i)
			height[0][i]=height[r+1][i]=INT_MAX;
		memset(dp,0,sizeof(dp));

		int cnt=0;
		for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
			{
				scanf("%d",&height[i][j]);
				node[cnt].x=i;
				node[cnt].y=j;
				node[cnt++].h=height[i][j];
			}

		sort(node,node+cnt,cmp);
		for(int i=0;i<cnt;++i)
		{
			for(int j=0;j<8;j+=2)
			{
				int x=node[i].x+diff[j];
				int y=node[i].y+diff[j+1];
				if(height[x][y]<height[node[i].x][node[i].y])
					dp[node[i].x][node[i].y]=max(dp[node[i].x][node[i].y],dp[x][y]+1);
			}
		}
		int max_len=INT_MIN;
		for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
				max_len= max(max_len,dp[i][j]);

		printf("%d\n",max_len+1);

	}

	return 0;
}
