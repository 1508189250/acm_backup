/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-15 19:37
 # Filename: ZOJ2107 HDU1007 Quoit Design.cpp
 # Description : 
 ******************************************************************************/
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
#include <float.h>
#include <limits.h>
#include <math.h>
#define MAX 100100
#define maxdis DBL_MAX
#define EPS 1e-15
using namespace std;

struct POINT
{
	double x,y;
}point[MAX],*remain[MAX];

double inline Distance(const POINT &lhs,const POINT &rhs)
{
	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

bool inline _less(const double &lhs,const double &rhs)
{
	 return lhs < rhs - EPS;  
}
bool inline _less_or_equal(const double &lhs,const double &rhs)
{
	return lhs < rhs + EPS;  
}
bool inline _equal(const double &lhs,const double &rhs)
{
	return fabs(lhs-rhs)< EPS;  
}
bool inline _greater(const double &lhs,const double &rhs)
{
	return lhs>rhs+EPS;
}
bool inline _greater_ou_equal(const double &lhs,const double &rhs)
{
	return lhs>rhs-EPS;
}

double _min(const double &lhs,const double &rhs)
{
	return _less(lhs,rhs)?lhs:rhs;
}

bool inline cmp(const POINT &lhs, const POINT &rhs)
{
	if(_equal(lhs.x,rhs.x))
		return _less(lhs.y,rhs.y);
	else
		return _less(lhs.x,rhs.x);
}
bool inline cmp2(const POINT *lhs, const POINT *rhs)
{
	if(_equal(lhs->y,rhs->y))
		return _less(lhs->x,rhs->x);
	else
		return _less(lhs->y,rhs->y);
}

double func(const int &lhs,const int &rhs)
{
	if(lhs == rhs)
		return DBL_MAX;
	else if(lhs==rhs-1)
		return Distance(point[lhs],point[rhs]);
	else if(lhs==rhs-2)
		return _min(_min(Distance(point[lhs],point[lhs+1]),Distance(point[lhs],point[lhs+2])),Distance(point[lhs+1],point[lhs+2]));
	int mid=(lhs+rhs)>>1;
	double ans=min(func(lhs,mid),func(mid+1,rhs));
	int len=0;
	
	for(int i=mid;i>=lhs && _less(point[mid].x-point[i].x,ans);--i)
		remain[len++]=&point[i];
	for(int i=mid+1;i<=rhs && _less(point[i].x-point[mid].x,ans);++i)
		remain[len++]=&point[i];

	sort(remain,remain+len,cmp2);

	for(int i=0;i<len-1;++i)
		for(int j=i+1;j<len;++j)
			if(_less_or_equal(ans,remain[j]->y-remain[i]->y))
				break;
			else
				ans=_min(Distance(*remain[j],*remain[i]),ans);
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n;
	while(scanf("%d",&n) &&n)
	{
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&point[i].x,&point[i].y);
		sort(point,point+n,cmp);
		double ans=func(0,n-1);
		printf("%.2lf\n",ans/2);
	}

	return 0;
}
