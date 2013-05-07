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

struct NODE{
	int id,level,price,n;
	int goods[MAX],vocher[MAX];
}node[MAX]; 

int n_threshold,n_now_lev;

int check(const NODE &lhs,const NODE &rhs)
{
	if(abs(lhs.level-rhs.level)>n_threshold)
		return lhs.price;
	for(int i=0;i<lhs.n;++i)
		if(lhs.goods[i]==rhs.id)
			return lhs.vocher[i];
	return lhs.price;
}

int map[MAX][MAX];
bool visit[MAX];

int dfs(const int &x,const int &n,const int &level)
{
	int ans=node[x].price;
	for(int i=1;i<=n;++i)
		if(!visit[i] && map[x][i]<ans && abs(level-node[i].level)<=n_threshold)
		{
			visit[i]=true;
			ans=min(ans,dfs(i,n,min(level,node[i].level))+map[x][i]);
      visit[i]=false;
		}
	return node[x].price=min(ans,node[x].price);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  //   scanf("%d",&ncase);

  while(~scanf("%d%d",&n_threshold,&n) )
  {
		for(int i=1;i<=n;++i)
		{
			node[i].id=i;
			scanf("%d%d%d",&node[i].price,&node[i].level,&node[i].n);
			for(int j=0;j<node[i].n;++j)
				scanf("%d%d",&node[i].goods[j],&node[i].vocher[j]);
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				map[i][j]=check(node[i],node[j]);

//     memset(visit,false,sizeof(visit));
//     printf("%d\n",dfs(1,n,node[1].level));
		for(int k=1;k<=n;++k)
		{
			int level=node[1].level;
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					if(node[i].price>map[i][j]+node[j].price && level>=node[j].level)
					{
						node[i].price=map[i][j]+node[j].price;
						level=min(level,node[j].level);
					}
		}
 		printf("%d\n",node[1].price);
  }

  return 0;
}
