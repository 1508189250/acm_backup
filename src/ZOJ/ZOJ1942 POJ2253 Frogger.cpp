/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-19 15:09
 # Filename: ZOJ1942 POJ2253 Frogger.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1942 POJ2253 Frogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <functional>

using namespace std;

#define INF 1<<30

int main(void)
{
	int scenario(1);
	int n;
	int coord[2][202];
	int map[202][202];
	int dijkstra[202];
	int visit[202];

	while(cin>>n && n)
	{
		memset(dijkstra,0,sizeof(dijkstra));
		memset(visit,0,sizeof(visit));
		for(int i=0;i<n;++i)
		{
			map[i][i]=0;
		}

		for(int i=0;i<n;++i)
			cin>>coord[0][i]>>coord[1][i];

		for(int i=0;i<n-1;++i)
		{
			for(int j=i+1;j<n;++j)
				map[i][j]=map[j][i]=pow(coord[0][i]-coord[0][j],2.0)+pow(coord[1][i]-coord[1][j],2.0);
		}

		for(int i=0;i<n;++i)
			dijkstra[i]=map[0][i];
		visit[0]=1;

		for(int i=0;i<n;++i)
		{
			int mini(INF);
			int index(0);

			for(int j=0;j<n;++j)
				if(!visit[j] && (dijkstra[j]<INF) && mini>dijkstra[j])
				{
					mini=dijkstra[j];
					index=j;
				}

			visit[index]=1;

			for(int j=0;j<n;++j)
				if(!visit[j] && (dijkstra[j]>max(dijkstra[index],map[index][j])))
					dijkstra[j]=max(dijkstra[index],map[index][j]);
		}

		printf("Scenario #%d\nFrog Distance = %0.3f\n\n",scenario++,sqrt(dijkstra[1]*1.0));

	}


	return 0;
}
