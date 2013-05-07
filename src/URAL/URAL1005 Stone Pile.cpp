#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
using namespace std;
int dp[2000010];

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n;
	int weight[25];
	while(~scanf("%d",&n))
	{
		int total=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&weight[i]);
			total +=weight[i];
		}

		int half=total/2;
		memset(dp,0,sizeof(0));

		for(int i=0;i<n;++i)
			for(int j=half;j>=weight[i];--j)
				dp[j]=max(dp[j],dp[j-weight[i]]+weight[i]);
		
		printf("%d\n",abs(total-2*dp[half]));
	}

  return 0;
}
