// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#define MAX 110

using namespace std;
int dist[MAX],visit[MAX],inTimes[MAX],energy[MAX];
int map[MAX][MAX];
queue<int> myqueue;
int ind,n;

void init()
{
	ind=0;
	for(int i=2;i<=n;++i)
		dist[i]=-(1<<30);
	memset(visit,0,sizeof(visit));
	memset(map,0,sizeof(map));
	memset(inTimes,0,sizeof(inTimes));
	while(!myqueue.empty()) myqueue.pop();
}
void input()
{
	int m,to;
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&energy[i],&m);
		while(m--)
		{
			scanf("%d",&to);
			map[i][to]=1;
		}
	}
}

int spfa()
{
	dist[1]=100;
	myqueue.push(1);
	visit[1]=1;
	inTimes[1]=1;
	while(!myqueue.empty())
	{
		int now=myqueue.front();
		myqueue.pop();
		visit[now]=0;
		if(inTimes[now]>n) break;	//如果一个节点入队大于n次，则存在负环
		for(int i=1;i<=n;++i)
		{
			if(map[now][i] && dist[i]<dist[now]+energy[i]&&dist[now]+energy[i]>0)
			{
				dist[i]=dist[now]+energy[i];
				if(!visit[i])
				{
					myqueue.push(i);
					++inTimes[i];
					visit[i]=1;
				}
			}
		}
	}
	if(dist[n]>0)
		return 1;
	else
	{
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					if(map[i][k] && map[k][j])
						map[i][j]=1;
		for(int i=1;i<=n;++i)
			if(inTimes[i]>n && map[1][i]&&map[i][n])	//如果一个节点入队n次，则这个节点在负环中，判断起止节点是否和这个节点连通就知道起止节点是否与这个负环连接
				return 1;
	}
	return 0;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	while(scanf("%d",&n)&&n>-1)
	{
		init();
		input();
		int ans=spfa();
		if(ans)
			printf("winnable\n");
		else
			printf("hopeless\n");
	}

	return 0;
}
