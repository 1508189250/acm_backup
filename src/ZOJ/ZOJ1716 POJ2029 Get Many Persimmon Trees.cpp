// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define	MAX 110
#define lowbit(x) (x&(-x))
#include <algorithm>
using namespace std;

int c[MAX][MAX];

void updata(const int &x,const int &y)
{
	for(int i=x;i<MAX;i+=lowbit(i))
		for(int j=y;j<MAX;j+=lowbit(j))
			++c[i][j];
}

int getsum(const int &x,const int &y)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			sum+=c[i][j];
	return sum;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n,w,h,s,t;
	int x,y;

	while(scanf("%d",&n)&&n)
	{
		memset(c,0,sizeof(c));
		scanf("%d%d",&w,&h);
		while(n--)
		{
			scanf("%d%d",&x,&y);
			updata(x,y);
		}
		scanf("%d%d",&s,&t);
		int ans=0;
		for(int i=s;i<=w;++i)
			for(int j=t;j<=h;++j)
				ans=max(ans,getsum(i,j)+getsum(i-s,j-t)-getsum(i,j-t)-getsum(i-s,j));

	printf("%d\n",ans);
	}

	return 0;
}
