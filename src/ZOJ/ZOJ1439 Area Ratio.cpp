// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

double inline distance(const int &x1,const int &y1,const int &z1,const int &x2,const int &y2,const int &z2)
{
	return sqrt(((double)x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int x1,x2,x3,y1,y2,y3,z1,z2,z3;

	while(scanf("%d %d %d %d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3)!=EOF)
	{
		double a=distance(x1,y1,z1,x2,y2,z2);
		double b=distance(x1,y1,z1,x3,y3,z3);
		double c=distance(x3,y3,z3,x2,y2,z2);
		double p=0.5*(a+b+c);
		double S=sqrt(p*(p-a)*(p-b)*(p-c)),C=2*p;
		double r=2*S/C;
		//double R=2*a*b*c/sqrt(pow(a*a+b*b+c*c,2)-2*(pow(a,4)+pow(b,4)+pow(c,4)));
		double R=a*b*c/(4*S);
		printf("%.3lf\n",pow(r/R,2));
	}

	return 0;
}
