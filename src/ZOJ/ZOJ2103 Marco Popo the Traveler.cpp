#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <queue>
#include <limits.h>
#define MAX 15
using namespace std;
int n,c,h,s,t;
int ind[MAX],outd[MAX],map[MAX][MAX];
int pre[MAX];
typedef struct CAR{
	int u,t,color;
}CAR;
void init()
{
	memset(ind,0,sizeof(ind));
	memset(outd,0,sizeof(outd));
	memset(map,-1,sizeof(map));
	memset(pre,-1,sizeof(pre));
}
int isoula()
{
	int sum = 0,i;
	s = t = -1;
	for(i=0; i<n; i++)
		if( (outd[i]+ind[i]) % 2 == 1 )
		{
			sum++;
			s = i;
		} 

		if( !(sum == 0 || sum == 2) )
			return 0;
		if( sum == 0 )
			s = t = 0;
		return 1;
}
int find(int x)
{
	if( pre[x] == -1 )
		pre[x] = x;
	while( x != pre[x] )
		x = pre[x];
	return x;
}
void Union(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if( a < b )
		pre[b] = pre[y] = pre[x] = a;
	if( b < a )
		pre[a] = pre[y] = pre[x] = b;
}
int con()
{
	int i;
	for(i=1; i<n; i++)
		if( find(i) != 0 )
			return 0;
	return 1;
}
int vis[MAX][MAX];
queue<CAR> q;
int BFS()
{
	while( !q.empty() )
		q.pop();
	int u,t,color,v;
	CAR tmp;
	tmp.u = s;
	tmp.t = 0;
	tmp.color = -1;
	q.push(tmp);
	while( !q.empty() )
	{
		tmp = q.front();
		q.pop();
		u = tmp.u;
		t = tmp.t;
		color = tmp.color;
		int flag = 0, tibu,ok = 1;
		for( v=0; v<n; v++ )
			if( !vis[u][v] && map[u][v] != -1 )
			{
				ok = 0;
				tibu = v;
				if( map[u][v] == color )
				{
					flag = 1;
					vis[u][v] = vis[v][u] = 1;
					tmp.color = color;
					tmp.u = v;
					tmp.t = t;
					q.push(tmp);
					break;
				}
			}
			if( ok )
				return t;
			if( !flag )
			{
				vis[u][tibu] = vis[tibu][u] = 1;
				tmp.u = tibu;
				tmp.t = t+1;
				tmp.color = map[u][tibu];
				q.push(tmp);
			}
	}
}
int main()
{
	int from,to,color,ans;
	while( ~scanf("%d%d%d",&n,&c,&h) && n )
	{
		init();
		while( h-- )
		{
			scanf("%d%d%d",&from,&to,&color);
			map[from][to] = map[to][from] = color;
			outd[from]++; 
			ind[to]++;
			Union(from,to);
		}
		if( con() == 0 || isoula() == 0 )
		{
			printf("No\n");
			continue;
		}
		memset(vis,0,sizeof(vis));
		ans = BFS();
		printf("%d\n",ans-1);
	}
	return 0;
}
