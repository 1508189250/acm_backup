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
#define MAX 1010
using namespace std;

struct NODE
{
	int to,len;
	NODE *next;
}station[MAX*200],*apex[MAX];
int n,m,cou;

void init()
{
	memset(apex,'\0',sizeof(apex));
	cou=0;
}
void add(int u,int v,int len)
{
	station[cou].to=v;
	station[cou].len=len;
	station[cou].next=apex[u];
	apex[u]=&station[cou++];
}

int spfa()
{
	stack<int> mstack;
	int instack[MAX],times[MAX],dist[MAX];
	memset(instack,0,sizeof(instack));
	memset(times,0,sizeof(times));
	for(int i=0;i<=n;++i)
		dist[i]=INT_MIN;
	mstack.push(0);
	instack[0]=times[0]=1;
	dist[0]=0;
	while(!mstack.empty())
	{
		int x=mstack.top();
		mstack.pop();
		instack[x]=0;
		NODE *head=apex[x];
		while(head)
		{
			int to=head->to;
			int len=head->len;
			if(dist[to]<len+dist[x])
			{
				dist[to]=len+dist[x];
				if(!instack[to])
				{
					mstack.push(to);
					instack[to]=1;
					if(++times[to]>n)
						return -1;
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
	char ch;
	int a,b,len;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=0;i<m;++i)
		{
			getchar();
			scanf("%c %d %d",&ch,&a,&b);
			if(ch=='P')
			{
				scanf("%d",&len);
				add(b,a,len);
				add(a,b,-len);
			}
			else
				add(b,a,1);
		}
		for (int i=1;i<=n;++i)
		{
			add(0,i,0);
		}
		int ans=spfa();
		if(ans==1)
			printf("Reliable\n");
		else
			printf("Unreliable\n");
	}


	return 0;
}
