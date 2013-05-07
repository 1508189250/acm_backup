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
#define MAX 110
using namespace std;

int map[MAX][MAX];
bool used[MAX],color[MAX];
bool flag;
int n;

void dfs(const int &x)
{
	if(!flag)
		return;
	used[x]=true;
  for(int i=1;i<=n;++i)
  {
		if(map[x][i] && !used[i])
		{
			if(!color[x])
				color[i]=true;
			dfs(i);
  }
  if(map[x][i] && color[x] == color[i])
  {
    flag = false;
    return;
  }
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	while(~scanf("%d",&n))
	{
		int temp;
		memset(map,0,sizeof(map));
		for(int i=1;i<=n;++i)
		{
			while(scanf("%d",&temp) &&temp)
				map[i][temp]=map[temp][i]=1;
		}

		memset(used,false,sizeof(used));
		memset(color,false,sizeof(color));
		flag=true;
		for(int i=1;i<=n;++i)
			if(!used[i])
				dfs(i);
		if(!flag)
			printf("-1\n");
		else
		{
			for(int i=1;i<=n;++i)
				if(color[i])
					printf("1");
				else
					printf("0");
			printf("\n");
		}

	}

  return 0;
}
