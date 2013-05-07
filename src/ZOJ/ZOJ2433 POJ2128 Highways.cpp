// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

#include <math.h>
#include <algorithm>
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
using namespace std;

int city[50010];
int n;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	
	int ncase;
	scanf("%d",&ncase);
	int flag=1;
	while(ncase--)
	{
		if(flag)
			flag=0;
		else
			printf("\n");
		scanf("%d",&n);
		city[1]=0;
		for(int i=2;i<=n;++i)
			scanf("%d",&city[i]);
		int minlength=INT_MAX;

		if(n<=3)
		{
			printf("0\n");
			continue;
		}

		int find;
		for(int i=3;i<n;++i)
			if (city[i]-city[1]+city[n]-city[i-1]<minlength)
			{
				minlength = city[i]-city[1]+city[n]-city[i-1];
				find=i;
			}
		printf("%d\n",minlength);
		printf("%d 1 %d %d\n",find,n,find-1);
	}

	return 0;
}
