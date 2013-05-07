// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <queue>
#include <limits.h>
#define MAX 210
using namespace std;

int map[MAX][MAX],flow[MAX][MAX];
int pre[MAX],visit[MAX];
//map��¼����ÿ���������Գ��ܵ�������flow��¼ÿ�����Ѿ����ܵ�������visit��¼���ǵ�ÿ���ڵ��������pre��¼�ڵ��ǰ��
int n,m;

int EK(const int &source,const int &target)
{
	queue<int> mQueue;
	int ans=0;
	memset(flow,0,sizeof(flow));
	memset(pre,0,sizeof(pre));
	while(true)	//ÿһ������BFS��һ��Դ�㵽�յ�����·
	{
		mQueue.push(source);
		memset(visit,0,sizeof(visit));	//����ÿһ��BFS����Ҫ��visi���
		visit[source]=INT_MAX;	//���Ǽ������Դ�ڵ�����������޴�
		while(!mQueue.empty())
		{
			int u=mQueue.front();
			mQueue.pop();
			for(int v=1;v<=m;++v)
				if(!visit[v] && map[u][v]>flow[u][v])	//���·��Ҫ����ÿ�����Ѿ����ܵ�����С��ÿ���߿��Գ��ܵ��������
				{
					mQueue.push(v);
					visit[v]=min(visit[u],map[u][v]-flow[u][v]);	//v��ǰ���ڵ��Ѿ����ܵ�������u��v�仹���Գ�����������Сֵ
					pre[v]=u;
				}
		}
		if(visit[target]==0)	//���Ŀ����Ѿ�û�������ˣ�Ҳ���Ǵ�Դ�㵽Ŀ��������·�����Ѿ����������������ˣ�����ѭ��
			break;
		for(int u=target;u!=source;u=pre[u])
		{
			flow[pre[u]][u]+=visit[target];
			flow[u][pre[u]]-=visit[target];
		}
		ans+=visit[target];
	}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int u,v,cap;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(map,0,sizeof(map));
		while(n--)
		{
			scanf("%d%d%d",&u,&v,&cap);
			map[u][v]+=cap;
		}
		int ans=EK(1,m);
		printf("%d\n",ans);
	}

	return 0;
}
