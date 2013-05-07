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
#define MAX 2010
using namespace std;

int dp[MAX][MAX];
int value[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,K;

  while(~scanf("%d%d",&n,&K))
  {
	  for(int i=1;i<=n;++i)
		  scanf("%d",&value[i]);
	  sort(value+1,value+1+n);

    memset(dp,0,sizeof(dp));
    for(int i=1;i<=K;++i)
      for(int k=i*2;k<=n;++k)
        dp[i][k]=INT_MAX;

    int t=0;
    for(int i=1;i<=2*K;i+=2)
    {
      t+=(value[i+1]-value[i])*(value[i+1]-value[i]);
      dp[i/2+1][i+1]=t;
    }

	  for(int k=1;k<=K;++k)
		  for(int i=k*2+1;i<=n;++i)
		  {
			  int temp=value[i]-value[i-1];
			  dp[k][i]=min(dp[k-1][i-2]+temp*temp,dp[k][i-1]);
		  }
	  printf("%d\n",dp[K][n]);
  }

  return 0;
}
