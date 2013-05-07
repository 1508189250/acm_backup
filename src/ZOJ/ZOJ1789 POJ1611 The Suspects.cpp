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
#define MAX 30010

using namespace std;
int pre[MAX];
int inline find(int x)
{
	while(x!=pre[x])
		x=pre[x];
	return x;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,m;
	int num,stu1,stu2;
	while(scanf("%d %d",&n,&m)&&n)
	{

		for(int i=0;i<n;++i)
			pre[i]=i;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&num,&stu1);
			for(int j=2;j<=num;++j)
			{
				scanf("%d",&stu2);
				int x=find(stu1);
				int y=find(stu2);
				pre[stu1]=x;
				pre[stu2]=y;
				pre[x]=pre[y]=min(pre[x],pre[y]);
			}
		}
		num=0;
		for(int i=0;i<n;++i)
			if(find(i)==0)
				++num;
		printf("%d\n",num);
	}

	return 0;
}
