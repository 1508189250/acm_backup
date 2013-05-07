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
#include <limits.h>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

#define MAX 65536

int notPrimer[MAX];
int num[MAX];

int gcd(int lhs,int rhs)
{
	if(lhs<rhs) swap(lhs,rhs);
	return rhs==0?lhs:gcd(rhs,lhs%rhs);
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	memset(notPrimer,0,sizeof(notPrimer));
	for(int i=2;i<=MAX;++i)
		if(notPrimer[i]==0)
			for(int j=i+i;j<MAX;j+=i)
				notPrimer[j]=1;

	long long x;
	while(scanf("%lld",&x)&& x)
	{
		memset(num,0,sizeof(num));
		for(int i=2;i<MAX;)
			if(x==1 || x==-1) break;
			else if(notPrimer[i]==0 && x%i==0)
			{
				++num[i];
				x/=i;
			}
			else
				++i;
		int ans=0;
		if(x<0)
			for(int i=0;i<MAX;++i)
				if(num[i])
				{
					while(num[i]%2==0)
						num[i]/=2;
					ans=num[i];
				}
		for(int i=2;i<MAX;++i)
			if(num[i])
				ans=gcd(ans,num[i]);
		
		if (ans==0)
			ans=1;
		printf("%d\n",ans);
	}
	
	

	return 0;
}
