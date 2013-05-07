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
#define MAX 120
#define EPS 1e-10
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
	double x,y;
}point[MAX];

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

bool cmp(const POINT &lhs,const POINT &rhs)
{
	return _less(crossProduct(point[0],lhs,rhs),0.0);
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	char str[100];
	scanf("%d",&ncases);
// 	ncases=1;
	getchar();
	getchar();
	while(ncases--)
	{
		int n=0;
		while(gets(str) && strlen(str))
		{
			sscanf(str,"%lf%lf",&point[n].x,&point[n].y);
			++n;
		}
		sort(point+1,point+n,cmp);
		
		for(int i=0;i<n;++i)
			printf("(%.0lf,%.0lf)\n",point[i].x,point[i].y);
		if(ncases)
			printf("\n");
	}

	return 0;
}
