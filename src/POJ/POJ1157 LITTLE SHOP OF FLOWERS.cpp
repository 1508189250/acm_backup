/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-16 20:11
 # Filename: POJ1157 LITTLE SHOP OF FLOWERS.cpp
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
#define MAX 110
using namespace std;

int dp[MAX][MAX];
int value[MAX][MAX];

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
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				scanf("%d",&value[i][j]);
				dp[i][j]=INT_MIN;
			}

		for(int i=1;i<=n;++i)
		{
			dp[i][i]=dp[i-1][i-1]+value[i][i];
			for(int j=i+1;j<=m;++j)
				dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+value[i][j]);
		}
		printf("%d\n",dp[n][m]);
	}

  return 0;
}
