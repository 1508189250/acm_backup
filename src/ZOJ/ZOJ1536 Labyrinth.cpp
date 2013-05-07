/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-31 19:50
 # Filename: ZOJ1536 Labyrinth.cpp
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
#define MAX 51
using namespace std;

struct NODE
{
  int dt[100],n;
  void sum(const NODE &tmp)
  {
    int num,i,f=0,t;
    num=max(n,tmp.n);

    for(i=0;i<num;i++)
    {
      t=dt[i]+tmp.dt[i]+f;
      dt[i]=t%10;
      f=t/10;
    }

    if(f>0) dt[i]=f,num++;
    n=num;
  }
}dp[22][22][MAX];

char map[MAX][MAX];
int diff[]={-1,0,1,0,0,-1,0,1};

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1,m;
  //   scanf("%d",&ncase);

  while(~scanf("%d%d",&n,&m) )
  {
		memset(dp,'\0',sizeof(dp));
    map[0][0]='1';
		for(int i=1;i<=n;++i)
		{
      getchar();
			for(int j=1;j<=n;++j)
				scanf("%c",&map[i][j]);
			map[i][0]=map[0][i]='1';
		}

    for(int l=0;l<8;l+=2)
    {
      int x=1+diff[l];
      int y=1+diff[l+1];
      if(map[x][y]=='0' )
      {
        dp[x][y][1].dt[0]=1;
        dp[x][y][1].n=1;
      }
    }


			for(int i=1;i<=m;++i)
				for(int j=1;j<=n;++j)
					for(int k=1;k<=n;++k)
						if(map[j][k]=='0')
							for(int l=0;l<8;l+=2)
							{
								int x=j+diff[l];
								int y=k+diff[l+1];
								dp[j][k][i].sum(dp[x][y][i-1]);
							}
      bool flag=false;
      for(int i=dp[n][n][m].n-1;i>=0;--i)
      {
        flag=true;
        printf("%d",dp[n][n][m].dt[i]);
      }
      printf("%s",flag?"\n":"0\n");
  }

  return 0;
}
