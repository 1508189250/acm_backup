/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-13 16:07
 # Filename: acm.cpp
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
using namespace std;

const int kMAX=400;
const int inf=1<<16;

int dp[kMAX],value[kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  scanf("%d",&ncase);

  while(ncase--)
  {
      for(int j=0;j<kMAX;++j)
        dp[j]=inf;
		dp[0]=0;

		for(int i=1;i<=6;++i)
			scanf("%d",&value[i]);

    for(int k=0;k<;++k)
		for(int i=1;i<=6;++i)
		{
			for(int j=value[i];j<kMAX;++j)
        if(dp[j]>dp[j-value[i]]+1)
          dp[j]=dp[j-value[i]]+1;
      for(int j=kMAX-1-value[i];j>=0;--j)
        if(dp[j]>dp[j+value[i]]+1)
          dp[j]=dp[j+value[i]]+1;
		}

    int ans=0;  
    int sum=0;  
    for(int i=1;i<=100;i++)  
    {  
      sum+=dp[i];  
      if(dp[i]>ans)ans=dp[i];  
    }  
    printf("%.2f %d\n",double(sum)/100.0,ans);  
  }

  return 0;
}