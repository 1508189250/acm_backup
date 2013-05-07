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

const double PI = acos(-1.0);

double func(const double d,const double r)
{
	double half = d/2.0;
	double diagonal = 0.5*sqrt(2.0)*d;
	if(r<=half)
		return PI*r*r;
	if(r>=diagonal)
		return d*d;

	double alaph=acos(half/r);
	double x=r*sin(alaph);
	return PI*r*r-4*(alaph*r*r - x*half);
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	double d,r;

	while(~scanf("%lf%lf",&d,&r))
	{
		printf("%.3lf\n",func(d,r));
	}

  return 0;
}
