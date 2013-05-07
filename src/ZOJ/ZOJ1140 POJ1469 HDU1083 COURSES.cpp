// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 810
using namespace std;

int map[MAX][MAX];
bool used[MAX];
int mat[MAX];
int p,n;

bool find(const int &x)
{
	int i;
	for(i=p+1;i<=p+n;++i)
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

int Hungary()
{
	int ans=0;
	for(int i=1;i<=p+n;++i)
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
	int num,to;
	int ncases;

	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d%d",&p,&n);
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat));
		for(int i=1;i<=p;++i)
		{
			scanf("%d",&num);
			while(num--)
			{
				scanf("%d",&to);
				map[i][p+to]=1;
			}
		}
		int ans=0;
		ans = Hungary();
		if(ans==p)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
