/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-04 20:26
 # Filename: URAL1072 Routing.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <queue>
#define MAX 100
using namespace std;

struct COMPUTER
{
	int k;
	long long subnet[6];
}com[MAX];

bool isConnect(const COMPUTER &lhs,const COMPUTER &rhs)
{
	for(int i=0;i<lhs.k;++i)
		for(int j=0;j<rhs.k;++j)
			if(lhs.subnet[i] == rhs.subnet[j])
				return true;
	return false;
}

bool map[MAX][MAX];
int pre[MAX],used[MAX];

void init()
{
	memset(map,false,sizeof(map));
	memset(pre,-1,sizeof(pre));
	memset(used,0,sizeof(used));
}

bool bfs(const int &s,const int &t,const int &n)
{
	queue<int> m_q;
	m_q.push(s);
	used[s]=1;
	while(!m_q.empty() && !used[t])
	{
		int now = m_q.front();
		m_q.pop();
		for(int i=1;i<=n;++i)
			if(!used[i] && map[now][i])
			{
				used[i]=1;
				pre[i]=now;
				m_q.push(i);
			}
	}
	if(used[t])
		return true;
	else
		return false;
}

void output(const int &x)
{
	if(x==-1)
		return;
	output(pre[x]);
	if(pre[x]!=-1)
		printf(" ");
	printf("%d",x);
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n_n,start,end;
	int temp1[4],temp2[4];
	scanf("%d",&n_n);
	
	init();
	for(int i=1;i<=n_n;++i)
	{
		scanf("%d",&com[i].k);
		for(int j=0;j<com[i].k;++j)
		{
			scanf("%d.%d.%d.%d",&temp1[0],&temp1[1],&temp1[2],&temp1[3]);
      scanf("%d.%d.%d.%d",&temp2[0],&temp2[1],&temp2[2],&temp2[3]);
      com[i].subnet[j]=0ll;
      for (int p=0;p<4;++p)
      {
        com[i].subnet[j] = com[i].subnet[j]<<8;
        com[i].subnet[j] += temp1[p]&temp2[p];
      }
    }

		for(int j=1;j<i;++j)
			if(isConnect(com[i],com[j]))
				map[i][j]=map[j][i]=1;
	}
	scanf("%d %d",&start,&end);
	if(!bfs(start,end,n_n))
		printf("No\n");
	else
	{
		printf("Yes\n");
		output(end);
		printf("\n");
	}
  return 0;
}
