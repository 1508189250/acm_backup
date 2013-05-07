/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-17 20:45
 # Filename: ZOJ2314 Reactor Cooling.cpp
 # Description : 
	这一条题其实就是要把每条边的下界消去，变成我们熟识的最大流模型，我引用一下下面这段话：
	总的来说就是新建一个原点汇点 s,t，对原来的每个点i，设m(i)=sum{b<j,i>}-sum{b<i,j>}其中b<>为流量下界，若m(i)>0，连一条<s,i>容量为m(i)的边；若m(i)<0，连一条<i,t>容量为|m(i)|的边。然后将原来边的容量变为c<i,j>-b<i,j>。求一次最大流。如果与s和t关联的边全部满流，则可行流存在，且每条边的流量为现在的流量+流量的下界。否则不存在可行流。
	总的来说，这就是要把下界剥离出来，变成从源点到各个点，和从各个点到汇点的流。而具体实现，就是建图的技巧了，我们可以看一下以下代码。
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

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>
#include <queue>
#define MAX 210
using namespace std;

int cap[MAX][MAX],flow[MAX][MAX];
int level[MAX];
int target,source,n;
queue<int> mque;

bool BFS()
{
	memset(level,-1,sizeof(level));
	level[source]=0;
	mque.push(source);

	while(!mque.empty())
	{
		int x=mque.front();
		mque.pop();
		for(int v=0;v<=target;++v)
		{
			if(cap[x][v]>flow[x][v] && level[v]==-1)
			{
				level[v]=level[x]+1;
				mque.push(v);
			}
		}
	}
	return level[target]!=-1;
}

int dinic(int now,int sum)
{
	int i,a,os;
	if(now==target)
		return sum;
	os = sum;
	for(int i=0; i<=target && sum; ++i)
		if(level[i]==level[now]+1 && cap[now][i]>flow[now][i])
		{
			a = dinic(i,min(sum,cap[now][i]-flow[now][i]));
			flow[now][i]+=a;
			flow[i][now]-=a;
			sum -=a;
		}
	return os-sum;
}

int from[MAX*MAX],to[MAX*MAX],down[MAX*MAX];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int m,ncases;
	int f,t,up;
	scanf("%d",&ncases);
	while(ncases--)
	{

		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));

		scanf("%d%d",&n,&m);
		source=0;
		target=n+1;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d%d",&from[i],&to[i],&down[i],&up);
			cap[from[i]][to[i]] += up-down[i];
			cap[0][to[i]] += down[i];				//请注意这三行，0到to[i]的流表示源点提供了每条流的下界
			cap[from[i]][n+1]+=down[i];			//from[i]到n+1的流表示汇点需要的每条流的下界
		}
		
		while(BFS())
			dinic(source,INT_MAX);

		int flag=1;
		for(int i=0;i<m;++i)
			if(cap[0][to[i]]!=flow[0][to[i]] || cap[from[i]][target]!=flow[from[i]][target])	//对于每一个顶点，如果他们不满载的话，就代表有流没有达到下界
			{
				flag=0;
				break;
			}
		if(flag)
		{
			printf("YES\n");
			for(int i=0;i<m;++i)
				printf("%d\n",flow[from[i]][to[i]]+down[i]);
		}
		else
			printf("NO\n");

	}

	return 0;
}
