/*******************************************************************************
# Author : Neo Fung
# Email : neosfung@gmail.com
# Last modified: 2012-02-03 22:50
# Filename: ZOJ1134 POJ1463 HDU1054 Strategic Game.cpp
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
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <vector>
#include <assert.h>
#define MAX 1510
using namespace std;

vector<int> adj[MAX];
int dp[MAX][2],visit[MAX];

void init(const int &n)
{
  memset(visit,0,sizeof(visit));
  memset(dp,0,sizeof(dp));
  for(int i=0;i<n;++i)
    adj[i].clear();
}

void dfs(const int &u)
{
  if(visit[u]) return;
  visit[u]=1;
  dp[u][0]=0;	// 0代表不取
  dp[u][1]=1;	// 1代表取
  int ans=0,  ans1=0;
  for(size_t i=0;i<adj[u].size();++i)
  {
    int v=adj[u][i];
    if(!visit[v])
    {
      dfs(v);
      dp[u][0]+=dp[v][1]; //如果u不取,则v要取
      dp[u][1]+=min(dp[v][0],dp[v][1]);	//如果u取, 则v可取可不取, 取最优
    }	
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int n,m,x,y;

  while(~scanf("%d",&n))
  {
    init(n);
    int beg=-1;
    for(int i=0;i<n;++i)
    {
      scanf("%d: (%d)",&x,&m);
      if(m) beg=x;
      while(m--)
      {
        scanf("%d",&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
      }
    }
    dfs(beg);
    printf("%d\n",min(dp[beg][0],dp[beg][1]));
  }

  return 0;
}
