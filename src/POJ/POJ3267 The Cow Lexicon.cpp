/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-14 19:38
 # Filename: POJ3267 The Cow Lexicon.cpp
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
#define MAX 310
using namespace std;

char word[MAX*2][26],str[MAX];
int dp[MAX],wlen[MAX*2];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int nw,nl;
	while(~scanf("%d%d",&nw,&nl))
	{
    getchar();
		gets(str);
		for(int i=0;i<nw;++i)
		{
			gets(word[i]);
			wlen[i]=strlen(word[i]);
		}

		dp[0]=0;
		for(int i=1;i<=nl;++i)
		{
			dp[i]=dp[i-1]+1;
			for(int j=0;j<nw;++j)
			{
				if(i<wlen[j] || str[i-1]!=word[j][wlen[j]-1])
					continue;
        int k=i-1,t=wlen[j]-1;
				for(;t>=0 && k>=0;--k)
					if(str[k]==word[j][t])
						--t;
				int del=i;
				if(t<0)
					del=(i-k-1-wlen[j]);
				dp[i]=min(dp[i],dp[k+1]+del);
			}
		}
		printf("%d\n",dp[nl]);
	}

  return 0;
}
