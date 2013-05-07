// ZOJ1203 Swordfish.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"




#include <fstream>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <memory.h>


using namespace std;
#define MAX_NUM 102
#define INF 1<<30
int n;
double x[MAX_NUM],y[MAX_NUM],map[MAX_NUM][MAX_NUM];
double dij[MAX_NUM];

void input()
{
	for(int i=0;i<n;++i)
	{
		cin>>x[i]>>y[i];
	}

	for(int i=0;i<n;++i)
		for(int j=i;j<n;++j)
			map[i][j]=map[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

void prim()
{
	int visit[MAX_NUM];
	double sum=0.0;
	int now=0;
	memset(visit,0,sizeof(visit));
	visit[now]=1;
	for(int i=0;i<n;++i)
		dij[i]=INF;
	dij[now]=0;

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			if(!visit[j] && dij[j]>map[now][j])
				dij[j]=map[now][j];

		double min=INF;

		for(int j=0;j<n;++j)
			if(!visit[j] && min>dij[j])
				min=dij[now=j];

		visit[now]=1;
	}

	for(int i=0;i<n;++i)
		sum+=sqrt(dij[i]);

	printf("The minimal distance is: %0.2f\n",sum);
}




int main(void)
{
	int casenum=1;

	while(cin>>n && n)
	{
		if (casenum>1)
		{
			printf("\n");
		}
		printf("Case #%d:\n",casenum++);
		input();
		prim();
		
	}


	return 0;
}
