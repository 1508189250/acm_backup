// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 510
using namespace std;

int map[MAX][MAX],mat[MAX],visit[MAX];
int n;

bool inline find(const int &x)
{
	for(int i=1;i<=n;++i)
		if(visit[i]==0 && map[x][i])
		{
			visit[i]=1;
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
	memset(mat,0,sizeof(mat));
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		memset(visit,0,sizeof(visit));
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
	int m;
	int u,v;

	while(scanf("%d%d",&n,&m) && n)
	{
		memset(map,0,sizeof(map));
		while(m--)
		{
			scanf("%d%d",&u,&v);
			map[u][v]=1;
		}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					if(map[i][k] && map[k][j])
						map[i][j]=1;
		int ans=hungary();
		printf("%d\n",n-ans);
	}

	return 0;
}
