/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-20 18:23
 # Filename: ZOJ1406 POJ1251 Jungle Roads.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1406 POJ1251 Jungle Roads.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <memory.h>

using namespace std;

#define INF 1<<30

int map[27][27];
int dij[27];

int prim(int start,int n);
int input(int n);

int main(void)
{
	int n;

	while(cin>>n && n)
	{
		input(n);
		printf("%d\n",prim(0,n));
	}
	return 0;
}

int input(int n)
{
	int len,num;
	char a,b;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			map[i][j]=INF;
		map[i][i]=INF;
		dij[i]=INF;
	}

	for(int i=0;i<n-1;++i)
	{
		cin>>a>>num;
		a-='A';
		for(int j=0;j<num;++j)
		{
			cin>>b>>len;
			b-='A';
			map[a][b]=map[b][a]=len;
		}
	}
	return 0;
}

int prim(int start,int n)
{
	int visit[27];
	memset(visit,0,sizeof(visit));

	int now=start;
	visit[now]=1;
	dij[now]=0;

	for(int i=0;i<n;++i)
	{
		int mini(INF);
		for(int j=0;j<n;++j)
			if(!visit[j] && map[now][j]<INF && dij[j]>map[now][j])
				dij[j]=map[now][j];

		for(int j=0;j<n;++j)
			if(!visit[j] && dij[j]<mini)
				mini = dij[now=j];
		visit[now]=1;
	}

	int sum(0);
	for(int i=0;i<n;++i)
		sum+=dij[i];

	return sum;
}
