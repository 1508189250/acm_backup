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
#define MAX	 30
using namespace std;

int dp[MAX][MAX*10];		
int len[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  memset(dp,0,sizeof(dp));
  memset(len,0,sizeof(len));
  len[0]=len[1]=1;

  for(int i=2;i<21;++i)
  {
	  int cnt=0;
	  for(int j=0;j<i;++j)	//第i条线与j条线不平行
		  for(int k=0;k<len[j];++k)
			  dp[i][cnt++]=j*(i-j)+dp[j][k];
	  sort(dp[i],dp[i]+cnt);
	  len[i]=unique(dp[i],dp[i]+cnt)-dp[i];
  }

  int n;
  while(~scanf("%d",&n))
  {
	  printf("0");
	  for(int i=1;i<len[n];++i)
		  printf(" %d",dp[n][i]);
	  printf("\n");
  }

  return 0;
}
