// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 32010
#define lowbit(x) (x&(-x))
using namespace std;
int level[MAX];
int c[MAX];

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

void updata(int x)
{
	while(x<MAX)
	{
		++c[x];
		x+=lowbit(x);
	}
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,x,y,i;
	while(~scanf("%d",&n))
	{
		memset(level,0,sizeof(level));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&x,&y);
			++x;
			++level[getsum(x)];
			updata(x);
		}
		for(int i=0;i<n;++i)
			printf("%d\n",level[i]);
	}

	return 0;
}
