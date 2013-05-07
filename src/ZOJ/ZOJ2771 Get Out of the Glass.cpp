/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-13 19:28
 # Filename: ZOJ2771 Get Out of the Glass.cpp
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
#define MAX 70
#define EMPTY(x) memset(x,'\0',sizeof(x))
using namespace std;

long long down[3][MAX],up[3][MAX],sum[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
	for(int i=0;i<3;++i)
		for(int j=0;j<MAX;++j)
			up[i][j]=down[i][j]=sum[i]=0ll;

	up[0][0]=up[0][1]=up[1][1]=up[2][1]=1ll;

	for(int i=2;i<MAX;++i)
		for(int j=0;j<3;++j)
		{
			for(int k=j;k<3;++k)
				down[j][i]+=up[k][i-1];
			for(int k=0;k<=j;++k)
				up[j][i]+=down[k][i-1];
		}

  while(~scanf("%d",&n)/* && n*/)
		printf("%lld\n",up[0][n]+up[1][n]+up[2][n]+down[0][n]+down[1][n]+down[2][n]);

  return 0;
}
