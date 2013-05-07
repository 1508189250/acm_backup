/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-09-25 20:26
 # Filename: POJ1236 Network of Schools.cpp
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
#define MAX 110

using namespace std;
struct NODE
{
	int to;
	NODE *next;
}*adj[MAX],node[MAX*MAX];

int nodeIndex,n,ind,componentNum;
int dfn[MAX],low[MAX],inStack[MAX],dag_in[MAX],dag_out[MAX],whichComponent[MAX];
stack<int> mstack;

void init(void)
{
	nodeIndex=0;
	ind=0;
	componentNum=0;
	memset(dfn,-1,sizeof(dfn));
	memset(low,-1,sizeof(low));
	memset(dag_in,0,sizeof(dag_in));
	memset(dag_out,0,sizeof(dag_out));
	memset(whichComponent,0,sizeof(whichComponent));
	memset(inStack,0,sizeof(inStack));
	memset(adj,'\0',sizeof(adj));
}
void input()
{
	int to;
	for(int i=1;i<=n;++i)
	{
		while(scanf("%d",&to)&&to)
		{
			node[nodeIndex].to=to;
			node[nodeIndex].next=adj[i];
			adj[i]=&node[nodeIndex++];
		}
	}
}

void tarjan(int from)
{
	int to;
	dfn[from]=low[from]=ind++;
	mstack.push(from);
	inStack[from]=1;
	NODE *head=adj[from];
	while(head)
	{
		to=head->to;
		if(dfn[to]==-1)
		{
			tarjan(to);
			low[from]=min(low[from],low[to]);
		}
		else if(inStack[to])
			low[from]=min(dfn[to],low[from]);
		head=head->next;
	}
	if(dfn[from]==low[from])
	{
		do
		{
			to=mstack.top();
			mstack.pop();
			inStack[to]=0;
			whichComponent[to]=componentNum;
		}while(from!=to);
		++componentNum;
	}
}

void solve(void)
{
	int to;
	for(int i=1;i<=n;++i)
		if(dfn[i]==-1)
			tarjan(i);
	for(int i=1;i<=n;++i)
	{
		NODE *head=adj[i];
		while(head)
		{
			if(whichComponent[i]!=whichComponent[head->to])
			{
				++dag_in[whichComponent[head->to]];
				++dag_out[whichComponent[i]];
			}
			head=head->next;
		}
	}
	int zero_out=0,zero_in=0;
	for(int i=0;i<componentNum;++i)
	{
		if(dag_in[i]==0) ++zero_in;
		if(dag_out[i]==0) ++zero_out;
	}
	if(componentNum==1)
		printf("1\n0\n");
	else
		printf("%d\n%d\n",zero_in,max(zero_out,zero_in));
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	while(scanf("%d",&n)!=EOF)
	{
		init();
		input();
		solve();
	}
	return 0;
}
