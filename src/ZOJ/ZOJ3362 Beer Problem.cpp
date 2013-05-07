/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-10 19:47
 # Filename: ZOJ3362 Beer Problem.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG
// 

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <vector>
#include <stack>
#include <math.h>
#define MAX 120
using namespace std;

struct NODE
{
	int to,cap,value,next;
}node[MAX*MAX];

int city[MAX];
int cou,n,m;

void init()
{
	memset(city,-1,sizeof(city));
	cou=0;
}

void addEdge(int from,int to,int cap,int value)
{
	node[cou].to=to;
	node[cou].cap=cap;
	node[cou].value=value;
	node[cou].next=city[from];
	city[from]=cou++;

	node[cou].to=from;
	node[cou].cap=0;
	node[cou].value=-value;
	node[cou].next=city[to];
	city[to]=cou++;
}

int EKwithSPFA(int source,int target)
{
	int value[MAX],pre_v[MAX],pre_e[MAX],instack[MAX];	//pre_v��¼���ڵ����һ���ڵ㣬pre_e��¼������һ���ڵ㵽���ڵ�ıߵı��
	int ans=0;
	stack<int> mstack;

	while(1)
	{
		//���Ͻ���SPFA���ҳ�����·���з�����С��·��
		for(int i=source;i<=target;++i)
			value[i]=INT_MIN;
		value[source]=0;
		memset(instack,0,sizeof(instack));
		memset(pre_v,-1,sizeof(pre_v));	//ȫ��ָ����Ч�ڵ�
		instack[source]=1;
		mstack.push(source);	//������ջ�����Ƕ��п��Լ���ʱ��
		//spfa����ÿ���ߵ�value�����·
		while(!mstack.empty())
		{
			int u=mstack.top();
			mstack.pop();
			instack[u]=0;
			for(int i=city[u];i!=-1;i=node[i].next)
			{
				int v=node[i].to;
				if(node[i].cap>0 && value[v]<value[u]+node[i].value)	//�жϱ߻���û�����¿ռ䣬�Լ�����v�ڵ��������ܷ�����
				{
					value[v]=value[u]+node[i].value;
					pre_v[v]=u;
					pre_e[v]=i;
					if(!instack[v])
					{
						mstack.push(v);
						instack[v]=1;
					}
				}
			}
		}
		if(value[target]<=0)	//��������յ㣬�����Ǹ��������������ߵı߶������ˣ��˳�
			break;
		int a=INT_MAX;
		for(int u=target;u!=source;u=pre_v[u])
		{
			int e=pre_e[u];
			a=min(a,node[e].cap);	//�ҳ�����ͨ·��ƿ��
		}
		for(int u=target;u!=source;u=pre_v[u])
		{
			int e=pre_e[u];
			node[e].cap-=a;
			node[e^1].cap+=a;	//��������ͨ·�����бߵ��������������ߣ�ż����1�������1��������1�������1
		}
		ans+=value[target]*a;	//ƿ�������յ�ķ��þ��������ķ���
	}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int from,to,cap,value;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=2;i<=n;++i)
		{
			scanf("%d",&value);
			addEdge(i,n+1,INT_MAX,value);	//�������ǹ涨��Ŀ���������ȥ��ơ�Ƶļ۸�������
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d%d",&from,&to,&cap,&value);
			addEdge(from,to,cap,-value);	//�������ǹ涨����ɱ��Ǹ���
			addEdge(to,from,cap,-value);	//��Ҫ������˫���
		}
		int ans=EKwithSPFA(1,n+1);
		printf("%d\n",ans);
	}

	return 0;
}
