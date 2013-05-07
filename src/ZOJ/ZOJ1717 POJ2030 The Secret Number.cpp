/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-23 20:17
 # Filename: ZOJ1717 POJ2030 The Secret Number.cpp
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
#define MAX 80
using namespace std;

int mat[MAX][MAX];

char dp[MAX][MAX][2*MAX];

bool cmp(const char *lhs,const char *rhs)
{
  const int llen=strlen(lhs),rlen=strlen(rhs);
  if(llen != rlen)
    return llen<rlen;
  else
    for(int i=0;i<llen;++i)
      if(lhs[i]!=rhs[i])
        return lhs[i]<rhs[i];
  return false;
}


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
	char temp,ans[2*MAX];

  while(scanf("%d%d",&m,&n) &&(n||m))
  {
		memset(mat,-1,sizeof(mat));
    memset(dp,'\0',sizeof(dp));
    memset(ans,'\0',sizeof(ans));

		for(int i=1;i<=n;++i)
    {
      getchar();
			for(int j=1;j<=m;++j)
			{
				scanf("%c",&temp);
				if(isdigit(temp))
					mat[i][j]=temp-'0';
				else
					mat[i][j]=-1;
			}
    }


		for(int i=1;i<=n;++i)
    {
			for(int j=1;j<=m;++j)
        if(mat[i][j]>-1)
        {
          int a=strlen(dp[i-1][j]),b=strlen(dp[i][j-1]);
          if(a&&b)
          {
            if(cmp(dp[i-1][j],dp[i][j-1]))
            {
              strcpy(dp[i][j],dp[i][j-1]);
              dp[i][j][b++]=mat[i][j]+'0';
              dp[i][j][b]='\0';
            }
            else
            {
              strcpy(dp[i][j],dp[i-1][j]);
              dp[i][j][a++]=mat[i][j]+'0';
              dp[i][j][a]='\0';
            }
          }
          else if(a)
          {
            strcpy(dp[i][j],dp[i-1][j]);
            dp[i][j][a++]=mat[i][j]+'0';
            dp[i][j][a]='\0';
          }
          else if(b)
          {
            strcpy(dp[i][j],dp[i][j-1]);
            dp[i][j][b++]=mat[i][j]+'0';
            dp[i][j][b]='\0';
          }
          else if(mat[i][j]>0)
          {
            dp[i][j][0]=mat[i][j]+'0';
          }
          if(cmp(ans,dp[i][j]))
            strcpy(ans,dp[i][j]);
        }
    }

		printf("%s\n",ans);
  }

  return 0;
}
