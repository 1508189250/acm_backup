// #include "stdafx.h"
// #define DEBUG

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

#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int times[300000];
int flag[300000];
int ncount=1;

void myclock()
{
	memset(times,0,sizeof(times));
	memset(flag,0,sizeof(flag));
	int sum=1;
	times[0]=sum;
	int second=1,minute=0,hour=0;
	while(second || minute || hour)
	{
		int temp=hour*10000+minute*100+second;
		if(temp%3==0)
		{
			++sum;
		}
		times[temp]=sum;
		int fMimute=(second+1)/60;
		second=(second+1)%60;
		int fHour=(minute+fMimute)/60;
		minute=(minute+fMimute)%60;
		hour=(hour+fHour)%24;
	}
	ncount=235959;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases,begin[3],end[3];
	myclock();
	scanf("%d",&ncases);
	while(ncases--)
	{
		int a,b;
		scanf("%d:%d:%d %d:%d:%d",&begin[0],&begin[1],&begin[2],&end[0],&end[1],&end[2]);
		a=begin[0]*10000+begin[1]*100+begin[2];
		b=end[0]*10000+end[1]*100+end[2];
		int from=a,to=b;
		int ans=0;
		if(from<=to)
		{
			ans=times[to]-times[from];
			if (from%3==0)
				++ans;
		}
		else
		{
			ans=times[ncount]-times[from];
			if(from%3==0) ++ans;
			ans+=times[to]-times[0]+1;
		}
		printf("%d\n",ans);
	}

	return 0;
}
