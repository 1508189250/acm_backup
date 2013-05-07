/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-09-13 12:53
 # Filename: ZOJ3171 The Hidden 7's.cpp
 # Description : 
 ******************************************************************************/
// ZOJ3171 The Hidden 7's.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	char seven[]=" seven";
	char str[10010];
	long long unsigned dp[6];

	while(gets(str) && strlen(str))
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;str[i];++i)
		{
			if (str[i]>='A' && str[i]<='Z')
			{
				str[i]+='a'-'A';
			}
			for(int j=5;j>0;--j)
				if(str[i]==seven[j])	//dp[j]��ʾ����seven[j]�ж�����·�������str[i]��seven[j]��ȣ���dp[j]�Ͷ��dp[j-1]��·����������01��������Ϊstr�е�ÿ���ַ�ֻ��ȡһ�Σ�����Ҫ�Ӻ���ǰ������
					dp[j]=dp[j-1]+dp[j];
		}
		printf("%llu\n",dp[5]);
	}
	return 0;
}
