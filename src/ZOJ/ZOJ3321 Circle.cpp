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
#define MAX 15
using namespace std;

int degree[MAX];
int pre[MAX];

int inline find(const int &x)
{
	return x==pre[x]?x:find(pre[x]);
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int u,v;
	int n,m;

	while(~scanf("%d%d",&n,&m))
	{
		memset(degree,0,sizeof(degree));
		for(int i=0;i<=n;++i)
			pre[i]=i;

		while(m--)
		{
			scanf("%d%d",&u,&v);
			++degree[u];
			++degree[v];
			int a=find(u);
			int b=find(v);
			pre[a]=pre[b]=pre[u]=pre[v]=min(a,b);
		}

		bool flag=true;
		for(int i=1;i<=n && flag;++i)
			if(degree[i]!=2)
			{
				flag=false;
			}
			else if(pre[i]!=1)
				flag=false;
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");

	}

  return 0;
}
