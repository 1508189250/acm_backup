/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-13 19:57
 # Filename: POJ2318 TOYS.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <stdio.h>
#include <math.h>
#include <iostream>
#define EP 1e-10
#define MAX 10010
using namespace std;

struct POINT{
	long long x,y;
}tmp;

struct LINE{
	POINT a,b;
}line[MAX];
int sum[MAX];

//叉积判断点线关系
long long inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	
//向量ac在ab的方向
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

void inBin(const POINT &p,const int &n)
{
	int first=0,end=n+1,mid;
	while(end-first>1)
	{
		mid=(end+first)/2;
		if (crossProduct(line[mid].a,line[mid].b,p)>0)
		{
			end=mid;
		} 
		else
		{
			first=mid;
		}
	}
	++sum[first];
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n,m;
	long long x1,y1,x2,y2;
	int flag=1;
	while(scanf("%d",&n)&&n)
	{
		memset(sum,0,sizeof(sum));
		scanf("%d%lld%lld%lld%lld",&m,&x1,&y1,&x2,&y2);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld%lld",&line[i].a.x,&line[i].b.x);
			line[i].a.y=y1;
			line[i].b.y=y2;
		}

		line[n+1].a.x=x2;
		line[n+1].a.y=y1;
		line[n+1].b.x=x1;
		line[n+1].b.y=y2;
		line[0].a.x=x1;
		line[0].a.y=y1;
		line[0].b.x=x1;
		line[0].b.y=y2;

		int ind=0;
		while(m--)
		{
			scanf("%lld%lld",&tmp.x,&tmp.y);
			inBin(tmp,n);
		}

		if(flag)
			flag=0;
		else
			printf("\n");

		for(int i=0;i<=n;++i)
			printf("%d: %d\n",i,sum[i]);
	}

	return 0;
}