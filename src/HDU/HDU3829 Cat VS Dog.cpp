#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 520
using namespace std;

int map[MAX][MAX];
int mat[MAX];
bool used[MAX];

bool find(const int &x,const int &n)
{
	int i;
	for(i=1;i<=n;++i)
	{
		if(map[x][i] && !used[i])
		{
			used[i]=1;
			if(!mat[i] || find(mat[i],n))
			{
				mat[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n,m,p;
	char like[MAX][20],dislike[MAX][20];

	while(~scanf("%d%d%d",&n,&m,&p))
	{
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat));
		for(int i=1;i<=p;++i)
		{
			scanf("%s %s",like[i],dislike[i]);
		}

		for(int i=1;i<=p;++i)
			for(int j=1;j<=p;++j)
      {
				if(strcmp(like[i],dislike[j])==0 || strcmp(like[j],dislike[i])==0)
					map[i][j]=map[j][i]=1;
      }

		int ans=0;
		for(int i=1;i<=p;++i)
		{
			memset(used,false,sizeof(used));
			if(find(i,p))
				++ans;
		}
		printf("%d\n",p-ans/2);
	}

  return 0;
}
