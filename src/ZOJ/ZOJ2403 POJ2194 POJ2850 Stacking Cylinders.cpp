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
#define MAX 15
using namespace std;

double coord[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n,ncases;
  scanf("%d",&ncases);

	for (int nc=1;nc<=ncases;++nc)
	{
    scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%lf",&coord[i]);
    sort(coord,coord+n);
		if(n==1)
		{
			printf("%d: %.4lf 1.0000\n",nc,coord[0]);
			continue;
		}
		double x=coord[0];
		double y=1.0;
		for(int i=1;i<n;++i)
		{
      double temp=(coord[i]+coord[0])/2;
			double h=sqrt(4.0-(temp-x)*(temp-x));
			x=(coord[0]+coord[i])/2;
			y+=h;
		}
    printf("%d: %.4lf %.4lf\n",nc,x,y);
	}

  return 0;
}
