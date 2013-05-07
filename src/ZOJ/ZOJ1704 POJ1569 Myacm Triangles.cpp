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
#define EPS 1e-6
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
  double x,y;
}point[MAX];

/************************************************************************/
/*double的大小判断                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_ou_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

double inline area(const POINT &a,const POINT &b,const POINT &c)
{
	return fabs(0.5*((c.y-a.y)*(b.x-a.x)-(b.y-a.y)*(c.x-a.x)));
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n;
	char ch;
  int ans[3]={0,1,2};

	while(scanf("%d",&n)&&n)
	{
		for(int i=0;i<n;++i)
		{
			getchar();
			scanf("%c%lf%lf",&ch,&point[i].x,&point[i].y);
		}

		double maxarea=0.0;;

		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				for(int k=j+1;k<n;++k)
				{
					double tmp=area(point[i],point[j],point[k]);
					if(_less_or_equal(tmp,maxarea))
						continue;
					bool flag=true;

					for(int l=0;l<n;++l)
						if(l!=i && l!=j &&l!=k)
						{
							double tmp1=area(point[i],point[j],point[l]);
							double tmp2=area(point[j],point[k],point[l]);
							double tmp3=area(point[k],point[i],point[l]);
              double temp=tmp1+tmp2+tmp3;
							if(_equal(temp,tmp))
							{
								flag=false;
								break;
							}
						}
					if(flag)
					{
						maxarea=tmp;
						ans[0]=i;ans[1]=j;ans[2]=k;
					}
				}
		printf("%c%c%c\n",ans[0]+'A',ans[1]+'A',ans[2]+'A');
	}

  return 0;
}
