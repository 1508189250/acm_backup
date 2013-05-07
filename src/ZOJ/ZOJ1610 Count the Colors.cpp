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
#include <set>
#define MAX 8010*2
using namespace std;
struct POINT
{
	int x,y,color;
}points[MAX];
int x[MAX];
int color[MAX];
int len[MAX];

void func(const int &n,const int &cnt)
{
	sort(x,x+cnt);
	memset(color,-1,sizeof(color));
	for(int i=0;i<n;++i)
	{
		int a = lower_bound(x,x+cnt,points[i].x)-x;
		int b = lower_bound(x,x+cnt,points[i].y)-x;
		for(int j=a;j<b;++j)
			color[j]=points[i].color;
	}
	memset(len,0,sizeof(len));
	for(int i=0;i<MAX;++i)
		if(color[i+1]!=color[i] && color[i]!=-1)
			len[color[i]]++;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n;
	while(~scanf("%d",&n))
	{
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&points[i].x,&points[i].y,&points[i].color);
			x[cnt++]=points[i].x;
			x[cnt++]=points[i].y;
		}
		func(n,cnt);
		for(int i=0;i<MAX;++i)
			if(len[i])
				printf("%d %d\n",i,len[i]);
		printf("\n");
	}

  return 0;
}
