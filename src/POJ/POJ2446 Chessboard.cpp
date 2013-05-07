// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 1600
using namespace std;

int map[MAX][MAX],board[MAX][MAX],used[MAX],mat[MAX];
int n,m;

void init()
{
	memset(map,0,sizeof(map));
	memset(board,0,sizeof(board));
}

bool inline find(const int &x)
{
	for(int i=0;i<m;++i)
		if(used[i]==0 && map[x][i])
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

int func()
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

int dist[]={1,0,-1,0,0,1,0,-1};

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int a,b,y,x,hole;

	while(~scanf("%d%d%d",&a,&b,&hole))
	{
		init();
		n=m=a*b;
		int ans=0,flag=0;
		for(int i=0;i<hole;++i)
		{
			scanf("%d%d",&x,&y);
			board[y-1][x-1]=1;
		}

		if (n%2 != hole%2)
		{
			printf("NO\n");
			continue;
		}

		for(int i=0;i<a;++i)
			for(int j=0;j<b;++j)
				if(board[i][j]==0)
					for(int k=0;k<8;k+=2)
					{
						x=i+dist[k];
						y=j+dist[k+1];
						if(board[x][y]==0 &&x>=0 && x<a &&y>=0 && y<b )
							map[i*b+j][x*b+y]=1;
					}
		ans=func();
		if(ans != n-hole )
			printf("NO\n");
		else
			printf("YEX\n");
	}

	return 0;
}
