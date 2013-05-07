/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-24 19:43
 # Filename: ZOJ2049 POJ1752 Advertisement.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
// #define DEBUG
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
#define MAX 20010
using namespace std;

struct NODE
{
  int v,d;
  NODE *next;
}node[4*MAX];
NODE *edge[MAX];
int m,n,ncase=1;
int beg,end,cnt;
int dist[MAX];
bool in_que[MAX];

void init()
{
  memset(edge,'\0',sizeof(edge));
}
void addEdge(const int &u,const int &v,const int &dist)
{
  node[cnt].d=dist;
  node[cnt].v=v;
  node[cnt].next=edge[u];
  edge[u]=&node[cnt++];
}

void spfa()
{
  memset(in_que,false,sizeof(in_que));
  for(int i=0;i<MAX;++i)
    dist[i]=INT_MIN;
  queue<int> que;
  que.push(beg);
  in_que[beg]=true;
  dist[beg]=0;
  while(!que.empty())
  {
    int u=que.front();
    que.pop();
    in_que[u]=false;
    NODE *p=edge[u];
//     for(vector<NODE>::iterator i=edge[u].begin();i!=edge[u].end();++i)
    while(p)
    {
      int v=p->v;
      int d=p->d;
      if(dist[v]<d+dist[u])
      {
        dist[v]=d+dist[u];
        if(!in_que[v])
        {
          que.push(v);
          in_que[v]=true;
        }
      }
      p=p->next;
    }
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

//   scanf("%d",&ncase);
  int u,v;

  while(ncase--)
  {
    scanf("%d%d",&m,&n);
    init();
    beg=INT_MAX;
    end=INT_MIN;
    cnt=0;

    for(int i=0;i<n;++i)
    {
      scanf("%d%d",&u,&v);
      if(u>v)
        swap(u,v);
      u+=10000;
      v+=10000;
      beg=min(u,beg);
      end=max(v+1,end);
      if(v-u+1<m)
        addEdge(u,v+1,v-u+1);
      else
        addEdge(u,v+1,m);
    }
    for(int i=beg;i<end;++i)
      addEdge(i,i+1,0);
    for(int i=beg+1;i<=end;++i)
      addEdge(i,i-1,-1);


    spfa();
    printf("%d\n",dist[end]);
    int pre=0;
    for(int i=beg;i<=end;++i)
      if(pre<dist[i])
      {
        printf("%d\n",i-10001);
        pre=dist[i];
      }
      if(ncase)
        printf("\n");
  }

  return 0;
}
