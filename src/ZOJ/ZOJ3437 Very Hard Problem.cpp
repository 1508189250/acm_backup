// ZOJ3437 Very Hard Problem.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <limits.h>
#include <assert.h>
#include <ctype.h>
#include <map>

using namespace std;

int main(void)
{
	char sign[10],num[100];
	int base;
	long long n;

	while(scanf("%s%d%s",sign,&base,num)!=EOF)
	{
		n=strtoll(num,NULL,base);
		if(sign[0]=='~')
            printf("%lld\n",~n); 
		else if(sign[0]=='!')
			printf("%d\n",!n);
		else
		{
			if(n==LLONG_MIN)
				printf("%llu\n",(long long unsigned)n);
			else
				printf("%lld\n",-n);  
		}
	}

	return 0;
}
