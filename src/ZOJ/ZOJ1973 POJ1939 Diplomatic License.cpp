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
#define maxlen 1000
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	double xaxis[maxlen],yaxis[maxlen];
	int n;

	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
			scanf("%lf%lf",&xaxis[i],&yaxis[i]);

		printf("%d",n);
		for(int i=0;i<n;++i)
			printf(" %.6lf %.6lf",(xaxis[i]+xaxis[(i+1)%n])/2,(yaxis[i]+yaxis[(i+1)%n])/2);

		printf("\n");
	}


  return 0;
}
