// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define lowbit(x) (x&(-x))
#define MAX 1010
using namespace std;

struct ROAD
{
	int x,y;
}road[MAX*MAX];

long long c[MAX];

void updata(int x)
{
	while(x<MAX)
	{
		++c[x];
		x+=lowbit(x);
	}
}

long long getsum(int x)
{
	long long  sum=0;
	while(x>0)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

bool cmp(const ROAD &lhs,const ROAD &rhs)
{
	if(lhs.y !=rhs.y)
		return lhs.y>rhs.y;
	else
		return lhs.x>rhs.x;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int ncases;
	scanf("%d",&ncases);
	int n,m,k;
	int u,v;
	
	for(int nc=1;nc<=ncases;++nc)
	{
		memset(c,0,sizeof(c));
		long long ans=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;++i)
		{
			scanf("%d%d",&u,&v);
			road[i].x=u;
			road[i].y=v;
		}
		sort(road,road+k,cmp);
		for(int i=0;i<k;++i)
		{
			ans+=getsum(road[i].x-1);
			updata(road[i].x);
		}

		printf("Test case %d: %lld\n",nc,ans);
	}

	return 0;
}
