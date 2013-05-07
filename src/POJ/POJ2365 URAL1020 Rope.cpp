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
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define MAX 120
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
  double x,y;
}point[MAX];

double length(POINT *pArray,const int &n)
{
  double ans=0.0;

  for(int i=0;i<n;++i)
  {
    ans+=sqrt((pArray[i].x-pArray[(i+1)%n].x)*(pArray[i].x-pArray[(i+1)%n].x)+
      (pArray[i].y-pArray[(i+1)%n].y)*(pArray[i].y-pArray[(i+1)%n].y));
  }

  return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n;
	double r;
	const double PI=acos(-1.0);

	while(~scanf("%d%lf",&n,&r))
	{
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&point[i].x,&point[i].y);
		double ans=length(point,n)+2*PI*r;
		printf("%.2lf\n",ans);
	}

  return 0;
}
