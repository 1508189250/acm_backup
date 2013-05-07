/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-18 15:06
 # Filename: ZOJ1592 POJ2263 Heavy Cargo.cpp
 # Description : 
 ******************************************************************************/
// ZOJ1592 POJ2263 Heavy Cargo.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <memory.h>

using namespace std;

#define INF 0

int main(void)
{
	int scenario=1;
	int n,r;
	map<string,int> mymap;
	int matrix[202][202];
	int path[202];
	int visit[202];
	string start,end;
	int len;

	while(cin>>n>>r &&n&&r)
	{
		mymap.clear();
		memset(path,0,sizeof(path));
		memset(visit,0,sizeof(visit));
		int index(0);

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				matrix[i][j]=INF;
			}
			matrix[i][i]=10000;
		}

		for(int i=0;i<r;++i)
		{
			cin>>start>>end>>len;
			if(mymap.find(start)==mymap.end())
			{
				mymap.insert( make_pair(start,index++));
			}
			if(mymap.find(end)==mymap.end())
			{
				mymap.insert( make_pair(end,index++));
			}
			matrix[mymap[start]][mymap[end]]=len;
			matrix[mymap[end]][mymap[start]]=len;
		}
		cin>>start>>end;
		int a=mymap[start],b=mymap[end];

		for(int i=0;i<n;++i)
		{
			path[i]=matrix[a][i];
		}
		visit[a]=1;

		for(int i=0;i<n;++i)
		{
			int minimum(INF);
			int index(i);

			for(int j=0;j<n;++j)
				if(!visit[j] && minimum<path[j] && path[j]> INF)
				{
					minimum=path[j];
					index=j;
				}
			visit[index]=1;

			for(int j=0;j<n;++j)
				if(!visit[j] && (matrix[index][j]>INF) && (path[j]<min(matrix[index][j],path[index])))
					path[j]=min(matrix[index][j],path[index]);
		}
			printf("Scenario #%d\n%d tons\n\n",scenario++,path[b]);

	}
	return 0;
}
