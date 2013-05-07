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
#include <functional>
#include <ctype.h>

using namespace std;

//a=OA,b=OB, c=OC, l=AB, m=BC, n=CA
double inline volume(const double &a,const double &b,const double &c,
                     const double &l,const double &m,const double &n)
{
  return sqrt(4.0*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-
    b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n)-c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l) 
    +(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n))/12.0;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	double a,b,c,l,m,n;

	while(~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&l,&m,&n))
  {
    double v=volume(a,b,c,l,n,m);
    long long int ans=v*10000;
		printf("%.4lf\n",(double)ans/10000.0);
  }

  return 0;
}
