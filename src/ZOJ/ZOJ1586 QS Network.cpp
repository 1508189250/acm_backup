// ZOJ1586 QS Network.cpp : Defines the entry point for the console application.
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

#define N 1010

using namespace std;


struct node
{
	int x,y,len;
}qs[N*N];

int pre[N],n,e,adap[N];

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

void kruskal()
{
	int min=0;
	e=0;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>adap[i];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			qs[e].x=i;
			qs[e].y=j;
			cin>>qs[e].len;
			qs[e].len=adap[i]+adap[j]+qs[e].len;
			++e;
		}
		pre[i]=i;
	}

	sort(qs,qs+e,cmp);

	for(int i=0;i<e;++i)
	{
		int a=find(qs[i].x);
		int b=find(qs[i].y);
		if(a!=b)
		{
			min+=qs[i].len;
			pre[a]=b;
		}
	}

	cout<<min<<endl;
}

int main(void)
{
	int t;
	cin>>t;

	while(t--)
	{
		kruskal();
	}


	return 0;
}
