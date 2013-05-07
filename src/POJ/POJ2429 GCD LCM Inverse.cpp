// POJ2429 GCD LCM Inverse.cpp : Defines the entry point for the console application.
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

#define MAX 1000000

using namespace std;

// int num[MAX];
// int dp[MAX];

int gcd(const int &lhs,const int &rhs)
{
	return rhs==0?lhs:gcd(rhs,lhs%rhs);
}

int main(void)
{
	int x,y,temp;

	while(scanf("%d %d",&x,&y)!=EOF)
	{
		temp=y/x;
		int result;
// 		int ncount=0;
		int upper=(int)sqrt((double)temp);

		for (int i=upper;i>=1;--i)
		{
			if(temp%i==0 && gcd(temp/i,i)==1)
			{
				result=i;
				break;
			}
		}
		printf("%d %d\n",result*x,y/result);
// 		int sum=upper;
// 		memset(dp,0,sizeof(dp));

// 		for(int i=2;i<=upper;++i)
// 		{
// 			if(temp%i==0)
// 			{
// 				temp /=i;
// 				int tmp=i;
// 				sum+=i;
// 				while(temp%i==0)
// 				{
// 					tmp*=i;
// 					sum+=i;
// 					temp /=i;
// 				}
// 				num[ncount++]=tmp;
// 			}
// 		}
// 
// 		dp[1]=1;
// 
// 		for(int i=0;i<ncount;++i)
// 			for(int j=sum;j>=num[i];--j)
// 			{
// 				if(j%num[i]==0)
// 					dp[j]=max( dp[j] ,  dp[j/num[i]] * num[i]);
// 			}
// 
// 		for (int i=sum;i>=1;--i)
// 		{
// 			if (dp[i])
// 			{
// 				dp[sum]=dp[i];
// 				break;
// 			}
// 		}
// 		printf("%d %d\n",dp[sum]*x,y/(dp[sum]));
	}

	
	return 0;
}

