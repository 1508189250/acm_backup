// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 1010
using namespace std;

int map[MAX][MAX];
int used[MAX],mat[MAX];
int n;

bool inline find(const int &x)
{
	for(int i=1;i<=n+n;++i)
		if(!used[i] && map[x][i])
		{
			used[i]=1;
			if(mat[i]==0 || find(mat[i]))
			{
				mat[i]=x;
				return true;
			}
		}
	return false;
}

int hungary()
{
	int ans=0;
	memset(mat,0,sizeof(mat));
	for(int i=1;i<=n+n;++i)
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

	int k,from,to;

	while(~scanf("%d%d",&n,&k))
	{
		memset(map,0,sizeof(map));
		while(k--)
		{
			scanf("%d%d",&from,&to);
			map[from][to+n]=1;
		}
		int ans=hungary();
		printf("%d\n",ans);
	}

	return 0;
}
