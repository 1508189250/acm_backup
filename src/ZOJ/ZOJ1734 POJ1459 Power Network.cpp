/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-11 19:47
 # Filename: ZOJ1734 POJ1459 Power Network.cpp
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

#include <stack>
#include <queue>
#define MAX 120
using namespace std;

int cap[MAX][MAX];
int level[MAX];
queue<int> mque;
int source,target;

bool BFS()
{
	memset(level,-1,sizeof(level));
	level[source]=0;
	mque.push(source);
	while(!mque.empty())
	{
		int u=mque.front();
		mque.pop();
		for(int v=0;v<=target;++v)
			if(cap[u][v]>0 && level[v]==-1)
			{
				level[v]=level[u]+1;
				mque.push(v);
			}
	}
	return level[target]!=-1;
}

int dinic(int now,int sum)
{
	int i,a,os;
	if ( now == target)
		return sum;
	os = sum;
	for(i=0; i<=target && sum; i++)
		if( level[i]==level[now]+1 && cap[now][i] > 0 )
		{
			a = dinic( i, min(sum,cap[now][i]) );
			cap[now][i]-=a;
			cap[i][now]+=a;
			sum -= a;
		}
		return os-sum;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,np,nc,m;
	int from,to,len;
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
	{
		memset(cap,0,sizeof(cap));
		source=n+1;
		target=n+2;
		while(m--)
		{
			scanf(" (%d,%d)%d",&from,&to,&len);
			cap[from][to]=len;
		}
		while(np--)
		{
			scanf(" (%d)%d",&to,&len);
			cap[n+1][to]=len;
		}
		while(nc--)
		{
			scanf(" (%d)%d",&from,&len);
			cap[from][n+2]=len;
		}
		int ans=0;
		while(BFS())
			ans+=dinic(source,INT_MAX);
		printf("%d\n",ans);
	}

	return 0;
}
