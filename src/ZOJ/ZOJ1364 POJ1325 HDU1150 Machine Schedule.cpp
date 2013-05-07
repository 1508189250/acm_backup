// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 220
using namespace std;
int map[MAX][MAX];
bool used[MAX];
int mat[MAX];
int n,m;

bool inline find(const int &x)
{
	int i;
	for(int i=1;i<=n+m;++i)
	{
		if(map[x][i] && !used[i])
		{
			used[i]=true;
			if(!mat[i] || find(mat[i]))
			{
				mat[i]=x;
				return true;
			}
		}
	}	
	return false;
}

int hungray()
{
	int ans = 0;
	for(int i=1;i<=n+m;++i)
	{
		memset(used,0,sizeof(used));
		if(find(i))
			++ans;
	}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int k,temp,from,to;

	while(scanf("%d",&n) &&n)
	{
		scanf("%d%d",&m,&k);
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat));
		
		while(k--)
		{
			scanf("%d%d%d",&temp,&from,&to);
			if(from==0 || to==0)
				continue;
			map[from][to+n]=1;
		}

		int ans=hungray();
		printf("%d\n",ans);
	}

	return 0;
}
