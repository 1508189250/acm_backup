#ifdef _MSC_VER
#define DEBUG
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
#define MAX 100010
using namespace std;

int num[MAX];
long long dp[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;

  while(scanf("%d",&n)&&n)
  {
	  for(int i=0;i<n;++i)
	  {
		  scanf("%d",&num[i]);
		  dp[i]=num[i]*1ll;
	  }
	  long long ans=dp[0];
	  for(int i=1;i<n;++i)
		  for(int j=i-1;j>=0;--j)
			  if(num[j]<num[i] && (num[i]+dp[j]>dp[i]))
			  {
				  dp[i]=dp[j]+num[i];
				  ans=max(ans,dp[i]);
			  }
	  printf("%lld\n",ans);
  }

  return 0;
}
