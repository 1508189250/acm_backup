// POJ2387 Til the Cows Come Home.cpp : Defines the entry point for the console application.
//

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

#define MAX 1010
#define maxint 1<<30

using namespace std;

int landmarks[MAX][MAX];
int path[MAX],visit[MAX];

int fspa(int source,int n)
{
	queue<int> myqueue;
	for(int i=1;i<=n;++i)
	{
		path[i]=maxint;
		visit[i]=0;
	}
	path[source]=landmarks[source][source];
	myqueue.push(source);
	visit[source]=1;
	while(!myqueue.empty())
	{
		int temp=myqueue.front();
		myqueue.pop();
		visit[temp]=0;
		for(int i=1;i<=n;++i)
			if(path[i]-path[temp]>landmarks[temp][i])
			{
				path[i]=path[temp]+landmarks[temp][i];
				if(!visit[i])
				{
					myqueue.push(i);
					visit[i]=1;
				}
			}
	}
	return path[n];
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int t,n,a,b,len;

	while(scanf("%d %d",&t,&n)!=EOF)
	{

		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				landmarks[i][j]=maxint;
			landmarks[i][i]=0;
		}

		for(int i=0;i<t;++i)
		{
			scanf("%d %d %d",&a,&b,&len);
			if (landmarks[a][b]>len)
			{
				landmarks[a][b]=landmarks[b][a]=len;
			}
		}

		printf("%d\n",fspa(1,n));

	}

	return 0;
}
