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
#include <limits.h>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int result[400];
int k,m;

int func()
{
	int ans=0;
	int ind=0;
	while(1)
	{
		if(result[k-1]==7)break;
		++ans;
		int carry=0;
		for(int i=0;i<=ind;++i)
		{
			result[i]=result[i]*m+carry;
			carry=0;
			if(result[i]>9)
			{
				carry=result[i]/10;
				result[i]%=10;
			}
		}
		result[ind+1]=carry;
		while(result[ind+1])
		{
			++ind;
			result[ind+1] =result[ind]/10;
			result[ind]%=10;
		}
	}
	return ans;
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	
	while(scanf("%d %d",&k,&m)!=EOF)
	{
		memset(result,0,sizeof(result));
		result[0]=1;
		int ans=func();
		printf("%d\n",ans);
	}

	return 0;
}
