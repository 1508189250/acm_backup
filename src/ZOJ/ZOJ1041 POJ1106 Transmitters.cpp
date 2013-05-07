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
#define MAX 1010
#define EPS 1e-10
using namespace std;

struct POINT
{
	double x,y;
}tree[MAX];

double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	
//向量ac在ab的方向
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

double inline Distance(const POINT &lhs,const POINT &rhs)
{
	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	POINT transmitter;
	double r;
	int n,num;

	while(scanf("%lf%lf%lf",&transmitter.x,&transmitter.y,&r)&&r>EPS)
	{
		scanf("%d",&n);
		num=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf",&tree[num].x,&tree[num].y);
			double tmp=r-Distance(tree[num],transmitter);
			if(tmp>EPS || fabs(tmp)<EPS)
				++num;
		}
		
		int ans=0;
		for(int i=0;i<num;++i)
		{
			int sum=0;
			for(int j=0;j<num;++j)
			{
				double tmp=crossProduct(transmitter,tree[i],tree[j]);
				if(tmp>EPS||fabs(tmp)<EPS)
					++sum;
			}
			ans=max(sum,ans);
		}
		printf("%d\n",ans);
	}

	return 0;
}
