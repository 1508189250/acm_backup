/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-29 20:24
 # Filename: ZOJ2067 White Rectangles.cpp
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
#define MAX 110
using namespace std;

char board[MAX][MAX];
int sum[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
  while(~scanf("%d",&n))
  {
    memset(sum,0,sizeof(sum));
    memset(board,'#',sizeof(board));
    getchar();
    for(int i=1;i<=n;++i)
      gets(board[i]+1);

		int ans=0;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(board[i][j]=='.')
				{
					if(board[i][j-1]!='.')
						sum[i][j]=1;
					else
            sum[i][j]=sum[i][j-1]+1;
				}

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				int len=INT_MAX;
				for(int k=i;k<=n && sum[k][j];++k)
				{
					len=min(len,sum[k][j]);
					ans+=len;
				}
			}
		printf("%d\n",ans);
  }

  return 0;
}
