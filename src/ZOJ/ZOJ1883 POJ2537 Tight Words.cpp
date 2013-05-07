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

double dp[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int k,n;
  while(~scanf("%d%d",&k,&n))
  {
    if(k==0)
    {
      printf("%.5lf\n",100.0);
      continue;
    }
   for(int i=0;i<n;++i)
     for(int j=0;j<k;++j)
       dp[i][j]=0.0;
   for(int i=0;i<=k;++i)
     dp[0][i]=1.0;

    for(int i=1;i<n;++i)
		{
			dp[i][0]=dp[i-1][0]+dp[i-1][1];
			dp[i][k]=dp[i-1][k]+dp[i-1][k-1];
			for(int j=1;j<k;++j)
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
    }

    double tmp=0.0;
		for(int i=0;i<=k;++i)
			tmp+=dp[n-1][i];

		double total=(pow((k+1)*1.0,n));

// 		if(tmp>total)
// 			tmp=total;

		printf("%.5lf\n",(tmp*100.0)/total);

  }

  return 0;
}
