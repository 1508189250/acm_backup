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
#define  MAX 1000000

using namespace std;


int notPrime[MAX];
int prime[MAX];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	memset(notPrime,0,sizeof(notPrime));
	int endpos = (int)sqrt(MAX*1.0);
	for(int i=2;i<=endpos;++i)
		if(!notPrime[i])
			for(int j=2;i*j<MAX;++j)
				notPrime[i*j]=1;
	int cou=0;
	for(int i=2;i<MAX;++i)
		if(!notPrime[i])
			prime[cou++]=i;
	int num;
	while(scanf("%d",&num)&&num)
	{
		int ans=0;
		for(int i=0;i<cou && prime[i]<=num/2 ;++i)
			if(!notPrime[num-prime[i]])
			{
				ans=prime[i];
				break;
			}

		printf("%d = %d + %d\n",num,ans,num-ans);
	}

	return 0;
}
