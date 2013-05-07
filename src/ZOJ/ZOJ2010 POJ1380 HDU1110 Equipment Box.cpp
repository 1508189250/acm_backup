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
using namespace std;

const double PI=acos(-1.0);

bool check(double a,double b,double x,double y)
{
	if(a>b) swap(a,b);
	if(x>y) swap(x,y);

	for(double d=0.0;2*d<PI;d+=0.003)
	{
		double t1=x*sin(d)+y*cos(d);
		double t2=y*sin(d)+x*cos(d);
		if(t1<=a && t2<=b || t1<=b && t2<=a)
			return true;
	}
	return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int ncases;
	scanf("%d",&ncases);
	double a,b,x,y;

	while(ncases--)
	{
		scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
		if(check(a,b,x,y))
			printf("Escape is possible.\n");
		else
			printf("Box cannot be dropped.\n");
	}

  return 0;
}
