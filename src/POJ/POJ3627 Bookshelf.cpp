// POJ3627 Bookshelf.cpp : Defines the entry point for the console application.
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
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>
#include <assert.h>
#include <ctype.h>

using namespace std;

int cows[20010];

int main(void)
{
// 	ifstream cin("data.txt");
	int n,b;

	while(scanf("%d %d",&n,&b)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&cows[i]);
		}

		sort(cows,cows+n,greater<int>());

		int ncount=0;
		int sum=0;
		for(int i=0;i<n;++i)
		{
			sum+=cows[i];
			++ncount;
			if(sum>=b)
				break;
		}

		printf("%d\n",ncount);
		
	}


	return 0;
}
