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

double dis(const double &x,const double &y,const double &a,const double &b)
{
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	const double PI=acos(-1.0);
	double ans[MAX];
	ans[1]=0.0;
	double r1=0.0,r2=0.0;

	for(int i=2;i<MAX;++i)
		ans[i]=sqrt(100.0*(i-1)/PI);

	int ncases;
	double x,y;
	scanf("%d",&ncases);

	for(int nc=1;nc<=ncases;++nc)
	{
		scanf("%lf%lf",&x,&y);
		int ind=1;
		double tmp=dis(x,y,0.0,0.0);
		while(ans[ind]<tmp)
			++ind;
    --ind;
		printf("Property %d: This property will begin eroding in year %d.\n",nc,ind);
	}

	printf("END OF OUTPUT.\n");


  return 0;
}
