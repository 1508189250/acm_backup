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
#define MAX 1000010 
#define EPS 1e-10
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
	int x,y;
}point[MAX];

/************************************************************************/
/* 求多边形的面积                                                       */
/************************************************************************/
long long area(POINT *pArray,const int &n)
{
	long long ans=0;

	for(int i=0;i<n;++i)
	{
		ans+=1ll*pArray[i].x*pArray[(i+1)%n].y-1ll*pArray[i].y*pArray[(i+1)%n].x;
	}

	return ans>0?ans:-ans;
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int dx[]={0,-1,0,1,-1,0,1,-1,0,1};
	int dy[]={0,-1,-1,-1,0,0,0,1,1,1};

	char str[MAX];
	int ncases;
	scanf("%d",&ncases);
	point[0].x=0;
	point[0].y=0;
	getchar();
	while(ncases--)
	{
		gets(str);
		int len=strlen(str);

		for(int i=0;i<len-1;++i)
		{
			int ind = str[i]-'0';
				point[i+1].x=point[i].x+dx[ind];
				point[i+1].y=point[i].y+dy[ind];

		}
		long long ans=area(point,len-1);

		if(ans%2)
			printf("%lld.5\n",ans/2);
		else
			printf("%lld\n",ans/2);
	}

	return 0;
}
