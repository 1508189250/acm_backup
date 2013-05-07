/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-26 21:12
 # Filename: ZOJ1128 POJ1151 HDU1542 Atlantis.cpp
 # Description : 
 ******************************************************************************/
#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#define EPS 1e-6
#define MAX 210
using namespace std;

struct POINT
{
  double lx,ly,rx,ry;
}point[MAX];

/************************************************************************/
/*doubleµÄ´óÐ¡ÅÐ¶Ï                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

double x[2*MAX],y[2*MAX];
int map[MAX][MAX];

int find(const double *array,const double &x,int m)
{
	int beg=0,end=m-1;
	while(beg<=end)
	{
		int mid=(beg+end)>>1;
		if(_equal(array[mid],x))
			return mid;
		else if(_greater(x,array[mid]))
			beg=mid+1;
		else
			end=mid;
  }
}

double Area(const int &m,const int &n)
{
	memset(map,0,sizeof(map));
	for(int i=0;i<n;++i)
	{
		int lx=find(x,point[i].lx,m);
		int ly=find(y,point[i].ly,m);
		int rx=find(x,point[i].rx,m);
		int ry=find(y,point[i].ry,m);
		for(int j=lx;j<rx;++j)
			for(int k=ly;k<ry;++k)
				map[j][k]=1;
	}

	double sum=0.0;
	for(int i=0;i<m-1;++i)
		for(int j=0;j<m-1;++j)
			if(map[i][j])
				sum+=(x[i+1]-x[i])*(y[j+1]-y[j]);
	return sum;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int ncanses=1;
	int n;

	while(scanf("%d",&n)&&n)
	{
		int m=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf%lf%lf",&point[i].lx,&point[i].ly,&point[i].rx,&point[i].ry);
			x[m]=point[i].lx;
			y[m++]=point[i].ly;
			x[m]=point[i].rx;
			y[m++]=point[i].ry;
		}
		sort(x,x+m);
		sort(y,y+m);
		double ans=Area(m,n);
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",ncanses++,ans);
	}

  return 0;
}
