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
#define lowbit(x) ((x)&(-x))
#define MAX 500100
using namespace std;

struct NODE
{
	int ind,x;
}node[MAX];

bool cmp(const NODE &lhs,const NODE &rhs)
{
	return lhs.x>rhs.x;
}

int num[MAX];
long long c[MAX];

void updata(int x)
{
	while(x<MAX)
	{
		++c[x];
		x+=lowbit(x);
	}
}

long long getsum(int x)
{
	long long sum=0;
	while(x>0)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n;
	while(scanf("%d",&n) &&n)
	{
		memset(c,0,sizeof(c));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&node[i].x);
			node[i].ind=i;
		}
		sort(node,node+n,cmp);

		for(int i=0;i<n;++i)
			num[node[i].ind]=i+1;

		long long ans=0;
		for(int i=0;i<n;++i)
		{
			ans+=getsum(num[i]);
			updata(num[i]);
		}
		printf("%lld\n",ans);

	}

	return 0;
}
