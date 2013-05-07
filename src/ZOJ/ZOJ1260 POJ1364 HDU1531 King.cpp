/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-24 20:35
 # Filename: ZOJ1260 POJ1364 HDU1531 King.cpp
 # Description : 
 ******************************************************************************/
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

// 边，
typedef struct Edge{
  int u, v;    // 起点，重点
  int weight;  // 边的权值
}Edge;

Edge edge[MAX];     // 保存边的值
int  dist[MAX];     // 结点到源点最小距离

int nodenum, edgenum, source;    // 结点数，边数，源点


// 松弛计算
void relax(int u, int v, int weight)
{
  if(dist[v] < dist[u] + weight)
    dist[v] = dist[u] + weight;//如果source到v的距离大于source到u到v的距离，更新之
}

bool Bellman_Ford()
{
  for(int i=0; i<=nodenum; ++i)
    for(int j=0; j<edgenum; ++j)
      relax(edge[j].u, edge[j].v, edge[j].weight);
  bool flag = 1;
  // 判断是否有负环路,1为不存在负环
  for(int i=0; i<edgenum; ++i)
    if(dist[edge[i].v] < dist[edge[i].u] + edge[i].weight)
    {
      flag = 0;
      break;
    }
    return flag;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

//   int n,ncase=1;
  int u,v,d;
  char str[5];
  //   scanf("%d",&ncase);

  while(~scanf("%d",&nodenum) && nodenum)
  {
    scanf("%d",&edgenum);
    for(int i=0;i<edgenum;++i)
    {
      scanf("%d %d %s %d",&u,&v,str,&d);
      if(str[0]=='g')
      {
        edge[i].u=u;
        edge[i].v=u+v+1;
        edge[i].weight=d+1;
      }
      else
      {
        edge[i].u=u+v+1;
        edge[i].v=u;
        edge[i].weight=1-d;
      }
    }
    for(int i=0;i<=nodenum;++i)
      dist[i]=-100000000;

    if(Bellman_Ford())
      printf("lamentable kingdom\n");
    else
      printf("successful conspiracy\n");
  }

  return 0;
}
