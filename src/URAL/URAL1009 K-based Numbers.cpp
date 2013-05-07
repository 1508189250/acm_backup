/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-22 21:02
 # Filename: URAL1009 K-based Numbers.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

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
	
	__int64 dp[100]; 
	int n,k;

	while(~scanf("%d%d",&n,&k))
	{
		dp[0]=k-1;
		dp[1]=(k-1)*k;

		for(int i=2;i<n;++i)
			dp[i]=(k-1)*(dp[i-1]+dp[i-2]);

		printf("%I64d\n",dp[n-1]);
	}
  return 0;
}
