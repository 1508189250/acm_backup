// POJ2485 Highways.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <stdlib.h>
// #include <iostream>
#include <algorithm>

using namespace std;

#define MAX_TOWN 501

int p,pre[MAX_TOWN];

struct node
{
	int x,y,len;
}town[MAX_TOWN*MAX_TOWN];

void input(int n)
{
	p=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			town[p].x=i;
			town[p].y=j;
			scanf("%d",&town[p].len);
			++p;
		}
}

int find(int x)
{
	while(x!=pre[x])
		x=pre[x];
	return x;
}

// int cmp(const void *lhs,const void *rhs)
// {
// 	return ((node*)lhs)->len>((node*)rhs)->len ? 1:-1;
// }
int cmp(const node &lhs,const node &rhs)
{
	return lhs.len<rhs.len? 1:0;
}

int kruskal(int n)
{
	int a,b;
	int min=0;

// 	qsort(town,p,sizeof(town[0]),cmp);
	sort(town,town+p,cmp);
	for(int i=0;i<=n;++i)
		pre[i]=i;

	for(int i=0;i<p;++i)
	{
		a=find(town[i].x);
		b=find(town[i].y);
		if(a!=b)
		{
			pre[a]=b;
			min=town[i].len;
		}
	}

	return min;
}

int main(void)
{
	int ncase;
	int n;
	
	scanf("%d",&ncase);

	while(ncase--)
	{
		scanf("%d",&n);
		input(n);
		printf("%d\n",kruskal(n));
	}


	return 0;
}
