// ZOJ1101 Gamblers.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG


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
#include <set>

using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	set<int> mset;
	int n;
	int num[1010];

	while(scanf("%d",&n) && n)
	{
		mset.clear();
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&num[i]);
			mset.insert(num[i]);
		}
		if (n<4)
		{
			printf("no solution\n");
			continue;
		}
		sort(num,num+n,greater<int>());
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				if(i==j) continue;
				for(int k=0;k<n;++k)
				{
					if(i==k || j==k) continue;
					int remain=num[i]-num[j]-num[k];
					if(mset.find(remain)!=mset.end() && remain!=num[i] && remain!=num[j] && remain!=num[k])
					{
						printf("%d\n",num[i]);
						goto end;
					}
				}
			}
		printf("no solution\n");
end:
		continue;
	}

	return 0;
}

