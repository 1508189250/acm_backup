// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 1100
using namespace std;

int map[MAX][MAX],used[MAX],mat[MAX];
int n,cou,maxday;

void init()
{
	memset(map,0,sizeof(map));
	cou=0;
}

bool inline find(const int &x)
{
	for(int i=0;i<maxday;++i)
	{
		if(used[i]==0 && map[x][i])
		{
			used[i]=1;
			if(mat[i]==-1 || find(mat[i]))
			{
				mat[i]=x;
				return true;
			}
		}
	}
	return false;
}

int func()
{
	int ans=0;
	memset(mat,-1,sizeof(mat));
	for(int i=0;i<cou;++i)
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
	int ncases,days,weeks;
	int work[7];
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		init();
		maxday=0;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<7;++j)
				scanf("%d",&work[j]);
			scanf("%d %d",&days,&weeks);
			for(int d=0;d<7;++d)
				if(work[d])
				{
					for(int j=cou;j<cou+days;++j)
						for(int w=0;w<weeks;++w)
							map[j][w*7+d]=1;
				}
			maxday=max(maxday,weeks);
			cou+=days;
		}
		maxday*=7;
		int ans=func();
		if(ans==cou)
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}
