/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-20 22:26
 # Filename: POJ1258 Agri-Net.cpp
 # Description : 
 ******************************************************************************/
// POJ1258 Agri-Net.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int pre[101];
int nodecount;

struct node
{
	int x,y,len;
}farm[101*101];

int cmp(const void *lhs,const void *rhs)
{
	return ((node *)lhs)->len > ((node *)rhs)->len ? 1:-1;
}

void input(int n)
{
	nodecount=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
				farm[nodecount].x=i;
				farm[nodecount].y=j;
				cin>>farm[nodecount].len;
				++nodecount;
		}
}

int find(int x)
{
	while(x !=pre[x])
		x=pre[x];
	return x;
}

void kruskal(int n)
{
	int a,b;
	qsort(farm,nodecount,sizeof(farm[0]),cmp);
	for(int i=0;i<n;++i)
		pre[i]=i;

	int sum=0;

	for(int i=0;i<nodecount;++i)
	{
		if (farm[i].x==0 &&farm[i].y==2)
		{
			a=0;
		}
		a=find(farm[i].x);
		b=find(farm[i].y);
		if(a!=b)
		{ 
			sum+=farm[i].len;
			pre[b]=a;
		}
	}
	printf("%d\n",sum);
}

int main(void)
{
	int n;
	while(cin>>n)
	{
		input(n);
		kruskal(n);
	}
	return 0;
}
