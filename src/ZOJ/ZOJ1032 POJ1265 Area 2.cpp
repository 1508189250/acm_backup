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
	int x,y;
}point[MAX];


/************************************************************************/
/* 求多边形的面积                                                       */
/************************************************************************/
double area(POINT *pArray,const int &n)
{
	double s1 = 0.0,s2 = 0.0;  
	for(int i=0; i<n; i++)  
	{  
		s1 += pArray[(i+1)%n].y * pArray[i].x;  
		s2 += pArray[(i+1)%n].y * pArray[(i+2)%n].x;  
	}  
	return fabs(s1 - s2)/2.0;  
}

int gcd(const int &lhs,const int &rhs)
{
	return rhs==0?lhs:gcd(rhs,lhs%rhs);
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	int n,dx,dy;
	int indot,ondot;
	double darea;

	scanf("%d",&ncases);

	for(int nc=1;nc<=ncases;++nc)
	{
		scanf("%d",&n);
		scanf("%d%d",&dx,&dy);
		point[0].x=dx;
		point[0].y=dy;
		ondot = gcd(abs(dx),abs(dy));
		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&dx,&dy);
			ondot += gcd(abs(dx),abs(dy));
			point[i].x=point[i-1].x+dx;
			point[i].y=point[i-1].y+dy;
		}
		darea = area(point,n);
		indot = (int)darea+1-ondot/2;
		printf("Scenario #%d:\n%d %d %.1lf\n\n",nc,indot,ondot,darea);
	}

	return 0;
}
