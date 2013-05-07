// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
using namespace std;

int n,num[110],temp[110];
bool isEqual()
{
	for(int i=0;i<n;++i)
	{
		if(num[i]%2)
			++num[i];
	}
	int temp=num[0];
	for (int i=0;i<n;++i)
	{
		if(temp!=num[i])
			return false;
	}
	return true;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int times;

	while(scanf("%d",&n) && n)
	{
		times=0;
		for (int i=0;i<n;++i)
			scanf("%d",&num[i]);
		while(!isEqual())
		{
			++times;
			for(int i=0;i<n-1;++i)
			{
				temp[i+1]=num[i]/2;
				num[i]/=2;
			}
			temp[0]=num[n-1]/2;
			num[n-1]/=2;
			for (int i=0;i<n;++i)
				num[i]+=temp[i];
		}

		printf("%d %d\n",times,num[0]);
	}

	return 0;
}
