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
#define MAX 24*3600
using namespace std;

struct PERFORMANCE{int beg,end;}performances[MAX];

int times[MAX];
int days[MAX];
int ncou;

int func(const int &n)
{
	int maxtime=INT_MIN;
	for(int i=0;i<n;++i)
	{
		int beg=lower_bound(times,times+ncou,performances[i].beg)-times;
		int end=lower_bound(times,times+ncou,performances[i].end)-times;
		for(int i=beg;i<=end;++i)
			++days[i];
	}
	int ans=INT_MIN;
	for(int i=0;i<ncou;++i)
		ans=max(ans,days[i]);
	return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n;
	while(scanf("%d",&n)&&n)
	{
		memset(times,0,sizeof(int)*n*2);
		memset(days,0,sizeof(int)*n*2);
		ncou=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&performances[i].beg,&performances[i].end);
			times[ncou++]=performances[i].beg;
			times[ncou++]=performances[i].end;
		}
		sort(times,times+ncou);
    ncou = unique(times,times+ncou)-times;
		int ans=func(n);
		printf("%d\n", ans);
	}

  return 0;
}
