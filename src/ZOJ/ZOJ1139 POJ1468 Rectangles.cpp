// #include "stdafx.h"
// #define DEBUG
// 
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#define MAX 5010
#define EPS 1e-6
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct RECTANGLE
{
	double xmin,xmax,ymin,ymax;
}rectangles[MAX];

/************************************************************************/
/*double的大小判断                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_ou_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

bool inline recEqual(const RECTANGLE &lhs,const RECTANGLE &rhs)
{
	if(_greater_ou_equal(lhs.xmin,rhs.xmin) && _less_or_equal(lhs.xmax,rhs.xmax)
		&& _greater_ou_equal(lhs.ymin,rhs.ymin) && _less_or_equal(lhs.ymax,rhs.ymax))
		return true;
	return false;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n;
	int flag[MAX];
	while(~scanf("%d",&n))
	{
		int ans=0;
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;++i)
			scanf("%lf%lf%lf%lf",&rectangles[i].xmin,&rectangles[i].xmax,&rectangles[i].ymin,&rectangles[i].ymax);

		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(i!=j && recEqual(rectangles[i],rectangles[j]))
					flag[i]=1;

		for (int i=0;i<n;++i)
			if(flag[i])
				++ans;
		printf("%d\n",ans);

	}

	return 0;
}
