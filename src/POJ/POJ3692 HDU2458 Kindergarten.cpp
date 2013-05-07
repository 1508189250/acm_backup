/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-28 08:47
 # Filename: POJ3692 HDU2458 Kindergarten.cpp
 # Description : 
	本题是要求图中的最大完全子图（最大团）中顶点的个数。由于原图的补图是一个二分图，其最大完全数等价于其补图的最大独立集中元素的个数，于是可以根据二分图的性质求出这个最大独立集。而普通图的最大团则是一个NP问题。

	定理：二分图最大独立集中元素个数=顶点数-二分图最大匹配数

	最大完全数：图中最大完全子图的顶点个数。

	独立集：图中任意两个顶点都不相连的顶点集合。
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
#define MAX 450
using namespace std;

int map[MAX][MAX];
int used[MAX],mat[MAX],g,b,n,m;

bool find(const int &x)
{
	for(int i=1;i<=b;++i)
		if(used[i]==0 && !map[x][i])		//由于是求补图，所以这里的map[x][i]要等于0
		{
			used[i]=1;
			if(mat[i]==0 || find(mat[i]))
			{
				mat[i]=x;
				return true;
			}
		}
	return false;
}

int hungary()
{
	int ans=0;
	memset(mat,0,sizeof(mat));
	for(int i=1;i<=g;++i)
	{
		memset(used,0,sizeof(used));
		if(find(i))
			++ans;
	}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int u,v;
	int ncases=1;
	while(scanf("%d%d%d",&g,&b,&m) && (g||b||m))
	{
		memset(map,0,sizeof(map));
		n=g+b;
		while(m--)
		{
			scanf("%d%d",&u,&v);
			map[u][v]=1;
		}
		int ans=hungary();
		printf("Case %d: %d\n",ncases++,n-ans);

	}

	return 0;
}
