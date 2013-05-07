/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-16 21:41
 # Filename: ZOJ1894 POJ2465 Adventures in Moving - Part IV.cpp
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
#define inf 20000000
using namespace std;


int dp[MAX][MAX*2],dis[MAX],price[MAX],total;


int main(void)
{
#ifdef DEBUG  
	freopen("../stdin.txt","r",stdin);
	freopen("../stdout.txt","w",stdout); 
#endif  


	char str[100];


	while(~scanf("%d",&total))
	{
		int n=1;
		getchar();
		while(gets(str) && strlen(str))
		{
			sscanf(str,"%d%d",&dis[n],&price[n]);
			++n;
		}
		dis[n]=total;
		price[n++]=inf;
		for(int i=0;i<MAX;++i)
			for(int j=0;j<MAX*2;++j)
				dp[i][j]=inf;

		dp[0][100]=0;

		for(int i=1;i<n;++i)
			for(int j=0;j<=200;++j)
			{
				for(int k=dis[i]-dis[i-1];k<=200;++k)
					if(dp[i-1][k]!=inf)
					{
						if(k-(dis[i]-dis[i-1])>j)
							break;
						else
							dp[i][j]=min(dp[i][j],dp[i-1][k]+(j-(k-dis[i]+dis[i-1]))*price[i]);
					}
			}

			int ans=dp[n-1][100];

			if(ans==inf)
				printf("Impossible\n");
			else
				printf("%d\n",ans);

	}


		return 0;
}
