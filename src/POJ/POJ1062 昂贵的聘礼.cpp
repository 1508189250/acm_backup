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
#define MAX 101
using namespace std;

int map[MAX][MAX],value[MAX];
bool visit[MAX];
struct NODE
{
	int level,x;
	unsigned int goods[MAX][2];

	void get()
	{
		scanf("%d%d",&level,&x);
		for( int i=0;i<x;++i)
			scanf("%d%d",&goods[i][0],&goods[i][1]);
	}
}node[MAX];

int dfs(const int &x,const int &m,const  int &tmax,const  int &tmin)
{
	int ans=value[x];
  visit[x]=true;
  for( int i=1;i<MAX;++i)
		if(!visit[i] &&map[x][i] && abs(node[i].level-tmax)<=m && abs(node[i].level-tmin)<=m)
			ans=min(ans,map[x][i]+dfs(i,m,max(node[i].level,tmax),min(node[i].level,tmin)));
  visit[x]=false;
	return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int m,n;

	while(~scanf("%d%d",&m,&n))
	{
		memset(map,0,sizeof(map));
		memset(value,0,sizeof(value));
		memset(visit,false,sizeof(visit));

		for(int i=1;i<=n;++i)
		{
			scanf("%d",&value[i]);
			node[i].get();
		}

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(i!=j && abs(node[i].level-node[j].level)<=m)
				{
					for( int k=0;k<node[i].x;++k)
						if(node[i].goods[k][0]==j)
							map[i][j]=node[i].goods[k][1];
				}
		int ans=dfs(1,m,node[1].level,node[1].level);
		printf("%d\n",ans);
	}

  return 0;
}
