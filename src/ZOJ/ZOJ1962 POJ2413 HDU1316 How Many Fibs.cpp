// ZOJ1962 POJ2413 HDU1316 How Many Fibs.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"


#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <algorithm>

#define MAX 500

using namespace std;

int num[MAX][130];

bool findLessEqu(const int &index,const int *array)
{
	for(int i=129;i>=0;--i)
	{
		if(num[index][i] != array[i])
			return num[index][i]>array[i];
	}
	return true;
}

int main(void)
{
// 	ifstream cin("data.txt");
	int maxindex=0;
	int arrayA[130],arrayB[130],len[MAX];
	char strA[130],strB[130];
	memset(num,0,sizeof(num));
	num[1][0]=1;
	num[2][0]=2;
	len[1]=len[2]=1;

	for(int i=3;i<MAX;++i)
	{
		int l=len[i-1];
		for(int k=0; k<l; k++)  
		{  
			num[i][k] += (num[i-1][k] + num[i-2][k]);  
		}  
		for(int k=0; k<l; k++)  
			if( num[i][k] > 9 )  
			{  
				num[i][k+1] += num[i][k]/10;  
				num[i][k] %= 10;  
			}  
		if( num[i][l] == 0 )  
			len[i] = l;  
		else  
			len[i] = l+1;  
	}

	while(scanf("%s %s", &strA,&strB)!=EOF && !(strA[0]=='0'&&strB[0]=='0'))
	{
		int nTemp=0;

		memset(arrayA,0,sizeof(arrayA));
		memset(arrayB,0,sizeof(arrayB));

		reverse(strA,strA+strlen(strA));
		reverse(strB,strB+strlen(strB));

		for(int i=0;i<130;++i)
		{
			if(strA[i]>='0' &&strA[i]<='9')
			{
				arrayA[i]=strA[i]-'0';
			}
			else
				break;
		}

		for(int i=0;i<130;++i)
		{
			if(strB[i]>='0' &&strB[i]<='9')
				arrayB[i]=strB[i]-'0';
			else
				break;
		}

		int beg=0,end=0;
		for(int i=1;i<MAX;++i)
		{
			if(findLessEqu(i,arrayA))
			{
				beg=i;
				break;
			}
		}
		for(int i=beg;i<MAX;++i)
		{
			if(findLessEqu(i,arrayB))
			{
				end=i;
				break;
			}
		}

		if (!memcmp(num[end],arrayB,130)/*|| !memcmp(num[0],arrayA,130)&&!memcmp(n)*/)//边界条件一定要注意！
		{
			nTemp=1;
		}

		printf("%d\n",end-beg+nTemp);
	}


	return 0;
}
