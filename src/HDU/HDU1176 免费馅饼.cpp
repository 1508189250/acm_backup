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

int dp[20][MAX],cookie[20][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int n,x,t,max_t;

  while(scanf("%d",&n) && n)
  {
    memset(dp,0,sizeof(dp));
    memset(cookie,0,sizeof(cookie));
    max_t=0;
    for(int i=0;i<n;++i)
    {
      scanf("%d%d",&x,&t);
      ++x;
      ++cookie[x][t];
      max_t=max(max_t,t);
    }
    int ans=0;
    for(int i=1;i<=max_t;++i)
      for(int j=1;j<=11;++j)
      {
        int t=dp[j][i-1];
        t=max(t,dp[j-1][i-1]);
        t=max(t,dp[j+1][i-1]);
        dp[j][i]=t;

        if(cookie[j][i] && i>=abs(j-6)) //开始位置为6
          dp[j][i]+=cookie[j][i];
        ans=max(ans,dp[j][i]);
      }
      printf("%d\n",ans);
  }

  return 0;
}
