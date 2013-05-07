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

int dp[MAX],pre[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,p,m,t;
  
  while(~scanf("%d%d%d%d",&n,&p,&m,&t))
  {
	  memset(dp,0,sizeof(dp));
	  memset(pre,0,sizeof(pre));
	  pre[p]=1;
	  for(int i=1;i<=m;++i)
    {
		  for(int j=1;j<=n;++j)
		  {
			  if(j==1)
				  dp[j+1]+=pre[j];
			  else if(j==n)
				  dp[j-1]+=pre[j];
			  else
			  {
				  dp[j+1]+=pre[j];
				  dp[j-1]+=pre[j];
			  }
		  }
      memcpy(pre,dp,sizeof(dp));
      memset(dp,0,sizeof(dp));
    }
	  printf("%d\n",pre[t]);
  }

  return 0;
}
