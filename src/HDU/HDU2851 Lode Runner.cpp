#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <stack>
#define MAX 2020
using namespace std;

int map[MAX][MAX];
struct ROAD{
	int x,y,len;
}road[MAX];

int ins[MAX];
int dis[MAX];

stack<int> s;

bool check(const ROAD &lhs,const ROAD &rhs)
{
	if(lhs.x >=rhs.x && lhs.x<=rhs.y || lhs.y>=rhs.x && lhs.y<=rhs.y)
		return true;
	else
		return false;
}

void Dijkstra(int s,int n)  
{  
  bool used[MAX];  
  memset(used,false,sizeof(used));  
  for(int i=0; i<n; i++)  
    dis[i] = INT_MAX;  
  used[1] = true; dis[1] = map[1][1];  
  int now = 1;  
  for(int i=0; i<n; i++)  
  {  
    for(int k=0; k<n; k++)  
      if( map[now][k] != -1 && dis[now] != INT_MAX )  
        if( dis[k] > dis[now] + map[now][k] )  
          dis[k] = dis[now] + map[now][k];  
    int mmin = INT_MAX;  
    for(int k=0; k<n; k++)  
      if( !used[k] && dis[k] < mmin )  
        mmin = dis[now = k];  
    used[now] = true;  
  }  
}  

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int ncaase;
	int n,m;
	int temp;
	scanf("%d",&ncaase);
	while(ncaase--)
	{
		memset(map,-1,sizeof(map));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&road[i].x,&road[i].y,&road[i].len);
			for(int j=1;j<=i;++j)
				if(check(road[i],road[j]) || check(road[j],road[i]))
					map[j][i]=road[i].len;
		}
		Dijkstra(1,n+1);
		while(m--)
		{
			scanf("%d",&temp);
			if(dis[temp]==INT_MAX)
				printf("-1\n");
			else
				printf("%d\n",dis[temp]);
		}

	}

  return 0;
}
