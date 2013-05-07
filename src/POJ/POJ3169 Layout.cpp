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
struct NODE
{
	int to,len;
	NODE *next;
}*apex[MAX],cows[21*MAX];

int n,ml,md,cowsInd;
int dist[MAX];

void init()
{

	memset(apex,'\0',sizeof(apex));
	memset(cows,'\0',sizeof(cows));
	cowsInd=0;
}

void add(int u,int v,int len)
{
	cows[cowsInd].to=v;
	cows[cowsInd].len=len;
	cows[cowsInd].next=apex[u];
	apex[u]=&cows[cowsInd++];
}

int spfa()
{
	queue<int> myqueue;
	int inque[MAX],time[MAX];
	memset(inque,0,sizeof(inque));
	memset(time,0,sizeof(time));	
	for(int i=0;i<=n;++i)
		dist[i]=INT_MAX;
	myqueue.push(1);
	dist[1]=0;
	inque[1]=time[1]=1;

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
			if(dist[to]>dist[x]+len)
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
	if(dist[n]==INT_MAX)
		return -2;
	else 
		return dist[n];
}
int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int a,b,len;
	while(scanf("%d %d %d",&n,&ml,&md)!=EOF)
	{
		init();
		for(int i=0;i<ml;++i)
		{
			scanf("%d%d%d",&a,&b,&len);
			add(a,b,len);
		}
		for(int i=0;i<md;++i)
		{
			scanf("%d%d%d",&a,&b,&len);
			add(b,a,-len);
		}
		for(int i=2;i<=n;++i)
			add(i,i-1,0);

		int ans=spfa();
		printf("%d\n",ans);
	}	

	return 0;
}
