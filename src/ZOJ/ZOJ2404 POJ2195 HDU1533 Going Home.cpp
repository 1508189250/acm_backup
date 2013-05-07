/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-09 20:18
 # Filename: ZOJ2404 POJ2195 HDU1533 Going Home.cpp
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
#include <limits.h>
#include <vector>
#include <stack>
#include <math.h>
#define MAX 220
using namespace std;

struct NODE
{
	int x,y;
}house[MAX],men[MAX];

int capacity[MAX][MAX],flow[MAX][MAX];
int cost[MAX][MAX];
int hcount,mcount,n,m;

int EKwithSPFA(int source,int target)
{
	int dist[MAX],pre[MAX],instack[MAX];
	int ans=0;
	stack<int> mstack;
	memset(flow,0,sizeof(flow));

	while(1)
	{
		for(int i=source;i<=target;++i)
			dist[i]=INT_MAX;
		dist[source]=0;
		memset(instack,0,sizeof(instack));
		instack[source]=1;
		mstack.push(source);
		while(!mstack.empty())
		{
			int x=mstack.top();
			mstack.pop();
			instack[x]=0;
			for(int i=source;i<=target;++i)
				if(capacity[x][i]>flow[x][i] && dist[i]>dist[x]+cost[x][i])
				{
					dist[i]=dist[x]+cost[x][i];
					pre[i]=x;
					if(!instack[i])
					{
						mstack.push(i);
						instack[i]=1;
					}
				}
		}
		if(dist[target]==INT_MAX)
			break;
		int a=INT_MAX;
		for(int u=target;u!=source;u=pre[u])
			if(capacity[pre[u]][u]-flow[pre[u]][u]<a)
				a=capacity[pre[u]][u]-flow[pre[u]][u];
		for(int u=target;u!=source;u=pre[u])
		{
			flow[pre[u]][u]+=a;
			flow[u][pre[u]]-=a;
		}
		ans+=dist[target]*a;
	}
	return ans;

}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	char ch;
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		hcount=mcount=1;
		memset(capacity,0,sizeof(capacity));
		memset(cost,0,sizeof(cost));
		for(int i=0;i<n;++i)
		{
			getchar();
			for(int j=0;j<m;++j)
			{
				ch=getchar();
				if(ch=='H')
				{
					house[hcount].x=i;
					house[hcount++].y=j;
				}
				else if(ch=='m')
				{
					men[mcount].x=i;
					men[mcount++].y=j;
				}
			}
		}
		for(int i=1;i<hcount;++i)
		{
			capacity[i][hcount+mcount-1]=1;
			for(int j=1;j<mcount;++j)
			{
				int from=hcount+j-1;
				int to=i;
				capacity[from][to]=1;
				cost[from][to]=abs(men[i].x-house[j].x)+abs(men[i].y-house[j].y);
				cost[to][from]=-cost[from][to];	//
			}
		}
		for(int j=1;j<mcount;++j)
			capacity[0][hcount+j-1]=1;
		int ans=EKwithSPFA(0,hcount+mcount-1);
		printf("%d\n",ans);
	}

	return 0;
}
