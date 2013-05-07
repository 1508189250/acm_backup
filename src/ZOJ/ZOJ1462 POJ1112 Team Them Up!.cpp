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

int map[MAX][MAX];		//邻接矩阵
int used[MAX];				//在每次找增广路径中用于记录当前节点是否在增广路径中
int mat[MAX];				//各个节点对应的匹配项
int m,n;

bool find(const int &x)		//从x开始是否有增广路
{
  int i;
  for(i=1;i<=n;++i)
  {
    if(!map[x][i] && !used[i])		//若x与i有边相连且i不在当前的增广路上
    {
      used[i]=1;
      if(!mat[i] || find(mat[i]))	//若i没有匹配项或从i的匹配项开始有增广路
      {
        mat[i]=x;
        return true;
      }
    }
  }
  return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  //   scanf("%d",&ncase);
	int u,v;

  while(~scanf("%d",&n) && n)
  {
		memset(map,0,sizeof(map));
		memset(mat,0,sizeof(mat));
		for(u=1;u<=n;++u)
			while(scanf("%d",&v) && v)
				map[u][v]=1;
    for(int i=1;i<=n;++i)
      for(int j=i+1;j<=n;++j)
        if(!(map[u][v]&&map[v][u]))
          map[u][v]=map[v][u]=0;

		int ans=0;
		for(int i=1;i<=n;++i)
		{
			memset(used,0,sizeof(used));
			if(find(i))
				++ans;
		}
		printf("%d\n",ans);
  }

  return 0;
}
