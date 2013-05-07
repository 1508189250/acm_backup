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
#define MAX 30
using namespace std;

struct NODE
{
  int id,time,initial,decreases;
}node[MAX];

int dp[MAX][MAX*MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  int hour;
  scanf("%d",&ncase);

  while(ncase--)
  {
    while(~scanf("%d",&n) && n)
    {
      scanf("%d",&hour);
      hour *=12;
      for(int i=1;i<=n;++i)
      {
        scanf("%d",&node[i].initial);
        node[i].id=i;
      }
      for(int i=1;i<=n;++i)
        scanf("%d",&node[i].decreases);
			for(int i=2;i<=n;++i)
				scanf("%d",&node[i].time);
			node[1].time=0;

			dp[1][1]=node[1].initial;
			dp[1][0]=0;
			for(int i=2;i<=hour;++i)
				dp[1][i]=dp[1][i-1]-node[1].decreases;


			int used=0;
			for(int i=2;i<=n;++i)
			{
// 				used+=node[i].time;
// 				dp[i][used]=0;
// 				dp[i][used+1]=node[i].initial;
// 				for(int j=used+2;j<=hour;++j)
// 					dp[i][j]=max(dp[i][j-1]+(j-used-1)*node[i].decreases,
					for(int j=1;j<=hour;++j)
					{
						dp[i][j]=dp[i-1][j];
						if(j==node[i].time)

					}

    }
  }

  return 0;
}
