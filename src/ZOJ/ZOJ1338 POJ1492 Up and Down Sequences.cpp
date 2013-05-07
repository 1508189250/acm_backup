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

#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
int num[10000];
int flag[10000];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncount=0,temp;
	while(scanf("%d",&temp) &&temp)
	{
		memset(flag,0,sizeof(flag));
		num[0]=temp;
		ncount=1;
		while(1)
		{
			scanf("%d",&temp);
			if(temp==0) break;
			num[ncount++]=temp;
		}
		int upLen=0,upNum=0,downLen=0,downNum=0,same=0;
		for(int i=1;i<ncount;++i)
		{
			if(num[i]>num[i-1])
			{
				if(flag[i-1]==-1)
				{
					++downNum;
					downLen+=same;
					same=0;
				}
				upLen=upLen+same+1;
				same=0;
				flag[i]=1;
			}
			else if(num[i]<num[i-1])
			{
				if(flag[i-1]==1)
				{
					++upNum;
					upLen+=same;
					same=0;
				}
				downLen=downLen+same+1;
				same=0;
				flag[i]=-1;
			}
			else if(num[i]==num[i-1])
			{
				++same;
				flag[i]=flag[i-1];
			}
		}
		if(flag[ncount-1]==1)
		{
			++upNum;
			upLen+=same;
		}
		else if(flag[ncount-1]==-1)
		{
			++downNum;
			downLen+=same;
		}
		double ansUp=0.0,ansDown=0.0;
		if(upNum)
			ansUp=(double)upLen/upNum;
		if(downNum)
			ansDown=(double)downLen/downNum;
		printf("Nr values = %d:  %.6llf %.6llf\n",ncount,ansUp,ansDown);
	}

	return 0;
}
