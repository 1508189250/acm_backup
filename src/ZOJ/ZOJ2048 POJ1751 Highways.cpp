// ZOJ2048 POJ1751 Highways.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>
#include <assert.h>
#include <ctype.h>

using namespace std;

#define N 760

struct node
{
	int x,y;
	double len;
}town[N*N];

int pre[N],n,e;

int find(int x)
{
	while(x!=pre[x])
		x=pre[x];
	return x;
}

bool cmp(const node &lhs,const node &rhs)
{
	return lhs.len<rhs.len;
}

bool cmp2(const node &lhs,const node &rhs)
{
	if(lhs.x!= rhs.x) return lhs.x<rhs.x;
	else return lhs.y<rhs.y;
}

void input()
{
	e=0;

	cin>>n;
	int *x=new int[n];
	int *y=new int[n];
	for(int i=0;i<n;++i)
		cin>>x[i]>>y[i];
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
		{
			town[e].x=i+1;
			town[e].y=j+1;
			town[e++].len=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		}

		for(int i=0;i<=n;++i)
			pre[i]=i;

		int a,b,m;
		cin>>m;
		while(m--)
		{
			cin>>a>>b;
			a=find(a);
			b=find(b);
			if (a!=b)
			{
				pre[a]=b;
			}
		}

		delete []x;
		delete []y;

}

void kruskal()
{
	int a,b;
	sort(town,town+e,cmp);

	for(int i=0;i<e;++i)
	{
		a=find(town[i].x);
		b=find(town[i].y);
		if(a!=b)
		{
			cout<<town[i].x<<' '<<town[i].y<<endl;
			pre[a]=b;
		}
	}
}

int main(void)
{
	int ncase,casenum;
	cin>>ncase;

	for(casenum=0;casenum<ncase;++casenum)
	{
		if (casenum!=0)
		{
			cout<<endl;
		}
		input();
		kruskal();
	}


	return 0;
}
