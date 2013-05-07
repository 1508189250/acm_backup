/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-17 20:45
 # Filename: ZOJ2314 Reactor Cooling.cpp
 # Description : 
	��һ������ʵ����Ҫ��ÿ���ߵ��½���ȥ�����������ʶ�������ģ�ͣ�������һ��������λ���
	�ܵ���˵�����½�һ��ԭ���� s,t����ԭ����ÿ����i����m(i)=sum{b<j,i>}-sum{b<i,j>}����b<>Ϊ�����½磬��m(i)>0����һ��<s,i>����Ϊm(i)�ıߣ���m(i)<0����һ��<i,t>����Ϊ|m(i)|�ıߡ�Ȼ��ԭ���ߵ�������Ϊc<i,j>-b<i,j>����һ��������������s��t�����ı�ȫ������������������ڣ���ÿ���ߵ�����Ϊ���ڵ�����+�������½硣���򲻴��ڿ�������
	�ܵ���˵�������Ҫ���½�����������ɴ�Դ�㵽�����㣬�ʹӸ����㵽��������������ʵ�֣����ǽ�ͼ�ļ����ˣ����ǿ��Կ�һ�����´��롣
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>
#include <queue>
#define MAX 210
using namespace std;

int cap[MAX][MAX],flow[MAX][MAX];
int level[MAX];
int target,source,n;
queue<int> mque;

bool BFS()
{
	memset(level,-1,sizeof(level));
	level[source]=0;
	mque.push(source);

	while(!mque.empty())
	{
		int x=mque.front();
		mque.pop();
		for(int v=0;v<=target;++v)
		{
			if(cap[x][v]>flow[x][v] && level[v]==-1)
			{
				level[v]=level[x]+1;
				mque.push(v);
			}
		}
	}
	return level[target]!=-1;
}

int dinic(int now,int sum)
{
	int i,a,os;
	if(now==target)
		return sum;
	os = sum;
	for(int i=0; i<=target && sum; ++i)
		if(level[i]==level[now]+1 && cap[now][i]>flow[now][i])
		{
			a = dinic(i,min(sum,cap[now][i]-flow[now][i]));
			flow[now][i]+=a;
			flow[i][now]-=a;
			sum -=a;
		}
	return os-sum;
}

int from[MAX*MAX],to[MAX*MAX],down[MAX*MAX];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int m,ncases;
	int f,t,up;
	scanf("%d",&ncases);
	while(ncases--)
	{

		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));

		scanf("%d%d",&n,&m);
		source=0;
		target=n+1;
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d%d",&from[i],&to[i],&down[i],&up);
			cap[from[i]][to[i]] += up-down[i];
			cap[0][to[i]] += down[i];				//��ע�������У�0��to[i]������ʾԴ���ṩ��ÿ�������½�
			cap[from[i]][n+1]+=down[i];			//from[i]��n+1������ʾ�����Ҫ��ÿ�������½�
		}
		
		while(BFS())
			dinic(source,INT_MAX);

		int flag=1;
		for(int i=0;i<m;++i)
			if(cap[0][to[i]]!=flow[0][to[i]] || cap[from[i]][target]!=flow[from[i]][target])	//����ÿһ�����㣬������ǲ����صĻ����ʹ�������û�дﵽ�½�
			{
				flag=0;
				break;
			}
		if(flag)
		{
			printf("YES\n");
			for(int i=0;i<m;++i)
				printf("%d\n",flow[from[i]][to[i]]+down[i]);
		}
		else
			printf("NO\n");

	}

	return 0;
}
