/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-22 20:43
 # Filename: ZOJ1425 POJ1692 Crossed Matchings.cpp
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

int array_a[MAX],array_b[MAX];
int dp[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases,n,m;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			scanf("%d",&array_a[i]);
		for(int i=1;i<=m;++i)
			scanf("%d",&array_b[i]);

		memset(dp,0,sizeof(dp));
		
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(array_a[i]==array_b[j])
					continue;

        //找到一个交叉匹配
				int k=i-1,l=j-1;
				for(;k>0;--k)
					if(array_a[k]==array_b[j])
						break;
				for(;l>0;--l)
					if(array_a[i]==array_b[l])
						break;

        //如果找到一个交叉匹配
				if(k>0 && l>0)
					dp[i][j]=max(dp[i][j],dp[k-1][l-1]+1);
			}
		printf("%d\n",dp[n][m]*2);

	}

  return 0;
}
