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
#define MAX 6000
using namespace std;

int dp[20][MAX*2];
int h[20],w[20];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int c,g;
	
	scanf("%d%d",&c,&g);
	for(int i=0;i<c;++i)
		scanf("%d",&h[i]);
	for(int i=0;i<g;++i)
		scanf("%d",&w[i]);

	memset(dp,0,sizeof(dp));
	for(int i=0;i<c;++i)
		dp[0][w[0]*h[i]+MAX]=1;

	for(int i=1;i<g;++i)
		for(int j=0;j<c;++j)
			for(int k=1;k<2*MAX;++k)
				if(dp[i-1][k])
					dp[i][k+w[i]*h[j]]+=dp[i-1][k];

	printf("%d\n",dp[g-1][MAX]);

  return 0;
}
