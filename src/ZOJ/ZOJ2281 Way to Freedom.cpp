// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <queue>
#define MAX 100010

using namespace std;
struct NODE
{
	int to,weight;
	NODE *next;
}*v[MAX],edge[20*MAX];
int visit[MAX],dist[MAX],edgeIndex,n,m;
priority_queue< pair<int,int> > myQueue;

void init()
{
	memset(v,'\0',sizeof(v));
	memset(visit,0,sizeof(visit));
	memset(dist,0,sizeof(dist));
	edgeIndex=0;
}

void build(int from, int to,int w)
{
	edge[edgeIndex].to=to;
	edge[edgeIndex].weight=w;
	edge[edgeIndex].next=v[from];
	v[from]=&edge[edgeIndex++];
}

int dijkstra(int from, int to)
{
	int now=from,num;
	visit[now]=1;
	dist[now]=1<<30;
	for(int i=1;i<n;++i)
	{
		NODE *head=v[now];
		while(head)
		{
			num=head->to;
			int len=min(dist[now],head->weight);
			if(dist[num]<len)
			{
				dist[num]=len;
				myQueue.push(make_pair(dist[num],num));
			}
			head=head->next;
		}
		pair<int,int> temp;
		while(!myQueue.empty())
		{			
			temp=myQueue.top();
			myQueue.pop();
			if(!visit[temp.second])
				break;
		}
		visit[temp.second]=1;
		now=temp.second;
	}
	while(!myQueue.empty())
		myQueue.pop();
	return
		dist[to];
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int from,to,len;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		init();
		for (int i=0;i<m;++i)
		{
			scanf("%d %d %d",&from,&to,&len);
			build(from,to,len);
			build(to,from,len);
		}
		scanf("%d %d",&from,&to);
		len=dijkstra(from,to);
		printf("%d\n",len);
	}

	return 0;
}
