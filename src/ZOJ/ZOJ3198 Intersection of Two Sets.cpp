// ZOJ3198 Intersection of Two Sets.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <set>
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
	set<int> myset;
	int ncases;
	int m,n,temp;

	scanf("%d",&ncases);

	while(ncases--)
	{
		myset.clear();

		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
			scanf("%d",&temp);
			myset.insert(temp);
		}

		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&temp);
			myset.insert(temp);
		}

		printf("%d\n",m+n-myset.size());

	}


	return 0;
}

