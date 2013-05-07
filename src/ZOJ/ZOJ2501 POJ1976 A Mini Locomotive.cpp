/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-24 19:49
 # Filename: ZOJ2501 POJ1976 A Mini Locomotive.cpp
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
#define MAX 50010
using namespace std;

int dp[MAX][4];
int temp[MAX],passenger[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases,n,max_coach;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&temp[i]);
		memset(dp,0,sizeof(dp));
		memset(passenger,0,sizeof(passenger));
		scanf("%d",&max_coach);

		for(int i=1;i<=n;++i)
			if(i>max_coach)
				passenger[i]=passenger[i-1]+temp[i]-temp[i-max_coach];
			else
				passenger[i]=passenger[i-1]+temp[i];


		int sum=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=3;++j)
			{
				if(i<=j*max_coach)
					dp[i][j]=dp[i-1][j]+temp[i];
				else
					dp[i][j]=max(dp[i-1][j], dp[i-max_coach][j-1]+passenger[i]);
			}

		printf("%d\n",dp[n][3]);

	}

  return 0;
}
