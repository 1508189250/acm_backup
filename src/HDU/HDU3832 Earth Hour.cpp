#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 220
using namespace std;

// 点的定义
struct POINT{
  int x,y,r;
}point[MAX];

// 计算两点的距离
int inline Distance(const POINT &lhs,const POINT &rhs)
{
  return ((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

bool inline ifConnect(const POINT &lhs,const POINT &rhs)
{
	if(Distance(lhs,rhs)<=(lhs.r+rhs.r)*(lhs.r+rhs.r))
		return true;
	else
		return false;
}

int map[MAX][MAX];
int dis[3][MAX];

void Dijkstra(const int &s,const int &n,int *dist)
{
	for(int i=0;i<n;++i)
		dist[i]=INT_MAX;
  bool *used = new bool[n];
	memset(used,false,sizeof(bool)*n);
	used[s]=true;
	dist[s]=0;
	int now=s;

	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n;++j)
			if(map[now][j] && dist[now]!=INT_MAX && dist[j]-dist[now]>map[now][j])
				dist[j]=dist[now]+map[now][j];

		int n_min=INT_MAX;
		
		for(int j=0;j<n;++j)
			if(!used[j] && dist[j]<n_min)
				n_min = dist[now=j];

		used[now]=true;
	}
  delete []used;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int ncases,n;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&point[i].x,&point[i].y,&point[i].r);
    }
    for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j)
        if(ifConnect(point[i],point[j]))
          map[i][j]=map[j][i]=1;
		
		Dijkstra(0,n,dis[0]);
		Dijkstra(1,n,dis[1]);
		Dijkstra(2,n,dis[2]);

		int ans=INT_MAX;
		for(int i=0;i<n;++i)
			if(dis[0][i]!=INT_MAX &&dis[1][i]!=INT_MAX && dis[2][i]!=INT_MAX)
				ans = min(dis[0][i]+dis[1][i]+dis[2][i],ans);

    if(ans==INT_MAX)
      printf("-1\n");
    else
		  printf("%d\n",n-ans-1);
	}

  return 0;
}
