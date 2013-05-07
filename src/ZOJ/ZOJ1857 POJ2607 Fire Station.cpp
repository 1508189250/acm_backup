// ZOJ1857 POJ2607 Fire Station.cpp : Defines the entry point for the console application.
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
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>
#include <assert.h>
#include <ctype.h>

#define MAX 510
#define maxint 1<<30

using namespace std;

int firestation[MAX],dist[MAX],visit[MAX];
int map[MAX][MAX];
int n;
queue<int> myqueue;

void spfa(int source)
{
	while(!myqueue.empty())
		myqueue.pop();
	memset(visit,0,sizeof(visit));
	
	for(int i=1;i<=n;++i)
		dist[i]=maxint;
	dist[source]=0;
	myqueue.push(source);
	visit[source]=1;

	while(!myqueue.empty())
	{
		int temp=myqueue.front();
		myqueue.pop();
		visit[temp]=0;

		for(int i=1;i<=n;++i)
		{
			if(dist[i]-dist[temp]>map[temp][i])
			{

				dist[i]=dist[temp]+map[temp][i];
				if(!visit[i])
					myqueue.push(i);
			}
		}
	}
	for (int i=1;i<=n;++i)
	{
		map[source][i]=dist[i];
	}
}

int main(void)
{
	int f;
	int len,a,b;
	char str[50];

	while(scanf("%d %d",&f,&n)!=EOF)
	{
		memset(firestation,0,sizeof(firestation));
		for(int i=0;i<f;++i)
		{
			scanf("%d",&a);
			++firestation[a];
		}
		if (n==1)
		{
			printf("1\n");
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
				map[i][j]=map[j][i]=maxint;
			map[i][i]=0;
		}
		getchar();
		while(gets(str) && strlen(str))
		{
			sscanf(str,"%d %d %d",&a,&b,&len);
			map[a][b]=map[b][a]=len;
		}

		for(int i=1;i<=n;++i)
			spfa(i);

		int minmaxlen=maxint;
		int index=0;
		for(int i=1;i<=n;++i)
		{
			if(!firestation[i])
			{
				++firestation[i];
				int maxlen=0;
				for(int j=1;j<=n;++j)
				{
					int temp=maxint;
					for(int k=1;k<=n;++k)
					{
						if(firestation[k] && map[j][k]<temp)
						{
							temp=map[j][k];
						}
					}
					if (maxlen<temp)
					{
						maxlen=temp;
					}
				}

				if(maxlen<minmaxlen)
				{
					minmaxlen=maxlen;
					index=i;
				}
				--firestation[i];
			}
		}
		if (index==0)
		{
			index=1;
		}
		printf("%d\n",index);
	}


	return 0;
}
