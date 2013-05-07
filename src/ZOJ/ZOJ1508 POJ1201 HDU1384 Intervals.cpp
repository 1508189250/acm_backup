/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-23 20:39
 # Filename: ZOJ1508 POJ1201 HDU1384 Intervals.cpp
 # Description : 对于差分不等式，a - b <= c ，建一条 b 到 a 的权值为 c 的边，求的是最短路，得到的是最大值
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
#include <vector>
#include <queue>
#define MAX 50010
using namespace std;

struct NODE
{
  int v,d;
}node;
vector<NODE> edge[MAX];

bool in_que[MAX];
int array[MAX],beg,end; 

void spfa()
{
	queue<int> que;
	memset(in_que,false,sizeof(in_que));
	for(int i=beg;i<=end;++i)
		array[i]=INT_MIN;
	in_que[beg]=true;
	array[beg]=0;
	que.push(beg);

	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		in_que[u]=false;
		for(int i=0;i<edge[u].size();++i)
		{
			int v=edge[u][i].v;
			int d=edge[u][i].d;
			if(array[v]<array[u]+d)
			{
				array[v]=array[u]+d;
				if(!in_que[v])
				{
					que.push(v);
					in_que[v]=true;
				}
      }
		}
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
	int u,v,d;

  while(~scanf("%d",&n) && n)
  {
		end=0;beg=INT_MAX;
		for(int i=0;i<MAX;++i)
			edge[i].clear();

		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&u,&v,&d);
			node.v=v+1;
			node.d=d;
			edge[u].push_back(node);
			end=max(end,v+1);
      beg=min(beg,u);
		}
		for(int i=beg;i<end;++i)  //所有的约束条件都要加入
		{
      node.d=0;
			node.v=i+1;
			edge[i].push_back(node);
      node.d=-1;
      node.v=i;
      edge[i+1].push_back(node);
		}
		spfa();
		printf("%d\n",array[end]);
  }

  return 0;
}
