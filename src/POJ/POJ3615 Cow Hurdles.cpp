// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 310
using namespace std;

int map[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n,m,t;
	int u,v,h;

	while(~scanf("%d%d%d",&n,&m,&t))
	{
		for(int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
			{
				map[i][j]=2000000;
			}
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&h);
			map[u][v]=h;
		}
		
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					if(map[i][j]>max(map[i][k],map[k][j]))
						map[i][j]=max(map[i][k],map[k][j]);

		while(t--)
		{
			scanf("%d%d",&u,&v);
			int ans=map[u][v];
			if(ans<2000000)
				printf("%d\n",ans);
			else
				printf("-1\n");
		}

	}

	return 0;
}
