// ZOJ2966 Build The Electric System.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 502
#define INF 1<<30

int map[N][N];
int pre[N],n,e;

struct node
{
	int x,y,len;
}city[N*N];

int input()
{
	scanf("%d %d",&n,&e);
	for(int i=0;i<e;++i)
		scanf("%d %d %d",&city[i].x,&city[i].y,&city[i].len);
	return n;
}

int find(int x)
{
	while(x!=pre[x])
		x=pre[x];
	return x;
}

int cmp(const node &lhs,const node &rhs)
{
	return lhs.len<rhs.len?1:0;
}

void kruskal()
{
	int a,b;
	int sum=0;
	for(int i=0;i<n;++i)
		pre[i]=i;
	sort(city,city+e,cmp);

	for(int i=0;i<e;++i)
	{
		a=find(city[i].x);
		b=find(city[i].y);
		if(a!=b)
		{
			sum+=city[i].len;
			pre[a]=b;
		}
	}
	printf("%d\n",sum);
}

void prim()
{
	int a,b,len;
	int dij[N],visit[N];
	scanf("%d %d",&n,&e);

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			map[i][j]=INF;
		map[i][i]=INF;
		dij[i]=INF;
		visit[i]=0;
	}
	int now=0;
	dij[0]=0;
	visit[0]=1;

	for(int i=0;i<e;++i)
	{
		scanf("%d %d %d",&a,&b,&len);
		map[a][b]=map[b][a]=len;
	}


	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			if(!visit[j] && dij[j]>map[now][j])
				dij[j]=map[now][j];
		int min=INF;
		for(int j=0;j<n;++j)
			if(!visit[j] && min>dij[j])
				min=dij[now=j];
		visit[now]=1;
	}
	int sum=0;
	for(int i=0;i<n;++i)
		sum+=dij[i];
	printf("%d\n",sum);
}


int main(void)
{
	int ncase;
	scanf("%d",&ncase);

	while(ncase--)
	{
// 		prim();
		input();
		kruskal();
	}


	return 0;
}
