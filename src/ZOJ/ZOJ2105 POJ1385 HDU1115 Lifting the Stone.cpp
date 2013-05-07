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
#define MAX 1000010
#define EPS 1e-10
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
  double x,y;
};

double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	
//向量ac在ab的方向
{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int t,n;
	scanf("%d",&t);
	POINT a,b,c;

	while(t--)
	{
		double sum_area=0.0,area=0.0;
		double g_x=0.0,g_y=0.0;
		scanf("%d",&n);
		scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
		for(int i=2;i<n;++i)
		{
			scanf("%lf%lf",&c.x,&c.y);
			area = crossProduct(a,b,c)/2.0;
			sum_area+=area;
			g_x += (a.x+b.x+c.x)*area;
			g_y += (a.y+b.y+c.y)*area;
			b=c;
		}
		g_x/=(3*sum_area);
		g_y/=(3*sum_area);

    printf("%.2lf %.2lf\n",g_x==0.0?0.0:g_x,g_y==0.0?0.0:g_y);
	}

  return 0;
}
