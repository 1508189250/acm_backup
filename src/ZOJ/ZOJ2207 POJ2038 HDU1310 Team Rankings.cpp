// ZOJ2207 POJ2038 HDU1310 Team Rankings.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG


#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
// #include <memory.h>

using namespace std;

char voter[122][6],input[110][6];

int ranking(char *lhs,char *rhs)
{
	int sum=0;
	for(int i=0;i<5;++i)
	{
		char ch=lhs[i];
		int index;
		for(index=0;index<5;++index)
			if(ch==rhs[index]) break;
		
		for(int j=i+1;j<5;++j)
		{
			ch=lhs[j];
			for(int k=0;k<index;++k)
				if(ch==rhs[k])
				{
					++sum;
					break;
				}
		}
	}
	return sum;
}

int visit[5];
char temp[6];
int ncount;
void dfs(int d)
{
	if(d==5)
		strcpy(voter[ncount++],temp);
	else
	{
		for(int i=0;i<5;++i)
			if(!visit[i])
			{
				temp[d]=i+'A';
				visit[i]=1;
				dfs(d+1);
				visit[i]=0;
			}
	}
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n;
	char result[6];
	ncount=0;
	dfs(0);
	while(scanf("%d",&n) && n)
	{
		int minrank=1<<30;
		memset(visit,0,sizeof(0));
		getchar();
		for(int i=0;i<n;++i)
			scanf("%s",&input[i]);

		for(int i=0;i<120;++i)
		{
			int sum=0;
			for(int j=0;j<n;++j)
			{
				sum+=ranking(voter[i],input[j]);
			}
			if(sum<minrank)
			{
				minrank=sum;
				strcpy(result,voter[i]);
			}
		}
		printf("%s is the median ranking with value %d.\n",result,minrank);
	}

	return 0;
}
