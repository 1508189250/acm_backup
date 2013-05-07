/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-05 20:03
 # Filename: ZOJ2770 Burn the Linked Camp.cpp
 # Description : 
	差分约束，我们定义x[i]为第i个营的人数，定义dist[i]=x[0]+x[1]+...x[i],其中x[0]=0,则可知我们要求的为dist[n]。
	对于差分不等式，a - b <= c ，建一条 b 到 a 的权值为 c 的边，求的是最短路，得到的是最大值；对于不等式 a - b >= c ，建一条 b 到 a 的权值为 c 的边，求的是最长路，得到的是最小值。这题由于求最小值，所以我们用的是第二种。
	对于题目，我们可以有如下约束
	Ci有: x[i]=dist[i]-dist[i-1],则有dist[i]-dist[i-1]>=0,且dist[i-1]-dist[i]>=-Ci
	i,j,k有: s[j]-s[i-1]>=k
	还有: dist[i]>=0,即dist[i]-dist[0]>=0
	因为是求最小值，同时图的建立是按照小于等于进行，所以我们就要从负无穷约束到最小值，用SPFA求最长路即可。
	SPFA过程中判断是否有环。
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
#include <queue>
#define MAX 1010
using namespace std;

struct NODE{
	int to,len;
	NODE *next;
}node[MAX*MAX],*apex[MAX];

int nodeInd,dist[MAX],n,m;
void init()
{
	nodeInd=0;
	memset(apex,'\0',sizeof(apex));
}

void add(int u,int v,int len)
{
	node[nodeInd].to=v;
	node[nodeInd].len=len;
	node[nodeInd].next=apex[u];
	apex[u]=&node[nodeInd++];
}

int spfa()
{
	queue<int> myqueue;
	int inque[MAX],time[MAX];
	memset(inque,0,sizeof(inque));
	memset(time,0,sizeof(time));
	myqueue.push(0);
	time[0]=inque[0]=1;
	for (int i=1;i<=n;++i)
		dist[i]=INT_MIN;
	dist[0]=0;
	while(!myqueue.empty())
	{
		int x=myqueue.front();
		myqueue.pop();
		inque[x]=0;
		NODE *head=apex[x];
		while(head)
		{
			int to=head->to;
			int len=head->len;
			if(dist[to]<dist[x]+len)
			{
				dist[to]=dist[x]+len;
				if(inque[to]==0)
				{
					myqueue.push(to);
					inque[to]=1;
					if(++time[to]>n)
						return -1;
				}
			}
			head=head->next;
		}
	}
	return dist[n];
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int u,v,len;

	while(scanf("%d %d",&n,&m)!=EOF)
	{
		init();
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&len);
			add(i-1,i,0);
			add(i,i-1,-len);
			add(0,i,0);
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d %d %d",&u,&v,&len);
			add(u-1,v,len);
		}
		int ans=spfa();
		if(ans==-1)
			printf("Bad Estimations\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
