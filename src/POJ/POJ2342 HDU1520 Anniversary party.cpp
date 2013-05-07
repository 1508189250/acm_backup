/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-26 19:22
 # Filename: POJ2342 HDU1520 Anniversary party.cpp
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
#define MAX 100010
using namespace std;

struct NODE
{
	int child,father,brother,present,not_present;
	int max()
	{
		return present>not_present?present:not_present;
	}
	void init()
	{
		child=father=brother=not_present=0;
	}
}node[MAX];

void dfs(const int &idx)
{
	int child=node[idx].child;
	while(child)
	{
		dfs(child);
		node[idx].present+=node[child].not_present;//第idx个参加，则孩子节点不能参加
		node[idx].not_present+=node[child].max();   //第idx个不参加，则孩子节点可参加可不参加
		child=node[child].brother;
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;

  while(~scanf("%d",&n) && n)
  {
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&node[i].present);
			node[i].init();
		}
		int k,l;
		while(scanf("%d%d",&l,&k) && k+l)
		{
			node[l].father=k;
			node[l].brother=node[k].child;
			node[k].child=l;
		}
		for(int i=1;i<=n;++i)
			if(!node[i].father)
			{
				dfs(i);
				printf("%d\n",node[i].max());
				break;
			}
  }

  return 0;
}
