/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-05 20:03
 # Filename: ZOJ2770 Burn the Linked Camp.cpp
 # Description : 
	���Լ�������Ƕ���x[i]Ϊ��i��Ӫ������������dist[i]=x[0]+x[1]+...x[i],����x[0]=0,���֪����Ҫ���Ϊdist[n]��
	���ڲ�ֲ���ʽ��a - b <= c ����һ�� b �� a ��ȨֵΪ c �ıߣ���������·���õ��������ֵ�����ڲ���ʽ a - b >= c ����һ�� b �� a ��ȨֵΪ c �ıߣ�������·���õ�������Сֵ��������������Сֵ�����������õ��ǵڶ��֡�
	������Ŀ�����ǿ���������Լ��
	Ci��: x[i]=dist[i]-dist[i-1],����dist[i]-dist[i-1]>=0,��dist[i-1]-dist[i]>=-Ci
	i,j,k��: s[j]-s[i-1]>=k
	����: dist[i]>=0,��dist[i]-dist[0]>=0
	��Ϊ������Сֵ��ͬʱͼ�Ľ����ǰ���С�ڵ��ڽ��У��������Ǿ�Ҫ�Ӹ�����Լ������Сֵ����SPFA���·���ɡ�
	SPFA�������ж��Ƿ��л���
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
#include <queue>
#define MAX 1010
using namespace std;

struct NODE{
	int to,len;
	NODE *next;
}node[MAX*MAX],*apex[MAX];

int nodeInd,dist[MAX],n,m;
void init()
{
	nodeInd=0;
	memset(apex,'\0',sizeof(apex));
}

void add(int u,int v,int len)
{
	node[nodeInd].to=v;
	node[nodeInd].len=len;
	node[nodeInd].next=apex[u];
	apex[u]=&node[nodeInd++];
}

int spfa()
{
	queue<int> myqueue;
	int inque[MAX],time[MAX];
	memset(inque,0,sizeof(inque));
	memset(time,0,sizeof(time));
	myqueue.push(0);
	time[0]=inque[0]=1;
	for (int i=1;i<=n;++i)
		dist[i]=INT_MIN;
	dist[0]=0;
	while(!myqueue.empty())
	{
		int x=myqueue.front();
		myqueue.pop();
		inque[x]=0;
		NODE *head=apex[x];
		while(head)
		{
			int to=head->to;
			int len=head->len;
			if(dist[to]<dist[x]+len)
			{
				dist[to]=dist[x]+len;
				if(inque[to]==0)
				{
					myqueue.push(to);
					inque[to]=1;
					if(++time[to]>n)
						return -1;
				}
			}
			head=head->next;
		}
	}
	return dist[n];
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int u,v,len;

	while(scanf("%d %d",&n,&m)!=EOF)
	{
		init();
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&len);
			add(i-1,i,0);
			add(i,i-1,-len);
			add(0,i,0);
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d %d %d",&u,&v,&len);
			add(u-1,v,len);
		}
		int ans=spfa();
		if(ans==-1)
			printf("Bad Estimations\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
