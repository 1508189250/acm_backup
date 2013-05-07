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

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int squart[2500];
	int dp[70000];
	int n;
	for(int i=0;i<2500;++i)
		squart[i]=i*i;
  for (int i=0;i<=65000;++i)
    dp[i]=i;
  for(int i=2;i<=sqrt(60000*1.0)+1;++i)
    for(int j=squart[i];j<=60000;++j)
      dp[j]=min(dp[j],dp[j-squart[i]]+1);

	while(~scanf("%d",&n))
	{
		printf("%d\n",dp[n]);
	}


  return 0;
}
