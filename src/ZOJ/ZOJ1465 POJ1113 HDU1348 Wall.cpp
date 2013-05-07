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
#define MAX 1010
#define EPS 1e-10
#define FUNC(x) (2*x*acos(-1.0))
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

bool inline cmpByCoordinate(const POINT &lhs,const POINT &rhs)
{
	if(lhs.y != rhs.y)
		return lhs.y<rhs.y;
	else
		return lhs.x<rhs.x;
}

double inline Distance(const POINT &lhs,const POINT &rhs)
{
	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

bool inline cmpByPolarAngle(const POINT &lhs,const POINT &rhs)
{
	double temp=crossProduct(tree[0],lhs,rhs);
	if (fabs(temp)<EPS)
		return	Distance(lhs,tree[0])<Distance(rhs,tree[0]);
	else
		return temp<0;
}

double graham(const int &n)
{
	POINT *stk[MAX];

	sort(tree,tree+n,cmpByCoordinate);
	sort(tree+1,tree+n,cmpByPolarAngle);	//这样排序使得各点相对于tree[0]成扇形分布

	for(int i=0;i<3;++i)
		stk[i]=&tree[i];
	int top=2;

	for(int i=3;i<n;++i)
	{
		while(1)
		{
			POINT *a = stk[top];
			POINT *b = stk[top-1];
			if(crossProduct(*a,*b,tree[i])<0)
				--top;
			else
				break;
		}
		stk[++top]=&tree[i];
	}

	double ans=0.0;
	for(int i=0;i<top;++i)
		ans+=Distance(*stk[i],*stk[i+1]);
	ans+=Distance(*stk[0],*stk[top]);
	return ans;

}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n;
	double l;
	int ncases;

	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d%lf",&n,&l);
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&tree[i].x,&tree[i].y);

		double ans=graham(n)+FUNC(l);
		printf("%.0lf\n",ans);
		if(ncases>0)
			printf("\n");
	}

	return 0;
}
