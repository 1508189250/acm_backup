// ZOJ1372 POJ1287 Networking.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <memory.h>

#define INF 1<<30

using namespace std;

int map[52][52];
int dij[52];

void input(int n,int m)
{
	int a,b,len;

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			map[i][j]=INF;
		map[i][i]=0;
		dij[i]=INF;
	}

	for(int i=0;i<m;++i)
	{
		cin>>a>>b>>len;
		if(len<map[a][b])
			map[a][b]=map[b][a]=len;
	}
}

int prim(int start,int n)
{
	int visit[52];
	memset(visit,0,sizeof(visit));
	int now(start);
	visit[now]=1;
	dij[now]=0;

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			if(!visit[j] && dij[j]>map[now][j])
				dij[j]=map[now][j];

		int min(INF);

		for(int j=1;j<=n;++j)
			if(!visit[j] && min>dij[j])
				min=dij[now=j];
		visit[now]=1;
	}

	int sum(0);
	for(int i=1;i<=n;++i)
		sum+=dij[i];
	return sum;
}



int main(void)
{
	int n,m;

	while(cin>>n &&n)
	{
		cin>>m;
		input(n,m);
		printf("%d\n",prim(1,n));
	}


	return 0;
}
