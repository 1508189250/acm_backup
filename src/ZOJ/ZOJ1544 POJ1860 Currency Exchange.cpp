// ZOJ1544 POJ1860 Currency Exchange.cpp : Defines the entry point for the console application.
//

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
#include <queue>
#define MAX 20000
#define mindou 1e-5
#define maxint 1<<30
using namespace std;

struct NODE
{
	int to;
	double rate;
	double comm;
	struct NODE *next;
}node[MAX],*p[MAX];
int visit[MAX],times[MAX];
int ncount;
double dist[MAX],commission[110][110];
queue<int> myque;

void init(int n)
{
	memset(visit,0,sizeof(visit));
	memset(times,0,sizeof(times));
	memset(node,'\0',sizeof(node));
	memset(p,'\0',sizeof(p));
	for(int i=1;i<=n;++i)
	{
		dist[i]=0.0;
		for(int j=i+1;j<=n;++j)
			commission[i][j]=commission[j][i]=maxint;
		commission[i][i]=0.0;
	}
	ncount=0;
}

bool spfa(int source,double v,int n)
{
	NODE *head[MAX];
	myque.push(source);
	visit[source]=1;
	dist[source]=v;
	++times[source];
	while(!myque.empty())
	{
		int x=myque.front();
		myque.pop();
		head[x]=p[x];
		visit[x]=0;
		while(head[x])
		{
			int to=head[x]->to;
			if((dist[x]-head[x]->comm)*head[x]->rate-dist[to]>mindou)
			{
				dist[to]=(dist[x]-head[x]->comm)*head[x]->rate;
				if(!visit[to])
				{
					myque.push(to);
					visit[to]=1;
					++times[to];
					if(times[to]>=n)
						return true;
				}
			}
			head[x]=head[x]->next;
		}
	}
	return false;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,m,s;
	int a,b;
	double v,rab,cab,rba,cba;

	while(scanf("%d %d %d %lf",&n,&m,&s,&v)!=EOF)
	{
		init(n);
		for(int i=0;i<m;++i)
		{
			scanf("%d %d %lf %lf %lf %lf",&a,&b,&rab,&cab,&rba,&cba);
			node[ncount].to=b;
			node[ncount].rate=rab;
			node[ncount].comm=cab;
			node[ncount].next=p[a];
			p[a]=&node[ncount++];
			node[ncount].to=a;
			node[ncount].rate=rba;
			node[ncount].comm=cba;
			node[ncount].next=p[b];
			p[b]=&node[ncount++];
		}
		bool result=spfa(s,v,n);
		if(result) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
