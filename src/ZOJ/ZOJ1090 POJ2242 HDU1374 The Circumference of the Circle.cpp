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
#define PI 3.141592653589793
using namespace std;

struct POINT
{
	double x,y;
};

double inline Distance(const POINT &lhs,const POINT &rhs)
{
	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	double a,b,c;
	POINT p,q,r;

	while(~scanf("%lf%lf%lf%lf%lf%lf",&p.x,&p.y,&q.x,&q.y,&r.x,&r.y))
	{
		a=Distance(p,q);
		b=Distance(p,r);
		c=Distance(q,r);

		double ans=a*b*c/sqrt((a*a+b*b+c*c)*(a*a+b*b+c*c)-2*(a*a*a*a+b*b*b*b+c*c*c*c));

		printf("%.2lf\n",2*PI*ans);
	}

	return 0;
}
