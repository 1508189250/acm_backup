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
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>
using namespace std;

int map[110][110],visit[110];
int n,ans;

void dfs(const int &s)
{
	bool flag=true;
	for(int i=1;i<=n;++i)
		if(map[s][i])
		{
			if(visit[i])
			{
				ans =0;
				return ;
			}
			else
			{
				visit[i]=1;
				dfs(i);
				visit[i]=0;
				if(ans ==0)
					return;
			}
		}
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int from,to;

	while(scanf("%d",&n) && n>=0)
	{
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		ans =1;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&from,&to);
			if(from != to)
				map[from][to]=1;
		}
		scanf("%d",&from);
		visit[from] =1;
		dfs(from);
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}
