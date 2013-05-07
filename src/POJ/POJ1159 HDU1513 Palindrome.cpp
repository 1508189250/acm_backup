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
#define MAX 5010
using namespace std;

char str[MAX];
short int dp[2][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n;
  while(~scanf("%d",&n))
  {
		getchar();
		gets(str+1);
		memset(dp,0,sizeof(dp));
    int k=0;
    for(int i=n-1;i>0;--i)
    {
			for(int j=i+1;j<=n;++j)
				if(str[i]==str[j])
          //dp[i][j]=dp[i+1][j-1];
					dp[k][j]=dp[1-k][j-1];
				else
          //dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
					dp[k][j]=min(dp[1-k][j],dp[k][j-1])+1;
      k=1-k;
    }
		printf("%d\n",dp[1-k][n]);
  }

  return 0;
}
