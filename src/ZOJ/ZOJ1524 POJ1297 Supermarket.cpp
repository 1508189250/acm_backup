/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-29 21:02
 # Filename: ZOJ1524 POJ1297 Supermarket.cpp
 # Description : 
 ******************************************************************************/
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
#define MAX 100010
#define INF 1000000000.00
#define EPS 10e-6
using namespace std;

double dp[2][MAX],value[MAX];
int num[MAX],list[MAX];
int mark[MAX];
int n,ncase=1,m;

void setINF(const int &x)
{
	for(int i=0;i<=n;++i)
		dp[x][i]=INF;
}

int func()
{
	setINF(0);
	for(int i=1;i<=n;++i)
		if(num[i]==list[1])
			dp[0][i]=min(dp[0][i-1],value[i]);
		else
			dp[0][i]=dp[0][i-1];

	int cur=1,pre=0;
	for(int i=2;i<=m;++i)
	{
		setINF(cur);
		for(int j=1;j<=n;++j)
			if(list[i]==num[j])
				dp[cur][j]=min(dp[cur][j-1],dp[pre][j-1]+value[j]);
			else
				dp[cur][j]=dp[cur][j-1];
		pre=cur;
		cur=1-pre;
	}

	return pre;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  //   scanf("%d",&ncase);

  while(~scanf("%d%d",&m,&n) && (m||n))
  {
		memset(mark,0,sizeof(mark));

		for(int i=1;i<=m;++i)
			scanf("%d",&list[i]);

		int ind=0;
		for(int i=1;i<=n;++i)
			scanf("%d %lf",&num[i],&value[i]);

		int cur=func();
		if(dp[cur][n]+EPS<INF)
			printf("%.2lf\n",dp[cur][n]);
		else
			printf("Impossible\n");
  }

  return 0;
}
