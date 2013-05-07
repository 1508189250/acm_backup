/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-20 14:45
 # Filename: ZOJ2526 FatMouse and JavaBean II.cpp
 # Description : 
 ******************************************************************************/
// ZOJ2526 FatMouse and JavaBean II.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <stack>

using namespace std;

#define MAX_NUM 502
#define INF 1<<30


int mat[MAX_NUM][MAX_NUM];
int bean[MAX_NUM];
int dij[MAX_NUM];
int visit[MAX_NUM];
int last[MAX_NUM];
int beansum[MAX_NUM];

int DFS(int start,int end,int len,int n);

int main(void)
{
// 	ifstream cin("data.txt");

	int N,M,sou,des,a,b,len;

	while(cin>>N>>M>>sou>>des)
	{
		for(int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				mat[i][j]=INF;
			}
			mat[i][i]=0;
			last[i]=-1;
			dij[i]=INF;
		}
		memset(visit,0,sizeof(visit));
		memset(beansum,0,sizeof(beansum));

		for(int i=0;i<N;++i)
			cin>>bean[i];
		for(int i=0;i<M;++i)
		{
			cin>>a>>b>>len;
			mat[a][b]=mat[b][a]=len;
		}

		int now=sou;
		dij[now]=0;
		visit[now]=1;
		beansum[now]=bean[now];

		for(int i=0;i<N;++i)
		{
			int min(INF);
			for(int j=0;j<N;++j)
				if(!visit[j] && mat[now][j]<INF && dij[j]>=dij[now]+mat[now][j])
				{
					if(dij[j]>dij[now]+mat[now][j])
					{
						dij[j]=dij[now]+mat[now][j];
						beansum[j]=beansum[now]+bean[j];
						last[j]=now;
					}
					else if(beansum[j]<beansum[now]+bean[j])
					{
						beansum[j]=beansum[now]+bean[j];
						last[j]=now;
					}
				}
			for(int j=0;j<N;++j)
				if(!visit[j] && min>dij[j])
					min=dij[now=j];
			visit[now]=1;
		}

		stack<int> mystack;
		for (int i=des;i!=sou;i=last[i])
			mystack.push(i);

		memset(visit,0,sizeof(visit));
		int pathcount(DFS(sou,des,dij[des],N));
// 		int pathcount(0);

		printf("%d %d\n",pathcount,beansum[des]);
		printf("%d",sou);
		while(!mystack.empty())
		{
			printf(" %d",mystack.top());
			mystack.pop();
		}
		printf("\n");

	}

	return 0;
}


int DFS(int start,int end,int len,int n)
{
	visit[start]=1;
	int result(0);
	if(start==end&&!len)
		result=1;
	else if(len<0)
		result=0;
	else
	{
		for(int i=0;i<n;++i)
		{
			if(mat[start][i]<INF && !visit[i])
				result+=DFS(i,end,len-mat[start][i],n);
		}
	}
	visit[start]=0;
	return result;
}
