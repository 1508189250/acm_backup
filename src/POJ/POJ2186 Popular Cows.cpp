/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-09-23 23:31
 # Filename: POJ2186 Popular Cows.cpp
 # Description : KosarajuËã·¨+Ëõ½Úµã
 ******************************************************************************/
// POJ2186 Popular Cows.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <stack>
#define MAX 10010 
using namespace std;

struct NODE
{
	int to;
	NODE *next;
}*v[MAX],node[5*MAX];
int nodecount,n,m;
int inStack[MAX],DFN[MAX],Low[MAX],inComponent[MAX],componentSum[MAX];
int ComponentNum=0,index=0;
stack<int> mstack;

void init(void)
{
	memset(v,'\0',sizeof(v));
	memset(inStack,0,sizeof(inStack));
	memset(DFN,0,sizeof(DFN));
	memset(Low,0,sizeof(Low));
	memset(inComponent,0,sizeof(inComponent));
	memset(componentSum,0,sizeof(componentSum));
	while(!mstack.empty()) mstack.pop();
	nodecount=0;
}
void input(void)
{
	int from,to;
	for(int i=0;i<m;++i)
	{
		scanf("%d %d",&from,&to);
		node[nodecount].to=to;
		node[nodecount].next=v[from];
		v[from]=&node[nodecount++];
	}
}

void tarjan(int i)
{
	int j;
	DFN[i]=Low[i]=++index;
	inStack[i]=1;
	mstack.push(i);
	NODE *head=v[i];
	while(head)
	{
		j=head->to;
		if(!DFN[j])
		{
			tarjan(j);
			Low[i]=min(Low[i],Low[j]);
		}
		else if(inStack[j])
			Low[i]=min(Low[i],DFN[j]);
		head=head->next;
	}
	if(DFN[i]==Low[i])
	{
		do
		{
			j=mstack.top();
			mstack.pop();
			inStack[j]=0;
			inComponent[j]=ComponentNum;
			++componentSum[ComponentNum];
		}
		while(j!=i);
		++ComponentNum;
	}
}

void outDegree(void)
{
	int out[MAX];
	memset(out,0,sizeof(out));
	for(int i=1;i<=n;++i)
	{
		NODE *head=v[i];
		while(head)
		{
			if(inComponent[i] != inComponent[head->to])
				++out[inComponent[i]];
			head=head->next;
		}
	}
	int ncount=-1;
	for(int i=0;i<ComponentNum;++i)
		if(out[i]==0)
			if(ncount==-1)
				ncount=i;
			else
			{
				printf("0\n");
				return;
			}
	printf("%d\n",componentSum[ncount]);
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	while(scanf("%d %d",&n,&m)!=EOF)
	{
		init();
		input();
		for(int i=1;i<=n;++i)
			if(!DFN[i])
				tarjan(i);
		outDegree();
	}
	return 0;
}
