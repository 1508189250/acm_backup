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
#include <queue>
#include <vector>
#define MAX 1010
using namespace std;

int map[MAX][MAX],value[MAX],mark[MAX][MAX];

struct NODE
{
  int u,cap,cost;
  bool operator<(const NODE &tmp) const
  {
    return cost>tmp.cost; //优先队列是返回权值最大的
  }
};

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,request,total,beg,end;
  int x,y,dist;
  vector<int> next[MAX];
  NODE now,tmp;
  scanf("%d%d",&n,&m);

  memset(map,0,sizeof(map));

  for(int i=0;i<n;++i)
    scanf("%d",&value[i]);
  for(int i=0;i<m;++i)
  {
    scanf("%d%d%d",&x,&y,&dist);
    map[x][y]=map[y][x]=dist;
    next[x].push_back(y);
    next[y].push_back(x);
  }

  scanf("%d",&request);
  while(request--)
  {
    scanf("%d%d%d",&total,&beg,&end);
    memset(mark,0,sizeof(mark));
    int ans=INT_MAX;

    now.u=beg;
    now.cost=0;
    now.cap=0;
    priority_queue<NODE> q;
    q.push(now);

    while(!q.empty())
    {
      now=q.top();
      q.pop();
      mark[now.u][now.cap]=1;
      if(now.u==end)
      {
        ans=min(ans,now.cost);
        break;
      }

      if(now.cap<total&& !mark[now.u][now.cap+1])
      {
        tmp=now;
        ++tmp.cap;
        tmp.cost+=value[tmp.u];
        q.push(tmp);
      }
      for(int i=0;i<next[now.u].size();++i)
      {
        tmp=now;
        tmp.cap-=map[now.u][next[now.u][i]];
        if(tmp.cap>-1 && !mark[next[now.u][i]][tmp.cap])
        {
          tmp.u=next[now.u][i];
          q.push(tmp);
        }
      }
    }

    if(ans==INT_MAX)
      printf("impossible\n");
    else
      printf("%d\n",ans);

  }


  return 0;
}
