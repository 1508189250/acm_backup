/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-05 21:14
 # Filename: HDU3926 Hand in Hand.cpp
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
#define MAX 10010
using namespace std;

bool inline cmp(const vector<int> &lhs,const vector<int> &rhs)
{
  return lhs.size()<rhs.size();
}

struct GRAPH
{
  vector<int>  adj[MAX],list[MAX],cirle[MAX];
  bool used[MAX];
  bool visit[MAX];
  int n,lcnt,ccnt;

  void init(const int &t)
  {
    n=t;
    lcnt=ccnt=0;
    memset(visit,false,sizeof(visit));
    memset(used,false,sizeof(used));
    for (int i=0;i<MAX;++i)
    {
      list[i].clear();
      cirle[i].clear();
      adj[i].clear();
    }
  }

  void add_adj(const int &x,const int &y)
  {
    used[x]=true;
    bool  flag=true;
    for(size_t i=0;i<adj[x].size();++i)
      if(adj[x][i]==y)
        flag=false;
    if(flag)
      adj[x].push_back(y);
  }

  bool dfs(const int &u)
  {
    visit[u]=true;
    list[lcnt].push_back(u);
    cirle[ccnt].push_back(u);

    bool flag=true;
    for(size_t j=0;j<adj[u].size();++j)
      if(!visit[adj[u][j]])
        flag=false;

    if(flag)
      if(adj[u].size()==1)
        return false;
      else
        return true;

    bool ans=false;
    for(size_t j=0;j<adj[u].size();++j)
      if(!visit[adj[u][j]])
        ans = ans||dfs(adj[u][j]);

    return ans;
  }

  void func()
  {
    for(int i=0;i<MAX;++i)
    {
      if(!visit[i] && used[i])
      {
        bool ans=dfs(i);
        if(!ans)
        {
          cirle[ccnt].clear();
          ++lcnt;
        }
        else
        {
          list[lcnt].clear();
          ++ccnt;
        }
      }
    }
    sort(list,list+lcnt,cmp);
    sort(cirle,cirle+ccnt,cmp);
  }
};

bool check(const vector<int> *lhs,const int &lcnt,const vector<int> *rhs,const int &rcnt)
{
  if(lcnt!=rcnt)
    return false;
  for(int i=0;i<lcnt;++i)
    if(lhs[i].size()!=rhs[i].size())
      return false;
  return true;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int ncases,n,m;
  int a,b;
  GRAPH lhs,rhs;

  scanf("%d",&ncases);
  for(int nc=1;nc<=ncases;++nc)
  {
    
    scanf("%d%d",&n,&m);
    lhs.init(n);
    while(m--)
    {
      scanf("%d%d",&a,&b);
      lhs.add_adj(a,b);
      lhs.add_adj(b,a);
    }
    lhs.func();

    scanf("%d%d",&n,&m);
    rhs.init(n);
    while(m--)
    {
      scanf("%d%d",&a,&b);
      rhs.add_adj(a,b);
      rhs.add_adj(b,a);
    }
    rhs.func();

    bool ans=check(lhs.list,lhs.lcnt,rhs.list,rhs.lcnt) && 
      check(lhs.cirle,lhs.ccnt,rhs.cirle,rhs.ccnt);

    printf("Case #%d: ",nc);
    if(!ans)
      printf("NO\n");
    else
      printf("YES\n");

  }


  return 0;
}
