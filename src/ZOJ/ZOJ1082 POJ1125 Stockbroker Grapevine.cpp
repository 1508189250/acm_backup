/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-08-12 22:04
 * Filename : ZOJ1082 POJ1125 Stockbroker Grapevine.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ1082 POJ1125 Stockbroker Grapevine.cpp : Defines the entry point for the console application.
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

#define maxint 1<<30
#define MAX 110

using namespace std;

int map[MAX][MAX];
int visit[MAX];
int dist[MAX];
int n;

int spfa(int source)
{
	queue<int> myqueue;
	int maxlen=0;
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=n;++i)
		dist[i]=maxint;
	dist[source]=0;
	myqueue.push(source);
	visit[source]=1;

	while(!myqueue.empty())
	{
		source=myqueue.front();
		myqueue.pop();
		visit[source]=0;

		for(int i=1;i<=n;++i)
		{
			if(dist[i]-dist[source]>map[source][i])
			{
				dist[i]=dist[source]+map[source][i];
				if(!visit[i])
				{
					myqueue.push(i);
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		if(maxlen<dist[i])
			maxlen=dist[i];
	return maxlen;
}

int main(void)
{
//  	ifstream cin("data.txt");
	int m;
	int b,len;

	while(cin>>n &&n)
	{
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j)
				map[i][j]=map[j][i]=maxint;

		for(int i=1;i<=n;++i)
		{
			cin>>m;
			for(int j=0;j<m;++j)
			{
				cin>>b>>len;
				map[i][b]=len;
			}
		}

		int maxlen=maxint;
		int temp=0;
		int index;
		for(int i=1;i<=n;++i)
		{
			temp=spfa(i);
			if(temp<maxlen)
			{
				maxlen=temp;
				index=i;
			}
		}

		if(maxlen<maxint)
			cout<<index<<' '<<maxlen<<endl;
		else
			cout<<"disjoint"<<endl;

	}

	return 0;
}
