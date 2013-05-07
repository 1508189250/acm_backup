/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-30 20:53
 # Filename: ZOJ1525 POJ1422 HDU1151 Air Raid.cpp
 # Description : 有向图最小路径覆盖=|V| - 最大匹配数; 无向图最小路径覆盖=|V| - 最大匹配数/2
 ******************************************************************************/
#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 130
using namespace std;

int map[MAX][MAX],used[MAX],mat[MAX];
int n;

bool inline find(const int &x)
{
	for(int i=1;i<=n;++i)
		if(map[x][i] && !used[i])
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
	for(int i=1;i<=n;++i)
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
	int ncases;
	int u,v,m;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d%d",&n,&m);
		memset(map,0,sizeof(map));
		while(m--)
		{
			scanf("%d%d",&u,&v);
			map[u][v]=1;
		}
		int ans=n-hungary();
		printf("%d\n",ans);
	}

	return 0;
}
