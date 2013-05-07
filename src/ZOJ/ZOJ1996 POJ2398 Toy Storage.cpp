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
#define MAX 1020
#define EPS 1e-10
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
	double x,y;
};

/************************************************************************/
/* 线段的定义                                                           */
/************************************************************************/
struct LINE{
	POINT a,b;
}line[MAX];


/************************************************************************/
/* 计算两点的距离                                                       */
/************************************************************************/
double inline Distance(const POINT &lhs,const POINT &rhs)
{
	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

/************************************************************************/
/* 计算向量ac在ab的方向的叉积                                           */
/************************************************************************/
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

/************************************************************************/
/*double的大小判断                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)
{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs){
	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs){	
	return fabs(lhs-rhs)< EPS;  }

/************************************************************************/
/* 确定两条线段是否相交（含端点相交）                                   */
/************************************************************************/
int   intersect(const LINE  &lhs,const LINE &rhs)  
{  
	return((max(lhs.a.x,lhs.b.x)>=min(rhs.a.x,rhs.b.x))&&  
		(max(rhs.a.x,rhs.b.x)>=min(lhs.a.x,lhs.b.x))&&  
		(max(lhs.a.y,lhs.b.y)>=min(rhs.a.y,rhs.b.y))&&  
		(max(rhs.a.y,rhs.b.y)>=min(lhs.a.y,lhs.b.y))&&  
		(crossProduct(lhs.a,lhs.b,rhs.a)*crossProduct(lhs.a,rhs.b,lhs.b)>=0)&&  
		(crossProduct(rhs.a,rhs.b,lhs.a)*crossProduct(rhs.a,lhs.b,rhs.b)>=0));  
} 

bool cmp(const LINE &lhs,const LINE &rhs)
{
	return _less(lhs.a.x,rhs.a.x);
}

void func(int *sum,LINE *lArray,const LINE &tline,int end)
{
	int start=0;
	int mid=(start+end)/2;
	while(end-start>=2)
	{
		mid=(end+start)/2;
		if(intersect(lArray[mid],tline))
			start=mid;
		else
			end=mid;
	}
	++sum[start];
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	LINE tline;
	int n,m;
	int sum[MAX];

	while(scanf("%d",&n)&&n)
	{
		memset(sum,0,sizeof(sum));

		scanf("%d%lf%lf%lf%lf",&m,&line[0].a.x,&line[0].a.y,&line[n+1].b.x,&line[n+1].b.y);
		line[0].b.x=line[0].a.x;
		line[0].b.y=line[n+1].b.y;
		line[n+1].a.x=line[n+1].b.x;
		line[n+1].a.y=line[0].a.y;

		for(int i=1;i<=n;++i)
		{
			scanf("%lf%lf",&line[i].a.x,&line[i].b.x);
			line[i].a.y=line[0].a.y;
			line[i].b.y=line[0].b.y;
		}

		sort(line+1,line+n+1,cmp);

		tline.a=line[0].a;

		while(m--)
		{
			scanf("%lf%lf",&tline.b.x,&tline.b.y);
			func(sum,line,tline,n+1);
		}

		printf("Box\n");
		for (int i=1;i<=n;++i)
		{
			int ans=0;
			for(int j=0;j<=n;++j)
				if(sum[j]==i)
					++ans;
			if(ans)
				printf("%d: %d\n",i,ans);
		}
	}

	return 0;
}
