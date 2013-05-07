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
#define MAX 30 
using namespace std;

int direction[]={1,0,-1,0,0,1,0,-1};

struct POS
{
  int x,y,d,t;
  bool operator < (const POS & nt) const {
    if (nt.t == t) {
      if (nt.x == x && nt.y == y) return d < nt.d;
      else false;
    }
    else 
      return t < nt.t;
    //     return d<nt.d;
  }
  bool okey(const int &n)
  {
    return x>=0&&x<n&&y>=0&&y<n;
  }
}pos;

int grid[MAX][MAX];

priority_queue<POS> que;

void func(const int &x,const int &y,const int &size,const int &n)
{
  POS tmp;
  for (int i=0;i<8;i+=2)
  {
    tmp.x=x+direction[i];
    tmp.y=y+direction[i+1];
    tmp.d=i;
    tmp.t=1;
    if(tmp.okey(n))
      que.push(tmp);
  }
  while(!que.empty())
  {
    tmp=que.top();
    que.pop();
    int x=tmp.x;
    int y=tmp.y;
    if(grid[tmp.x][tmp.y])
    {
      ++grid[tmp.x][tmp.y];
      if(grid[tmp.x][tmp.y]==size)
      {
        grid[tmp.x][tmp.y]=0;
        for (int i=0;i<8;i+=2)
        {
          POS tp;
          tp.x=x+direction[i];
          tp.y=y+direction[i+1];
          tp.d=i;
          tp.t=tmp.t+1;
          if(tp.okey(n))
            que.push(tp);
        }
      }
    }
    else
    {
      tmp.x+=direction[tmp.d];
      tmp.y+=direction[tmp.d+1];
      ++tmp.t;
      if(tmp.okey(n))
        que.push(tmp);
    }
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m,size,p;
  int x,y;
  char ch;

  bool flag=true;
  while(~scanf("%d%d%d%d",&n,&m,&size,&p))
  {
    if(flag)
      flag=false;
    else
      printf("\n");

    while(!que.empty())
      que.pop();

    for(int i=0;i<n;++i)
    {
      getchar();
      for(int j=0;j<n;++j)
      {
        scanf("%c",&ch);
        grid[i][j]=ch-'0';
      }
    }

    while(p--)
    {
      scanf("%d%d",&x,&y);
      if(!m || !grid[x][y])
        continue;
      m--;
      ++grid[x][y];
      if(grid[x][y]==size)
      {
        grid[x][y]=0;
        func(x,y,size,n);
      }
    }
    printf("%d\n",m);
    for (int i=0;i<n;++i)
    {
      for(int j=0;j<n;++j)
        printf("%d",grid[i][j]);
      printf("\n");
    }
  }

  return 0;
}
