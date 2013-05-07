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
#include <stack>
#include <queue>
#define MAX 20020
using namespace std;

struct EDGE
{
	int u,v,cap,next;
}edge[MAX*80];

int head[MAX],ecount,n,m;
int level[MAX];
queue<int> mqueue;

void init()
{
	memset(head,-1,sizeof(head));
	ecount=0;
}

void addEdge(const int &u,const int &v,const int &cap)
{
	edge[ecount].u=u;
	edge[ecount].v=v;
	edge[ecount].cap=cap;
	edge[ecount].next=head[u];
	head[u] = ecount++;

	edge[ecount].u=v;
	edge[ecount].v=u;
	edge[ecount].cap=0;
	edge[ecount].next=head[v];
	head[v] = ecount++;
}

bool BFS(const int &s,const int &t)
{
	int cap,v,u;
	memset(level,-1,sizeof(level));
	level[s]=0;
	mqueue.push(s);
	while(!mqueue.empty())
	{
		u=mqueue.front();
		mqueue.pop();
		int temp=head[u];
		while(temp !=-1)
		{
			cap = edge[temp].cap;
			v = edge[temp].v;
			if( cap>0 && level[v] ==-1)
			{
				mqueue.push(v);
				level[v] = level[u]+1;
			}
			temp = edge[temp].next;
		}
	}
	return level[t] != -1;
}

int que[MAX*10];
int dinic(const int &s,const int &t)
{
	int flow=0,ag,i,cur[MAX],pos,cap,v,u,tail;
	while(BFS(s,t))
	{
		u=s;
		tail=0;
		memcpy(cur,head,sizeof(head));
		while(cur[s]!=-1)
		{
			pos = cur[u];
			cap = edge[pos].cap;
			v = edge[pos].v;
			if(u != t && cur[u]!=-1 && cap>0 && level[u]!=-1 && level[u]+1 == level[v])
			{
				que[tail++]= cur[u];
				u = v;
			}
			else
				if(u==t)
				{
					ag = INT_MAX;
					for(i=tail-1;i>=0; --i)
						ag = min(ag,edge[que[i]].cap);
					flow+=ag;
					for(i = tail-1;i>=0;--i)
					{
						edge[que[i]].cap -= ag;
						edge[que[i]^1].cap +=ag;
						if(edge[que[i]].cap==0)
							tail = i;
					}
					u = edge[que[tail]].u;
				}
				else
				{
					while( tail>0 && u !=s && cur[u]==-1)
						u = edge[que[--tail]].u;
					cur[u] = edge[cur[u]].next;
				}
		}
	}
	return flow;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int u,v,cap,cap2;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&cap,&cap2);
			addEdge(0,i,cap);
			addEdge(i,n+1,cap2);
		}
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&cap);
			addEdge(u,v,cap);
			addEdge(v,u,cap);
		}
		int ans = dinic(0,n+1); 
		printf("%d\n",ans);
	}


	return 0;
}
