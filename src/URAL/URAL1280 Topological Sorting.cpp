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
#define MAX 1010
using namespace std;
int g_in_degree[MAX];
int g_map_ind[MAX],g_map[MAX][MAX];
int order[MAX];

bool check(const int &u,const int &v)
{
  for (int i=0;i<g_map_ind[u];++i)
    if(g_map[u][i]==v)
      return true;
  return false;
}
int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n,m;
	int u,v;
	while(~scanf("%d%d",&n,&m))
	{
		memset(g_in_degree,0,sizeof(g_in_degree));
		memset(g_map_ind,0,sizeof(g_map_ind));
		memset(g_map,0,sizeof(g_map));
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&u,&v);
      if(check(u,v))
        continue;
			++g_in_degree[v];
			g_map[u][g_map_ind[u]++]=v;
		}
		bool flag=true;
		for(int i=0;i<n;++i)
			scanf("%d",&order[i]);
		
		bool ans=true;
		for(int i=1;i<n;++i)
		{
			if(g_in_degree[order[i-1]]!=0)
			{
				ans=false;
				break;
			}
			for(int j=0;j<g_map_ind[order[i-1]];++j)
			{
				--g_in_degree[g_map[order[i-1]][j]];
			}
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
  return 0;
}
