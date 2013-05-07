/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-14 18:55
 # Filename: POJ2593 Max Sequence.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#define MAX 100010
using namespace std;

long long num[MAX],left_dp[MAX],right_dp[MAX];
int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases,n;

	while(scanf("%d",&n) &&n)
	{
		long long total,now;

		for(int i=0;i<n;++i)
		{
			scanf("%lld",&num[i]);
			if(i==0)
			{
				left_dp[i]=total=now=num[0];
				continue;
			}
			now+=num[i];
 			now=max(num[i],now);
			total=max(total,now);
			left_dp[i]=total;
		}

		total=num[n-1];
		now=num[n-1];
    right_dp[n-1]=num[n-1];
		for(int i=n-2;i>=0;--i)
		{
			now+=num[i];
 			now=max(num[i],now);
			total=max(total,now);
			right_dp[i]=total;
		}

		total=-1000000ll;
		for(int i=1;i<n;++i)
			total=max(total,left_dp[i-1]+right_dp[i]);
		printf("%lld\n",total);
	}

  return 0;
}
