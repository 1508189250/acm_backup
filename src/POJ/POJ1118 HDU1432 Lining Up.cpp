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
#include <algorithm>
#include <math.h>
#include <float.h>
#define MAX 2010
#define EPS 1e-10
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
	int x,y;
}point[MAX];


double inline slope(const POINT &lhs,const POINT &rhs)
{
	if(lhs.x==rhs.x)
		return DBL_MAX;
	return 1.0*(lhs.y-rhs.y)/(lhs.x-rhs.x);
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n;
	double k[MAX];
	
	while(~scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;++i)
			scanf("%d%d",&point[i].x,&point[i].y);

		int maxsum=0;
		for(int i=0;i<n;++i)
		{
			int cnt=0;
			for (int j=i+1;j<n;++j)
				k[cnt++]=slope(point[i],point[j]);

			sort(k,k+cnt);

			int sum=1;
			for (int j=1;j<cnt;++j)
			{
				if(k[j-1]==k[j])
					++sum;
				else
				{
					maxsum=max(sum,maxsum);
					sum=1;
				}
			}
			maxsum=max(sum,maxsum);
		}
		printf("%d\n",maxsum+1);
	}

	return 0;
}
