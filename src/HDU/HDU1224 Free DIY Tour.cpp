/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-30 20:11
 # Filename: HDU1224 Free DIY Tour.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

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
#define MAX 120
using namespace std;

bool map[MAX][MAX];
int value[MAX],pre[MAX],sum[MAX];

void func(const int &n)
{
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;++i)
		if(pre[i]||i==1)
			for(int j=i+1;j<=n;++j)
				if(map[i][j] && sum[j]<sum[i]+value[j])
				{
					sum[j]=sum[i]+value[j];
					pre[j]=i;
				}
}

void output(const int &n)
{
	if(n==0)
		return;
	else
	{
		output(pre[n]);
		printf("%d->",n);
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int ncases,n,m;
	int u,v;
	scanf("%d",&ncases);

	for(int nc=1;nc<=ncases;++nc)
  {
    memset(pre,0,sizeof(pre));
    memset(map,false,sizeof(map));
    memset(value,0,sizeof(value));

		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&value[i]);

		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&u,&v);
			map[u][v]=true;
			if(u==1)
      {
				pre[v]=u;
//         sum[v]=value[v];
      }
		}

    if(nc>1)
      printf("\n");
		func(n+1);
		printf("CASE %d#\n",nc);
		printf("points : %d\ncircuit : ",sum[n+1]);
		output(pre[n+1]);
		printf("1\n");
	}

  return 0;
}
