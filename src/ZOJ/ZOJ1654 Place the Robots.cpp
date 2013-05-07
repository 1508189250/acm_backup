#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 2510
using namespace std;

int map[MAX][MAX],used[MAX],mat[MAX];
char blocks[MAX][MAX];
int n,m,cou;

bool inline find(const int &x)
{
	for(int i=0;i<n*m;++i)
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

int hungary()
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
	int ncases;
	scanf("%d",&ncases);
	for(int nc=1;nc<=ncases;++nc)
	{
		cou=0;
		printf("Case :%d\n",nc);
		memset(map,0,sizeof(map));
		memset(blocks,'\0',sizeof(blocks));
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;++i)
		{
			getchar();
			scanf("%s",blocks[i]);
		}

		for(int i=0;i<m;++i)
		{
			int flag=-1;
			int tab=0;
			for(int j=0;j<n;++j)
			{
				if(blocks[i][j]=='#' && flag !=-1)
				{
					flag=-1;
					++cou;
				}
				else if(blocks[i][j]=='o' && flag>=0)
				{
					map[cou][i*n+j]=1;
				}
				else if(blocks[i][j]=='o' && flag==-1)
				{
					map[cou][i*n+j]=1;
					tab=1;
					flag=j;
				}
			}
			if(tab) ++cou;
		}
		for(int j=0;j<n;++j)
		{
			int flag=-1;
			int tab=0;
			for(int i=0;i<m;++i)
			{
				if(blocks[i][j]=='#' && flag>=0)
				{
					++cou;
					flag=-1;
				}
				if(blocks[i][j]=='o' && flag>=0)
				{
					map[cou][i*n+j]=1;
				}
				if(blocks[i][j]=='o' && flag==-1)
				{
					map[cou][i*n+j]=1;
					flag=i;
					tab=1;
				}
			}
			if(tab) ++cou;
		}

		int ans=hungary();
		printf("%d\n",ans);
	}

	return 0;
}
