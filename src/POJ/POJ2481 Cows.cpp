// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 100010
#include <algorithm>
#define lowbit(x) (x&(-x))
using namespace std;

struct SE
{
	int s,e,ind;
}se[MAX];
int c[MAX],result[MAX];

void updata(int x)
{
	while(x<MAX)
	{
		++c[x];
		x+=lowbit(x);
	}
}

int getsum(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

bool cmp(const SE &lhs,const SE &rhs)
{
	if(lhs.e==rhs.e)
		return lhs.s<rhs.s;
	else
		return lhs.e>rhs.e;
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,s,e;
	while(scanf("%d",&n) &&n)
	{
		memset(c,0,sizeof(c));
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&s,&e);
			se[i].s=s+1,se[i].e=e,se[i].ind=i;
		}
		sort(se,se+n,cmp);

		int ans=getsum(se[0].s);
		int te=se[0].e,ts=se[0].s;
		result[se[0].ind]=ans;
		updata(se[0].s);

		for(int i=1;i<n;++i)
		{
			if(se[i].s==ts && se[i].e==te)
			{
				result[se[i].ind]=ans;
				updata(se[i].s);
			}
			else
			{
				ts=se[i].s;
				te=se[i].e;
				ans=getsum(ts);
				result[se[i].ind]=ans;
				updata(ts);
			}
		}

		for(int i=0;i<n;++i)
		{
			if(i!=0)
				printf(" ");
			printf("%d",result[i]);
		}
		printf("\n");
	}

	return 0;
}
