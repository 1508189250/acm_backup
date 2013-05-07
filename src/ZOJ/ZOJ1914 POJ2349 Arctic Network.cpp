// ZOJ1914 POJ2349 Arctic Network.cpp : Defines the entry point for the console application.
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

#define P 510

using namespace std;

int x[P],y[P];
int pre[P],n,e;

struct node
{
	int x,y,len;
}output[P*P];

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
	int s;
	e=0;
	cin>>s>>n;
	for(int i=0;i<n;++i)
		cin>>x[i]>>y[i];

	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			output[e].x=i;
			output[e].y=j;
			output[e++].len=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		}
		pre[i]=i;
	}

	sort(output,output+e,cmp);
	
	double result;
	int index=n-s;

	for(int i=0;i<e;++i)
	{
		int a=find(output[i].x);
		int b=find(output[i].y);
		if(a!=b)
		{
			pre[a]=b;
			--index;
			if(!index)
				result = output[i].len;
		}
	}

	printf("%.2f\n",sqrt(result));

}

int main(void)
{
	int testcase;
	cin>>testcase;

	while(testcase--)
	{
		kruskal();
	}


	return 0;
}


