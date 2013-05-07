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
#define MAX 100100

using namespace std;

int pre[MAX];
int preson[MAX];
int find(int x)
{
	while(x !=pre[x])
		x=pre[x];
	return x;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,m;
	int a,b;
	int flag=1,ncase=1;
	char type;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(flag)
			flag=0;
		else
			printf("\n");
		printf("Case %d:\n",ncase++);
		for(int i=1;i<=n;++i)
			preson[i]=1,pre[i]=i;
		for(int i=0;i<m;++i)
		{
			getchar();
			scanf("%c",&type);
			if(type=='M')
			{
				scanf("%d %d",&a,&b);
				int x=find(a);
				int y=find(b);
				pre[a]=x;
				pre[b]=y;//加上这两行代码，减少搜索量
				if(y!=x)
				{
					pre[y]=x;
					preson[x]+=preson[y];
				}
			}
			else
			{
				scanf("%d",&a);
				printf("%d\n",preson[find(a)]);
			}
		}
	}

	return 0;
}
