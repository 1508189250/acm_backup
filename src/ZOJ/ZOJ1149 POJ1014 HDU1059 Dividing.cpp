/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-02 20:46
 # Filename: ZOJ1149 POJ1014 HDU1059 Dividing.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

using namespace std;
int dp[450000],value[200000];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ind=1;
	int num[7];
	while(scanf("%d %d %d %d %d %d",&num[1],&num[2],&num[3],&num[4],&num[5],&num[6])!=EOF)
	{
		int total=0;
		for(int i=1;i<=6;++i)
			total+=i*num[i];
		if(total==0) break;
		printf("Collection #%d:\n",ind++);
		if(total%2)
		{
			printf("Can't be divided.\n\n");
			continue;
		}
		int half=total/2;
		int ncount=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=6;++i)	//二进制拆分
		{
			int temp=num[i];
			if(temp==0) continue;
			int pow2=1;
			while(temp>pow2)
			{
				value[ncount++]=pow2*i;
				temp-=pow2;
				pow2*=2;
			}
			if(temp) value[ncount++]=temp*i;
		}
		for(int i=0;i<ncount;++i)	//转变为0/1背包问题
			for(int j=half;j>=value[i];--j)
				dp[j]=max(dp[j],dp[j-value[i]]+value[i]);
		if(dp[half]==half)
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");
	}

	return 0;
}
