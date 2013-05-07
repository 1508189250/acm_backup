// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 510
using namespace std;

int map[MAX][MAX],used[MAX],mat[MAX];
int n;

bool inline find(const int &x)
{
	for(int i=0;i<n;++i)
		if(map[x][i] && used[i]==0)
		{
			used[i]=1;
			if(mat[i]==-1 || find(mat[i]))
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
	memset(mat,-1,sizeof(mat));
	for(int i=0;i<n;++i)
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
	int num,u,v;

	while(~scanf("%d",&n))
	{
		memset(map,0,sizeof(map));
		for(int i=0;i<n;++i)
		{
			scanf("%d: (%d) ",&u,&num);
			while(num--)
			{
				scanf("%d",&v);
				map[u][v]=1;
			}
		}
		int ans=hungary();
		printf("%d\n",n-ans/2);
	}

	return 0;
}
