/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-18 19:48
 # Filename: ZOJ3033 Board Games.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <vector>
#include <stack>
#define MAX 100010
using namespace std;

struct NODE
{
	int v;
	long long w;
};

vector<NODE> edge[MAX];
stack<int> stk;
int n,ncase,m;
int beg,end;
int visit[MAX],in_stk[MAX];
long long dist[MAX];

int spfa()
{
	memset(visit,0,sizeof(visit));
	memset(in_stk,0,sizeof(in_stk));
	for(int i=0;i<n;++i)
		dist[i]= ((long long)(1))<<61;
	while(!stk.empty())
		stk.pop();
	stk.push(beg);
	in_stk[beg]=1;
	dist[beg]=0;
	while(!stk.empty())
	{
		int u=stk.top();
		stk.pop();
		if(++visit[u]>n)
			return 0;
// 		if(visit[end]>n)
// 			return -1;
		in_stk[u]=0;
		for(size_t i=0;i<edge[u].size();++i)
		{
			int v=edge[u][i].v;
			long long w=edge[u][i].w;
			if(dist[v]-dist[u]>w)
			{
				dist[v]=dist[u]+w;
				if(!in_stk[v])
				{
					stk.push(v);
					in_stk[v]=1;
				}
			}
		}
	}
	return 1;
}

int main(void)
{
#ifdef DEBUG  
	freopen("../stdin.txt","r",stdin);
	freopen("../stdout.txt","w",stdout); 
#endif  

	scanf("%d",&ncase);
	int u;

	while(ncase--)
	{
		scanf("%d",&n);
		scanf("%d%d",&beg,&end);
		scanf("%d",&m);
		for(int i=0;i<n;++i)
			edge[i].clear();

		NODE nd_tmp;
		while(m--)
		{
			scanf("%d%d%lld",&u,&nd_tmp.v,&nd_tmp.w);
			edge[u].push_back(nd_tmp);
		}
		
		int ans=spfa();
		if(dist[end]== ((long long)(1))<<61 || !ans)
			printf("infinity\n");
		else
			printf("%d\n",dist[end]);
	}

	return 0;
}
