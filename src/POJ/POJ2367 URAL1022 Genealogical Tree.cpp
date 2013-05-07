/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-28 19:04
 # Filename: POJ2367 URAL1022 Genealogical Tree.cpp
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
#include <algorithm>
#include <math.h>
#define MAX 110
using namespace std;

int map[MAX][MAX];
int used[MAX],order[MAX];
int n_count;

void dfs(const int x)
{
	for(int i=0;map[x][i];++i)
		if(!used[map[x][i]])
		{
			used[map[x][i]]=1;
			dfs(map[x][i]);
		}
	order[--n_count]=x;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n;
	while(~scanf("%d",&n))
	{
		memset(map,0,sizeof(map));
		memset(used,0,sizeof(used));
		n_count=n;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<n;++j)
			{
				scanf("%d",&map[i][j]);
				if(!map[i][j])
					break;
			}
		}
		for(int i=1;i<=n;++i)
			if(!used[i])
      {
        used[i]=1;
				dfs(i);
      }

		for(int i=0;i<n-1;++i)
			printf("%d ",order[i]);
		printf("%d\n",order[n-1]);

	}

  return 0;
}
