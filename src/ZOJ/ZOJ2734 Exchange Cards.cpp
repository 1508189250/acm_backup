// ZOJ2734 Exchange Cards.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>
#include <assert.h>
#include <ctype.h>

using namespace std;

int num[1010];
int m,way;
int sum,value;

void dfs(int x)
{
	if(sum==value)
	{
		++way;
		return;
	}
	else
	{
		for(int i=x;i+sum<=value;++i)
			if(num[i])
			{
				sum+=i;
				--num[i];
				dfs(i);
				sum-=i;
				++num[i];
			}
	}

}

int main(void)
{
	int flag=1;
	while(cin>>value>>m)
	{
		sum=0,way=0;
		int x,y;
		memset(num,0,sizeof(num));

		for(int i=0;i<m;++i)
		{
			scanf("%d %d",&x,&y);
			num[x]=y;
		}

		dfs(1);

		if(flag)
			flag=0;
		else
			printf("\n");
		printf("%d\n",way);

	}


	return 0;
}
