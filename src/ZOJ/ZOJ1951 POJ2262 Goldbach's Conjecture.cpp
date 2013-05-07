// ZOJ1951 POJ2262 Goldbach's Conjecture.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>
#include <assert.h>
#include <ctype.h>

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int notprime[1000100];
	memset(notprime,0,sizeof(notprime));
	for(int i=2;i<1000100;++i)
		for(int j=2;i*j<1000100;++j)
			notprime[i*j]=1;

	int n;
	while(scanf("%d",&n) && n)
	{
		int flag=0;
		for(int i=3;i<=n/2;++i)
			if(!notprime[i] && !notprime[n-i])
			{
				flag=i;
				break;
			}

			if (flag)
			{
				printf("%d = %d + %d\n",n,flag,n-flag);
			} 
			else
			{
				printf("Goldbach's conjecture is wrong.\n");
			}
	}


	return 0;
}

