/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-13 16:07
 # Filename: acm.cpp
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
using namespace std;

const int kMAX=1010;
int num[kMAX][kMAX];
long long matrix[kMAX][kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1,m,x,y;
  scanf("%d",&ncase);
	memset(num,0,sizeof(num));

	while(ncase--)
  {
	  memset(matrix,0,sizeof(matrix));
		scanf("%d%d%d%d",&m,&n,&x,&y);
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&num[i][j]);

		long long ans=0ll;
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
			{
				matrix[i][j]=num[i][j]+matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
				if(i>=x && j>=y)
					ans=max(ans,matrix[i][j]-matrix[i-x][j]-matrix[i][j-y]+matrix[i-x][j-y]);
			}
		printf("%lld\n",ans);
  }

  return 0;
}

