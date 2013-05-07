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
#include <map>
#define MAX 100010
using namespace std;

long long num[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
			scanf("%lld",&num[i]);

		int t;
		long long ll_max=-1;

		for(int i=0;i<n-1;++i)
			if(llabs(num[i]-num[i+1])>ll_max)
				ll_max=llabs(num[t=i]-num[i+1]);
		printf("%d %d\n",t+1,t+2);

	}

  return 0;
}
