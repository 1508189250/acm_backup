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

int map[MAX][MAX],used[MAX],mat[MAX];
int n;

bool inline find(const int &x)
{
	for(int i=0;i<MAX;++i)
		if(map[x][i] && !used[i])
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
	for(int i=0;i<MAX;++i)
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

	int num,p,q;

	while(~scanf("%d",&n))
	{
		memset(map,0,sizeof(map));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d%d",&p,&q);
				map[i][(p-1)*12+q]=1;
			}
		}
		int ans=hungary();
		printf("%d\n",ans);
	}

	return 0;
}
