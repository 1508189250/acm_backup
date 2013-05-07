#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 100010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	double vs,r,c,w;
	int n;

	scanf("%lf%lf%lf%d",&vs,&r,&c,&n);
	while(n--)
	{
		scanf("%lf",&w);
		double ans=((w*r*c*vs)/sqrt(r*r*c*c*w*w+1));
		printf("%.3lf\n",ans);
	}

  return 0;
}
