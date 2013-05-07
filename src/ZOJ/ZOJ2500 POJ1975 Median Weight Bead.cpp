// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#define MAX 120

using namespace std;
int map[MAX][MAX],tmap[MAX][MAX];

void init()
{
	memset(map,0,sizeof(map));
	memset(tmap,0,sizeof(tmap));
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	scanf("%d",&ncases);
	int n,m;
	int a,b;
	while(ncases--)
	{
		scanf("%d %d",&n,&m);
		init();
		while(m--)
		{
			scanf("%d %d",&a,&b);
			map[a][b]=1;
			tmap[b][a]=1;
		}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					if(map[i][k]&&map[k][j])
						map[i][j]=1;
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					if(tmap[i][k]&&tmap[k][j])
						tmap[i][j]=1;
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			int temp=0;
			int flag=0;
			for(int j=1;j<=n;++j)
				if(map[i][j]) ++temp;
			if(temp >= (n+1)/2)
				flag=1;
			temp=0;
			for(int j=1;j<=n;++j)
				if(tmap[i][j]) ++temp;
			if(temp >= (n+1)/2)
				flag=1;
			if(flag)
			{
				++sum;
// 				printf("%d\n",i);
			}
		}
		printf("%d\n",sum);
	}

	return 0;
}
