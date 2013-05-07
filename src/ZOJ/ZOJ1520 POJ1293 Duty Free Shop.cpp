/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-29 19:45
 # Filename: ZOJ1520 POJ1293 Duty Free Shop.cpp
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
#include <assert.h>
#define MAX 1010
using namespace std;

int dp[MAX*2],value[MAX];
int mark[MAX],visit[MAX];
int ans[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,l;
  //   scanf("%d",&ncase);

  while(~scanf("%d%d",&m,&l) && (m||l))
  {
		int sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&value[i]);
			sum+=value[i];
		}

		memset(dp,0,sizeof(dp));
		memset(mark,0,sizeof(mark));
    memset(visit,0,sizeof(visit));
    dp[0]=1;
		for(int i=1;i<=n;++i)
			for(int j=m;j>=value[i];--j)
				if(dp[j-value[i]]&&!dp[j])
				{
          dp[j]=1;
					mark[j]=i;
				}

    int rec;
    for(rec=m;!dp[rec] &&rec;--rec);
    if((sum-rec)>l)
      printf("Impossible to distribute\n");
    else
    {
      while(rec)
      {
        visit[mark[rec]]=1;
        rec-=value[mark[rec]];
      }
      int cnt=0;
      for(int i=1;i<=n;++i)
        if(visit[i])
          ans[cnt++]=i;

      printf("%d",cnt);
      for(int i=0;i<cnt;++i)
        printf(" %d",ans[i]);

        printf("\n");
    }
  }

  return 0;
}
