/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-10 19:58
 # Filename: ZOJ2583 POJ2679 Adventurous Driving.cpp
 # Description : 
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
#include <queue>
#define MAX 1110
using namespace std;

struct NODE
{
	int v,cost,len;
	NODE *next;
}*apex[MAX],edge[MAX*10];

int cou,n;
int dist[MAX],cost[MAX],visit[MAX];
int ins[MAX],times[MAX],unusable[MAX];

void init()
{
	cou=0;
	memset(apex,'\0',sizeof(apex));
}

void addEdge(const int &u,const int &v,const int &fee,const int &len)
{
	if(!apex[u] || apex[u]->cost == fee)
	{
		edge[cou].v=v;
		edge[cou].cost=fee;
		edge[cou].len=len;
		edge[cou].next=apex[u];
		apex[u] = &edge[cou++];
	}
	else if(apex[u]->cost>fee)
	{
		apex[u]->cost = fee;
		apex[u]->len = len;
		apex[u]->v=v;
		apex[u]->next=NULL;
	}
}

bool dfs(const int &now,const int &end)
{
	if(now==end)
		return true;
	else
	{
		NODE *head=apex[now];
		int v;
		while(head)
		{
			v=head->v;
			if(!visit[v])
			{
				visit[v]=1;
				if(dfs(v,end))
					return true;
				visit[v]=0;
			}
			head=head->next;
		}
		return false;
	}
}

int SPFA(const int &s,const int &t)
{
	queue<int> mq;
	int u,v,fee,len;
	NODE *head;

	memset(ins,0,sizeof(ins));
	memset(times,0,sizeof(times));
	memset(unusable,0,sizeof(unusable));
	for(int i=0;i<n;++i)
		dist[i]=cost[i]=INT_MAX;

	dist[s]=cost[s]=0;
	ins[s]=1;
	times[s]=1;
	mq.push(s);

	while(!mq.empty())
	{
		u=mq.front();
		mq.pop();
		ins[u]=0;
		head=apex[u];
		
		while(head)
		{
			v=head->v;
			if( (cost[v]>cost[u]+head->cost || (cost[v]==cost[u]+head->cost && dist[v]>dist[u]+head->len)))
			{
				cost[v]=cost[u]+head->cost;
				dist[v]=dist[u]+head->len;
				
				if(!ins[v] )
				{
					if(++times[v] > n+5) return -1;
					mq.push(v);
					ins[v]=1;
				}
			}
			head=head->next;
		}
	}

		return 1;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int m,s,t,u,v,fuv,fvu,len;
	bool flag;
	char ch;

	while(~scanf("%d%d%d%d",&n,&m,&s,&t))
	{
		init();
		while(m--)
		{
			scanf(" (%d,%d,%d[%d]%d)",&u,&v,&fuv,&len,&fvu);
			addEdge(u,v,fuv,len);
			addEdge(v,u,fvu,len);
		}
		int ans=SPFA(s,t);
		if(cost[t]==INT_MAX)
			printf("VOID\n");
		else if(ans==1)
			printf("%d %d\n",cost[t],dist[t]);
		else
		{
			flag=false;
			for (int i=0;i<n;++i)
			{
				if(times[i]>n)
				{
					memset(visit,0,sizeof(visit));
					visit[i]=1;
					if(flag=dfs(i,t))
						break;
				}
			}
			if (flag || times[t]>n)printf("UNBOUND\n"); 
			else printf("%d %d\n",cost[t],dist[t]);
		}
	}

	return 0;
}