/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-13 20:08
 # Filename: ZOJ1298 POJ1135 Domino Effect.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1298 POJ1135 Domino Effect.cpp : Defines the entry point for the console application.
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


using namespace std;

#define INFINITE numeric_limits<int>::max()

int main(void)
{
// 	ifstream cin("data.txt");
	int n,m;
	int x,y,len;
	int map[502][502];
	int visit[502];
	int lastvisit[502];
	int path[502];
	int ncases(1);

	while(cin>>n>>m &&(n||m))
	{

		if (n==1)
		{
			printf("System #%d\nThe last domino falls after 0.0 seconds, at key domino 1.\n\n",ncases++);
			continue;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				map[i][j]=INFINITE;
			map[i][i]=0;
		}

		for(int i=0;i<m;++i)
		{
			cin>>x>>y>>len;
			map[x][y]=len;
			map[y][x]=len;
		}

		memset(visit,0,sizeof(visit));
		visit[1]=1;

		memset(lastvisit,0,sizeof(lastvisit));
		memset(path,0,sizeof(path));
		for(int i=1;i<=n;++i)
		{
			path[i]=map[1][i];
			if(path[i]<INFINITE)
				lastvisit[i]=1;
		}


		for(int i=1;i<n;++i)
		{
			int min(INFINITE),minindex(1) ;

			for(int j=1;j<=n;++j)
			{
				if(!visit[j] && path[j]< min)
				{
					min=path[j];
					minindex=j;
				}
			}

			visit[minindex]=1;
			map[lastvisit[minindex]][minindex]=INFINITE;
			map[minindex][lastvisit[minindex]]=INFINITE;
			
			for(int j=1;j<=n;++j)
			{
				if(!visit[j] && map[minindex][j] < INFINITE
						&& path[j]>map[minindex][j]+path[minindex])
				{
					path[j]=map[minindex][j]+path[minindex];
					lastvisit[j]=minindex;
				}
			}
		}

		float total(0.0);
		int total_index;
		for(int i=1;i<=n;++i)
			if(path[i]>total)
			{
				total = path[i];
				total_index = i;
			}

		int flag(0);
		int a,b;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				if(map[i][j]<INFINITE && (total<(path[i]+path[j]+map[i][j])/2.0))
				{
					total = (path[i]+path[j] + map[i][j])/2.0;
					flag=1;
					a=i;
					b=j;
					map[i][j]=INFINITE;
					map[j][i]=INFINITE;
				}
			}

		cout<<"System #"<<ncases++<<endl;
		if(flag)
		{
			if (a>b)
			{
				swap(a,b);
			}
			printf("The last domino falls after %0.1f seconds, between key dominoes %d and %d.\n",total,a,b);
		}
		else
		{
			printf("The last domino falls after %0.1f seconds, at key domino %d.\n",total,total_index);
		}
		cout<<endl;

	}


	return 0;
}
