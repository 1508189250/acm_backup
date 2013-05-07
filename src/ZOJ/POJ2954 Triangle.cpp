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
using namespace std;

int gcd(const int &lhs,const int &rhs)
{
	return rhs==0?lhs:gcd(rhs,lhs%rhs);
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int x1,y1,x2,y2,x3,y3;

	while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3) &&(x1||x2||x3||y1||y2||y3))
	{
		double area=x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
		area = fabs(area)/2;
		int onedge=gcd(abs(x1-x2),abs(y1-y2))+gcd(abs(x2-x3),abs(y2-y3))+gcd(abs(x1-x3),abs(y1-y3));
		int ans = area+1-onedge/2;
		printf("%d\n",ans);
	}

	return 0;
}
