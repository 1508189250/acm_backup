/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-17 20:09
 # Filename: POJ1160 Post Office.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 1010
using namespace std;

int dp[MAX][MAX],coord[MAX],cost[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,m;

	while(~scanf("%d%d",&n,&m))
	{
    memset(dp,0,sizeof(dp));
    memset(cost,0,sizeof(cost));
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
				dp[i][j]=INT_MAX;

		for(int i=1;i<=n;++i)
			scanf("%d",&coord[i]);

		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j)
      {
        int mid=(i+j)>>1;
        for(int k=i;k<=j;++k)
				cost[i][j]+=abs(coord[mid]-coord[k]);
      }

    for(int j=1;j<=n;++j)
      dp[1][j]=cost[1][j];

		for(int i=2;i<=m;++i)
			for(int j=i;j<=n;++j)
        for(int k=i-1;k<j;++k)
          //��ǰ i-1 ���ʾָ���ǰ k ����ׯ���� i ���ʾָ��ǵ� k+1 �� j ����ׯ����״̬ת�Ʒ���Ϊ
          //dp[i][j] = min { dp[i-1][k] + cost[k+1][j] }    ( i-1 =< k < j ����i-1��ʼ����Ϊǰi-1���ʾֳ�ʼֻ������1��i-1����ׯ)
				  dp[i][j]=min(dp[i][j],dp[i-1][k]+cost[k+1][j]);

		printf("%d\n",dp[m][n]);

	}

  return 0;
}
