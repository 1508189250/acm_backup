// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <math.h>
#include <stack>
#define MAX 1010
using namespace std;

struct NODE
{
	double x,y;
}node[MAX];
int map[MAX][MAX];
int used[MAX];
int ins[MAX];

double inline dist(const double &x,const double &y,const double &a,const double &b)
{
	return (x-a)*(x-a)+(y-b)*(y-b);
}

int spfa(const int &start,const int &end,const int &n)
{
	int u,v;
	stack<int> st;
	memset(ins,0,sizeof(ins));
	for(int i=1;i<=n;++i)
		used[i]=INT_MAX;
	
	st.push(start);
	ins[start]=1;
	used[start]=0;

	while(!st.empty())
	{
		u=st.top();
		st.pop();
		ins[u]=0;
		for(v=1;v<=n;++v)
			if(map[u][v] && used[v]>used[u]+1)
			{
				used[v]=used[u]+1;
				if(!ins[v])
				{
					st.push(v);
					ins[v]=1;
				}
			}
	}
	return used[end];
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,start,end;
	double len1,len2;
	int ncases,blocks;
	
	scanf("%d",&blocks);
	while(blocks--)
	{

	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d%d%d%lf%lf",&n,&start,&end,&len1,&len2);
		double len=len1+len2;
		len*=len;

		for(int i=1;i<=n;++i)
			scanf("%lf%lf",&node[i].x,&node[i].y);

		memset(map,0,sizeof(map));

		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(len>=dist(node[i].x,node[i].y,node[j].x,node[j].y))
					map[i][j]=map[j][i]=1;

		int ans=spfa(start,end,n);
		if(ans==INT_MAX)
			printf("Impossible\n");
		else
			printf("%d\n",ans);

	}
	}

	return 0;
}
