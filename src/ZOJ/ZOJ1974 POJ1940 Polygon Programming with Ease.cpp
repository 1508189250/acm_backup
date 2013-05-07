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
#define maxlen 5000
using namespace std;

void func(const double  *lhs,double *rhs,const int &n)
{
	double tmp=lhs[0];
	for(int i=1;i<n;++i)
	{
		if(i%2)
			tmp-=lhs[i];
		else
			tmp+=lhs[i];
	}
	rhs[0]=tmp;
	for(int i=1;i<n;++i)
		rhs[i]=2*lhs[i-1]-rhs[i-1];
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	double xaxis[maxlen],yaxis[maxlen],xans[maxlen],yans[maxlen];
	int n;

	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&xaxis[i],&yaxis[i]);
		func(xaxis,xans,n);
		func(yaxis,yans,n);
		printf("%d",n);
		for(int i=0;i<n;++i)
			printf(" %.6lf %.6lf",xans[i],yans[i]);
		printf("\n");
	}
	

  return 0;
}
