// ZOJ2835 Magic Square.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>


using namespace std;

int main(void)
{
	int num[11000];
	int matrix[15][15];
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		int flag=0;
		memset(num,0,sizeof(num));
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				scanf("%d",&matrix[i][j]);
				++num[matrix[i][j]];
				if(num[matrix[i][j]]>1)
					flag=1;
			}

		if(flag)
		{
			printf("No\n");
			continue;
		}

		int sum=0;
		for(int j=0;j<n;++j)
			sum+=matrix[0][j];

		for(int i=0;i<n;++i)
		{
			int temp=0;
			for(int j=0;j<n;++j)
				temp+=matrix[i][j];
			if(temp!=sum)
				flag=1;
		}
		if(flag)
		{
			printf("No\n");
			continue;
		}

		for(int j=0;j<n;++j)
		{
			int temp=0;
			for(int i=0;i<n;++i)
				temp+=matrix[i][j];
			if(temp!=sum)
				flag=1;
		}
		if(flag)
		{
			printf("No\n");
			continue;
		}

		int temp=0;
		for(int i=0;i<n;++i)
			temp+=matrix[i][i];
		if(sum!=temp)
		{
			printf("No\n");
			continue;
		}

		temp=0;
		for(int i=0;i<n;++i)
			temp+=matrix[i][n-i-1];
		if(sum!=temp)
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
	return 0;
}
