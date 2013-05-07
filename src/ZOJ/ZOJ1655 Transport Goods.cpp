/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-19 10:45
 # Filename: ZOJ1655 Transport Goods.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1655 Transport Goods.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

#define INF 0.0000000000

int main(void)
{
	int N,M;
	double map[105][105];
	int goods[105];
	double dijkstra[105];
	int visit[105];
	int a,b;
	double len;

	while(cin>>N>>M)
	{
		memset(goods,0,sizeof(goods));
		memset(dijkstra,0,sizeof(dijkstra));
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=N;++i)
		{
			for(int j=1;j<=N;++j)
			{
				map[i][j]=INF;
			}
			map[i][i]=1;
		}

		for(int i=1;i<=N-1;++i)
			cin>>goods[i];

		for(int i=0;i<M;++i)
		{
			cin>>a>>b>>len;
			if (map[a][b]<1.0-len)//这里必须考虑到输入中路径重复但费率不同的问题
			{
				map[a][b]=map[b][a]=1.0-len;
			}
		}

		for(int i=1;i<=N;++i)
			dijkstra[i]=map[N][i];

		visit[N]=1;

		for(int i=1;i<N;++i)
		{
			int index;
			double mini(INF);

			for(int j=1;j<N;++j)
				if(!visit[j] && dijkstra[j]>INF && (dijkstra[j]>mini))
				{
					index=j;
					mini=dijkstra[j];
				}

			visit[index]=1;

			for(int j=1;j<N;++j)
				if(!visit[j] && map[index][j]>INF && (dijkstra[j] < map[index][j]*dijkstra[index]))
				{
					dijkstra[j]=map[index][j]*dijkstra[index];
				}
		}

		double sum(0.0);
		for(int i=1;i<N;++i)
			sum+=dijkstra[i]*goods[i];

		printf("%0.2f\n",sum);

	}
	return 0;
}
