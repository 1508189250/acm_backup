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
#define MAX 110
using namespace std;

int map[MAX][MAX];
int money[MAX],begin_stop[MAX];
int dist[MAX][MAX];
int in_stack[MAX],month_ticket[MAX];
int n,m;

void spfa(const int &start)
{
	stack<int> m_s;
	memset(in_stack,0,sizeof(in_stack));
	for(int i=0;i<=n;++i)
		dist[start][i]=INT_MAX;

	m_s.push(start);
	in_stack[start]=1;
	dist[start][start]=0;

	while(!m_s.empty())
	{
		int u=m_s.top();
		m_s.pop();
		in_stack[u]=0;
		for(int v=1;v<=n;++v)
			if(map[u][v]!=-1 && dist[start][v]-map[u][v]>dist[start][u])
			{
				dist[start][v]=map[u][v]+dist[start][u];
				if(!in_stack[v])
				{
					in_stack[v]=1;
					m_s.push(v);
				}
			}
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int route[MAX];

	while(~scanf("%d%d",&n,&m))
	{
		memset(map,-1,sizeof(map));
		for(int i=0;i<m;++i)
		{
			int l;
			scanf("%d",&l);
			for(int j=0;j<l;++j)
				scanf("%d",&route[j]);
			for(int j=0;j<l;++j)
				for(int k=j+1;k<l;++k)
					map[route[j]][route[k]]=map[route[k]][route[j]]=4;
    }
    for(int i=1;i<=n;++i)
      map[i][i]=0;

		int n_person;
		int n_temp;
		scanf("%d",&n_person);
		for(int i=0;i<n_person;++i)
		{
			scanf("%d%d%d",&money[i],&begin_stop[i],&month_ticket[i]);
		}
		for(int i=0;i<n_person;++i)
			  spfa(begin_stop[i]);

		int min_sum=INT_MAX;
		for(int i=1;i<=n;++i)
		{
			int sum=0;
			bool flag=false;
			for(int j=0;j<n_person;++j)
				if(!month_ticket[j] && money[j]>=dist[begin_stop[j]][i])
					sum+=dist[begin_stop[j]][i];
        else if (!month_ticket[j] || dist[begin_stop[j]][i] == INT_MAX)
          flag=true;

      if (flag)
        continue;
			else if(min_sum> sum)
			{
				min_sum=sum;
				n_temp=i;
			}
		}
		if(min_sum==INT_MAX)
			printf("0\n");
		else
			printf("%d %d\n",n_temp,min_sum);
	}

  return 0;
}
