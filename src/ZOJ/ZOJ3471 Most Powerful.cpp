/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-17 08:54
 # Filename: ZOJ3471 Most Powerful.cpp
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
#include <limits.h>

using namespace std;

int map[15][15];
int dp[1<<11];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n;
	while(scanf("%d",&n)&&n)
	{
		int maxint=1<<n;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&map[i][j]);
		memset(dp,0,sizeof(dp));

		for(int i=0;i<maxint;++i)		//״̬��0��2^n-1��
			for(int j=0;j<n;++j)
			{
				if(i & (1<<j)) continue;	//�����״̬i�е�j��ԭ������ʧ��������
				for(int k=0;k<n;++k)
				{
					if(i & (1<<k)) continue;		//�����״̬i�е�k��ԭ������ʧ��������
					if(j==k) continue;			//�����ײ������ԭ����ͬ��������
					dp[i | (1<<k)] = max(dp[i|(1<<k)],dp[i]+map[j][k]);	//״̬ת�Ʒ���
				}
			}
		int ans=0;
		for(int i=0;i<maxint;++i)
			if(dp[i]>ans)
				ans=dp[i];
		printf("%d\n",ans);
	}

	return 0;
}
