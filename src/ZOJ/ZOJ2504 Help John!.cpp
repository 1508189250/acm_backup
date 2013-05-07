/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-17 21:22
 # Filename: ZOJ2504 Help John!.cpp
 # Description : 
 ******************************************************************************/
// ZOJ2504 Help John!.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <stdio.h>
#include <memory.h>

using namespace std;
#define MAX_NUM 1002
#define INF 2000000

int main(void)
{
// 	ifstream cin("data.txt");
	int ncases;
	int n,m,k;
	int map[MAX_NUM][MAX_NUM];
	int path[MAX_NUM];
	int dijtstra[MAX_NUM];
	int meet;
	int a,b,len;


	scanf("%d",&ncases);

	for(int casenum=1;casenum<=ncases;++casenum)
	{
		int oldtotal(0),newtotal(INF);
		int flag(1);
		memset(path,0,sizeof(path));
		memset(dijtstra,0,sizeof(dijtstra));

		for(int i=0;i<MAX_NUM;++i)
		{
			for(int j=0;j<MAX_NUM;++j)
			{
				map[i][j]=INF;
			}
			map[i][i]=0;
		}

		scanf("%d %d",&n,&m);
		for(int i=0;i<m;++i)
		{
			scanf("%d %d %d",&a,&b,&len);
			map[a][b]=len;
			map[b][a]=len;
		}

		scanf("%d",&k);
		a=1;
		for(int i=0;i<k;++i)
		{
			scanf("%d",&b);
			if (i==1)
			{
				meet=b;
			}
			if(map[a][b]<INF)
			{
				oldtotal +=map[a][b];
				a=b;
			}
			else
			{
				flag=0;
				break;
			}
		}

		if(!flag)
		{
			printf("TEST %d N\n",casenum);
			continue;
		}

		for(int i=1;i<=n;++i)
		{
			dijtstra[i]=map[meet][i];
		}
		path[1]=1;
		path[meet]=1;

		for(int i=1;i<n;++i)
		{
			int min(INF);
			int index(1);
			for(int j=1;j<=n;++j)
			{
				if(!path[j] && (min>dijtstra[j]) && dijtstra[j]<INF)
				{
					min=dijtstra[j];
					index=j;
				}
			}

			path[index]=1;

			for(int j=1;j<=n;++j)
			{
				if(!path[j] && (map[index][j]<INF) && (dijtstra[j]>map[index][j]+dijtstra[index]))
				{
					dijtstra[j]=map[index][j]+dijtstra[index];
				}
			}

		}


		newtotal=dijtstra[n]+map[1][meet];


		printf("TEST %d Y %d\n",casenum,oldtotal-newtotal);
	}

	return 0;
}
