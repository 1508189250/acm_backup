#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <ctype.h>

#include <set>
#include <stack>
#include <queue>
#include <deque>
#define MAX 100010

using namespace std;

struct ADJ
{
	int from,to,len;
};
class cmp
{
	public:
		cmp()
		{}
		bool operator()(const ADJ &lhs,const ADJ &rhs) const
		{
			if(lhs.len!=rhs.len)
				return lhs.len>rhs.len;
			else if(lhs.from!=rhs.from)
				return lhs.from>rhs.from;
			else
				return lhs.to>rhs.to;
		}
};

int visit[MAX],pre[MAX],n,m;
set< ADJ , cmp > myset;
void init()
{
	myset.clear();
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=n;++i)
		pre[i]=i;
}

int inline find(int x)
{
	
	return x==pre[x]?x:find(pre[x]);
}

int solve(const int &from,const int &to)
{
	int maxWeight;
	set< ADJ,cmp >::iterator iter=myset.begin();
	for(;iter!=myset.end();++iter)
	{
		int a=iter->from,b=iter->to,weight=iter->len;
		int x=find(a),y=find(b);
		if(x!=y)
		{
			pre[a]=pre[b]=pre[x]=pre[y]=min(x,y);
			maxWeight=weight;
		}
		if(find(from)==find(to))
			break;
	}
	return maxWeight;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int from,to,len;
	ADJ edge;

	while(scanf("%d %d",&n,&m)!=EOF)
	{
		init();
		for(int i=0;i<m;++i)
		{
			scanf("%d %d %d",&edge.from,&edge.to,&edge.len);
			myset.insert(edge);
		}
		scanf("%d %d",&from,&to);
		len=solve(from,to);
		printf("%d\n",len);
	}


	return 0;
}
