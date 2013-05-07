/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-09-15 21:29
 * Filename : POJ3259 Wormholes.cpp
 * Description : 
 * *****************************************************************************/
// POJ3259 Wormholes.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG

#include <stdio.h>
#include <string.h>
#include <string>
#include <memory.h>
#include <queue>
using namespace std;

#define MAX 510
#define maxint 1<<30
#define minint -maxint

struct NODE
{
	int to,len;
	struct NODE *next;
}node[30000],*p[MAX];
int ncount,path[MAX],visit[MAX],times[MAX];
queue<int> myqueue;

bool spfa(int n)
{
	NODE *head[MAX];
	memset(visit,0,sizeof(visit));
	memset(times,0,sizeof(times));
	while(!myqueue.empty()) myqueue.pop();
	for(int i=1;i<=n;++i)
		path[i]=maxint;
	path[1]=0;
	myqueue.push(1);
	visit[1]=1;
	++times[1];
	while(!myqueue.empty())
	{
		int x=myqueue.front();
		myqueue.pop();
		visit[x]=0;
		head[x]=p[x];
		while(head[x])
		{
			int to=head[x]->to;
			int len=head[x]->len;
			if(path[to]-path[x]>len)
			{
				path[to]=path[x]+len;
				if(!visit[to])
				{
					myqueue.push(to);
					visit[to]=1;
					++times[to];
					if(times[to]>n)
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
	int ncases,n,m,w;
	int a,b,len;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d %d %d",&n,&m,&w);
		memset(p,'\0',sizeof(p));
		ncount=0;

		for(int i=0;i<m;++i)
		{
			scanf("%d %d %d",&a,&b,&len);
			node[ncount].to=b;
			node[ncount].len=len;
			node[ncount].next=p[a];
			p[a]=&node[ncount++];


			node[ncount].to=a;
			node[ncount].len=len;
			node[ncount].next=p[b];
			p[b]=&node[ncount++];
		}
		for(int i=0;i<w;++i)
		{
			scanf("%d %d %d",&a,&b,&len);
			node[ncount].to=b;
			node[ncount].len=-len;
			node[ncount].next=p[a];
			p[a]=&node[ncount++];
		}

		bool result=spfa(n);
		if(result)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
