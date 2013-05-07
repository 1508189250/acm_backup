/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-06 18:46
 # Filename: POJ3159 Candies.cpp
 # Description : SPFA中用栈可以比用队列节省时间
 ******************************************************************************/
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
#include <limits.h>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define MAX 30010
using namespace std;

struct NODE
{
	int to,len;
	NODE *next;
}*apex[MAX],node[6*MAX];

int cou,n,m;

void init()
{
	cou=0;
	memset(apex,'\0',sizeof(apex));
}

void add(const int &u,const int &v,const int &len)
{
	node[cou].to=v;
	node[cou].len=len;
	node[cou].next=apex[u];
	apex[u]=&node[cou++];
}

int spfa()
{
	int dist[MAX],instack[MAX];
	stack<int> mystack;
	for(int i=0;i<=n;++i)
		dist[i]=INT_MAX;
	memset(instack,0,sizeof(instack));
	mystack.push(1);
	dist[1]=0;
	instack[1]=1;
	while(!mystack.empty())
	{
		int x=mystack.top();
		mystack.pop();
		instack[x]=0;
		NODE *head=apex[x];
		while(head)
		{
			int to=head->to;
			int len=head->len;
			if(dist[to]-len>dist[x])
			{
				dist[to]=dist[x]+len;
				if(!instack[to])
				{
					mystack.push(to);
					instack[to]=1;
				}
			}
			head=head->next;
		}
	}
	return dist[n];
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int u,v,len;

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&u,&v,&len);
			add(u,v,len);
		}
		int ans=spfa();
		printf("%d\n",ans);
	}

	return 0;
}
