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
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define EPS 1e-12
using namespace std;

/************************************************************************/
/*doubleµÄ´óÐ¡ÅÐ¶Ï                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_or_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

double l,n,c,L;
const double PI=acos(-1.0);

double func(void)
{
	double beg=0.0,end=PI/2.0;
	double ans;
	
	while(_less(beg,end))
	{
		ans=(beg+end)/2.0;
		if(_less(L*sin(ans),ans*l))
			end=ans;
		else
			beg=ans;
	}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	while(scanf("%lf%lf%lf",&l,&n,&c))
	{
		if(_less(l,0.0) && _less(n,0.0) &&_less(c,0.0))
			break;
		if(_equal(l*n*c,0.0))
		{
			printf("0.000\n");
			continue;
		}

		L=(1+n*c)*l;
		double alaph=func();
    double ans=(1-cos(alaph))*l/2/sin(alaph);
		printf("%.3lf\n",ans);

	}

  return 0;
}
