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

int map[MAX][MAX];
struct GOOD
{
  int p,ap;
}goods[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,ncase=1;
	int q,p,u,v;
  scanf("%d",&ncase);

  while(ncase--)
  {
    scanf("%d",&n);
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				map[i][j]=INT_MAX;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&q);
      scanf("%d",&goods[q].p);
      goods[q].ap=goods[q].p-1;
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&p);
			map[u][v]=p;
		}

		bool flag=true;
    
		while(flag)
		{
			flag=false;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
          if(i==j)
            continue;
					else if(goods[i].p==goods[j].p && goods[i].ap<goods[j].ap)
					{
						flag=true;
						goods[j].ap=goods[i].ap;
					}
					else if(/*goods[i].p< goods[j].p && */goods[i].ap<goods[j].ap-map[i][j]) 
					{
						flag=true;
						goods[j].ap=goods[i].ap+map[i][j];
					}
		}
    
		for(int i=1;i<=n;++i)
			printf("%d %d\n",i,goods[i].ap);
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(j==i)
          continue;
        int k=1;
        for(;k<=n;k++)
        {
          if(k==i||k==j)
            continue;
          if(goods[i].ap==goods[j].ap+goods[k].ap)
          {
            ans++;
            break;
          }
        }
        if(k<=n)
          break;
      }
    }		
    printf("%d\n",ans);
  }

  return 0;
}
