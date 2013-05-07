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
#define MAX 100010
using namespace std;

int insect[MAX],visit[MAX];
vector<int> edge[MAX];

int n,m,limit,ncase=1;
int ans;
void bfs(const int &x,const int &cnt)
{
	if(cnt>limit)
		return;
	if(x==n)
	{
		++ans;
		return;
	}
	for(int i=0;i<edge[x].size();++i)
	{
		int v=edge[x][i];
		if(!visit[v])
		{
			visit[v]=1;
			bfs(v,cnt+insect[v]);
			visit[v]=0;
		}
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int u,v;
  //   scanf("%d",&ncase);

  while(~scanf("%d%d%d",&m,&n,&limit) )
  {
		ans=0;
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&u,&v);
			insect[u]=v;
			edge[i].clear();
		}
		while(m--)
		{
			scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
    visit[1]=1;
		bfs(1,0);
		if(ans)
			printf("%d\n",ans);
		else
			printf("Impossible!\n");
  }

  return 0;
}
