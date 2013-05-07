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
#include <numeric>
#include <functional>
#include <ctype.h>
#define	MAX 500
using namespace std;

int dp[MAX][MAX];

int func(const int &x,const int &y)
{
	if(dp[x][y]!=-1)
		return dp[x][y];

  int sum=10000;
  for(int i=1 ;i<x;++i)
    sum = min(sum,func(i,y) + func(x-i,y) +1);

  for(int j=1;j<y;++j)
    sum= min(sum, func(x,j)+func(x,y-j)+1);

  dp[x][y]=sum;

	return dp[x][y];
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int ncase;
  int n,m;

  memset(dp,-1,sizeof(dp));

  for (int i=0;i<MAX;++i)
    dp[i][i]=0;
  for(int i=1;i<MAX;++i)
    for(int j=1;j<MAX;++j)
      func(i,j);

	scanf("%d",&ncase);

	while(ncase--)
  {
    scanf("%d%d",&n,&m);
		printf("%d\n",dp[n][m]);
	}

  return 0;
}
