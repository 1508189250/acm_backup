#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 310
using namespace std;

int map[MAX][MAX];
int mark[MAX];

void init(const int &n)
{
  for(int i=0;i<n;++i)
  {
    for (int j=i+1;j<n;++j)
      map[i][j]=map[j][i]=INT_MAX;
    map[i][i]=0;
  }
	memset(mark,0,sizeof(mark));
}

void floyd(const int i,const int &n)
{
			for(int j=0;j<n;++j)
					for(int k=0;k<n;++k)
							if(map[j][i]!=INT_MAX && map[i][k] !=INT_MAX && map[j][k]>map[j][i]+map[i][k])
								map[j][k]=map[j][i]+map[i][k];
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n,m,q;
	int u,v,len;
	int sel,ncase=1;

	while(scanf("%d%d%d",&n,&m,&q) && (n||m||q))
	{
    if(ncase!=1)
      printf("\n");
		printf("Case %d:\n",ncase++);
		init(n);
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&u,&v,&len);
      map[u][v]=min(map[u][v],len);
		}
		while(q--)
		{
			scanf("%d",&sel);
			if(sel)
			{
				scanf("%d%d",&u,&v);
        if(!mark[u] || !mark[v])
          printf("ERROR! At path %d to %d\n",u,v);
        else
        {

          if(map[u][v]!=INT_MAX)
            printf("%d\n",map[u][v]);
          else
            printf("No such path\n");
        }
			}
			else
			{
				scanf("%d",&u);
				if(mark[u])
					printf("ERROR! At point %d\n",u);
				else
				{
					mark[u]=1;
					floyd(u,n);
				}
			}
		}
	}

  return 0;
}
