/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-08 20:00
 # Filename: ZOJ3211 Dream City.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
//#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 260
#define max_dp MAX*100
using namespace std;

struct TREE{int a,b;}tree[MAX];

bool inline cmp(const TREE &lhs,const TREE &rhs)
{ return lhs.b<rhs.b;};

int dp[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases,n,m;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
      scanf("%d",&tree[i].a);
    for(int i=1;i<=n;++i)
      scanf("%d",&tree[i].b);
		sort(tree+1,tree+n+1,cmp);

    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i)
	  	for(int j=1;j<=m;++j)
			{
				if(j>i)
					break;
				dp[j][i] = max(dp[j][i-1],dp[j-1][i-1]+tree[i].a+tree[i].b*(j-1));
			}

		printf("%d\n",dp[m][n]);
	}

  return 0;
}
