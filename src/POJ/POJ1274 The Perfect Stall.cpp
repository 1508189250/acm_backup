/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-24 19:24
 # Filename: POJ1274 The Perfect Stall.cpp
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
#define MAX 410
using namespace std;

int map[MAX][MAX];		//邻接矩阵
int used[MAX];				//在每次找增广路径中用于记录当前节点是否在增广路径中
int link[MAX];				//各个节点对应的匹配项
int m,n;

bool find(const int &x)		//从x开始是否有增广路
{
	int i;
	for(i=n+1;i<=m+n;++i)
	{
		if(map[x][i] && !used[i])		//若x与i有边相连且i不在当前的增广路上
		{
			used[i]=1;
			if(!link[i] || find(link[i]))	//若i没有匹配项或从i的匹配项开始有增广路
			{
				link[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int num,to;
	while(~scanf("%d%d",&n,&m))
	{
		memset(map,0,sizeof(map));
		memset(link,0,sizeof(link));
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&num);
			for(int j=0;j<num;++j)
			{
				scanf("%d",&to);
				map[i][n+to]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n+m;++i)
		{
			memset(used,0,sizeof(used));
			if(find(i)) ++ans;
		}
		printf("%d\n",ans);
	}

	return 0;
}
