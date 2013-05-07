/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-09-25 01:42
 # Filename: ZOJ1979 POJ2553 The Bottom of a Graph.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <stack>
#include <algorithm>
#define MAX 5010

using namespace std;
struct NODE 
{
	int to;
	NODE *next;
}*v[MAX],node[MAX*5];
int n,e;
stack<int> mstack;
int inStack[MAX],dfn[MAX],low[MAX],whichComponent[MAX];
int dag_out[MAX];
int ind,componentNum,nodeind;

void init(void)
{
	ind=0;
	componentNum=0;
	nodeind=0;
	memset(v,'\0',sizeof(v));
	memset(inStack,0,sizeof(inStack));
	memset(dfn,-1,sizeof(dfn));
	memset(low,-1,sizeof(low));
	memset(whichComponent,0,sizeof(whichComponent));
	memset(dag_out,0,sizeof(dag_out));
	while(!mstack.empty())mstack.pop();
}

void input(void)
{
	int from,to;
	for(int i=0;i<e;++i)
	{
		scanf("%d %d",&from,&to);
		node[nodeind].to=to;
		node[nodeind].next=v[from];
		v[from]=&node[nodeind++];
	}
}

void tarjan(int i)
{
	int to;
	dfn[i]=low[i]=ind++;
	inStack[i]=1;
	mstack.push(i);
	NODE *head=v[i];
	while(head)
	{
		to=head->to;
		if(dfn[to]==-1)
		{
			tarjan(to);
			low[i]=min(low[i],low[to]);
		}
		else if(inStack[to])
		{
			low[i]=min(low[i],dfn[to]);
		}
		head=head->next;
	}
	if(dfn[i]==low[i])
	{
		do{
			to=mstack.top();
			inStack[to]=0;
			mstack.pop();
			whichComponent[to]=componentNum;
		}while(i!=to);
		++componentNum;
	}
}

void solve(void)
{
	for(int i=1;i<=n;++i)
		if(dfn[i]==-1)
			tarjan(i);
	for(int i=1;i<=n;++i)
	{
		NODE *head=v[i];
		while(head)
		{
			if(whichComponent[i]!=whichComponent[head->to])
				++dag_out[whichComponent[i]];
			head=head->next;
		}
	}
	int flag=1;
	for (int i=1;i<=n;++i)
		if (!dag_out[whichComponent[i]])
		{
			if(flag)
				flag=0;
			else
				printf(" ");
			printf("%d",i);
		}
	printf("\n");
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	while(scanf("%d",&n)&&n)
	{
		init();
		scanf("%d",&e);
		input();
		solve();
	}
	return 0;
}
