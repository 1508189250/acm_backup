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
#define esp 1e-5

using namespace std;
struct NODE
{
	double x,y;
}node[4];

bool cmp(const struct NODE &lhs,const struct NODE &rhs)
{
	if(lhs.x!=rhs.x)
		return lhs.x<rhs.x;
	else
		return lhs.y<rhs.y;
}
double inline distence(const struct NODE &lhs,const struct NODE &rhs)
{
	return ((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	int flag=1;
	scanf("%d",&ncases);
	for(int i=1;i<=ncases;++i)
	{
		getchar();
		if(flag)
			flag=0;
		else
			printf("\n");
		printf("Case %d:\n",i);
		for(int j=0;j<4;++j)
			scanf("%lf %lf",&node[j].x,&node[j].y);
		sort(node,node+4,cmp);
		if(distence(node[0],node[1])==distence(node[0],node[2]))
			if(distence(node[3],node[1])==distence(node[3],node[2]))
				if(distence(node[0],node[1])+distence(node[0],node[2])==distence(node[1],node[2]))
				{
					printf("Yes\n");
					continue;
				}
		printf("No\n");
	}

	return 0;
}
