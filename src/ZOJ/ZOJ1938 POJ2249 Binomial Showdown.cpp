// ZOJ1938 POJ2249 Binomial Showdown.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



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

int main(void)
{
	int n,k;

	while(scanf("%d %d",&n,&k)&&n)
	{
		if (k==0)
		{
			printf("1\n");
			continue;
		}
		if(k>n-k)
			k=n-k;
		long long int result=1;
		for(int i=1;i<=k;++i)
		{
			result*=n--;
			result/=i;
		}
		printf("%lld\n",result);
		
	}


	return 0;
}
