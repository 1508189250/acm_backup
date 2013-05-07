// #include "stdafx.h"
// #define DEBUG
// 
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 1010
using namespace std;

int num[MAX],prime[MAX];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	memset(num,0,sizeof(num));
	for(int i=2;i<MAX;++i)
		if(num[i]==0)
			for(int j=2;j*i<MAX;++j)
				num[i*j]=1;
	int cou=0,n,c;
	for(int i=1;i<MAX;++i)
		if(num[i]==0)
			prime[cou++]=i;

	while(~scanf("%d%d",&n,&c))
	{
		int len;
		printf("%d %d:",n,c);
		for(len=0;len<cou;++len)
			if(prime[len]>n)
				break;
		if(len%2)	//odd
		{
			int mid=len/2;
			int begin;
			if(c>mid)
			{
				begin=0,c=len;
			}
			else
			{
				begin=mid-c+1;
				c=c*2-1;
			}		
			for(int i=begin;i<begin+c;++i)
				printf(" %d",prime[i]);
		}
		else //even
		{
			int mid=len/2;
			int begin;
			if(c>mid)
			{
				begin=0,c=len;
			}
			else
			{
				begin=mid-c;
				c=2*c;
			}
			for(int i=begin;i<begin+c;++i)
				printf(" %d",prime[i]);
		}
		printf("\n\n");
	}

	return 0;
}
