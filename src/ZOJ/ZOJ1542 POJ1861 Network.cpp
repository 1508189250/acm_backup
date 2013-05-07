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
#include <vector>
#define MAX 1010
using namespace std;

int map[MAX][MAX];
int pre[MAX],dist[MAX];
bool visit[MAX];

void prim(const int &n)
{
  memset( visit,0,sizeof(visit));
  for (int i=1;i<=n;++i)
  {
    dist[i]=1<<30;
    pre[i]=i;
  }
  visit[1]=1;	//访问过的节点
  dist[1]=0;	//最小距离
  int minIndex=1;

  for(int ind=2;ind<=n;++ind)
  {
    for(int i=1;i<=n;++i)
      if(!visit[i] && dist[i]>map[minIndex][i])
      {
        dist[i]=map[minIndex][i];
        pre[i]=minIndex;
      }

      int minlen=1<<30;
      minIndex=-1;
      for(int i=1;i<=n;++i)
        if(!visit[i] && (minIndex==-1||dist[i]<minlen))
        {
          minlen=dist[i];
          minIndex=i;
        }
        if(minIndex>-1) visit[minIndex]=1;
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
	int n,m,x,y,len;

	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				map[i][j]=INT_MAX;
			map[i][i]=0;
		}

		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&x,&y,&len);
			map[x][y]=map[y][x]=len;
		}

    prim(n);

    int ans=0,cnt=0;
    for(int i=1;i<=n;++i)
      if(pre[i]!=i)
      {
        ++cnt;
        ans=max(ans,map[i][pre[i]]);
      }

    printf("%d\n%d\n",ans,cnt);
    for (int i=1;i<=n;++i)
      if(i!=pre[i])
        printf("%d %d\n",pre[i],i);
    printf("\n");

  }





	return 0;
}
