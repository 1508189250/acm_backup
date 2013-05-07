// #include "stdafx.h"
// #define DEBUG


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
#define MAX 1020
using namespace std;

struct NODE
{
	int to,cap,value,next;
}node[MAX*40];

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
			value[i]=INT_MAX;
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
				if(node[i].cap>0 && value[v]>value[u]+node[i].value)	//�жϱ߻���û�����¿ռ䣬�Լ�����v�ڵ���·���ܷ����
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
		if(value[target]==INT_MAX)	//��������յ㣬·���������޴��˳�
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

	int from,to,cap,cost;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		addEdge(0,1,2,0);
		addEdge(n,n+1,2,0);
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&from,&to,&cost);
			addEdge(from,to,1,cost);
			addEdge(to,from,1,cost);	//�ǵ���˫���
		}
		int ans=EKwithSPFA(0,n+1);
		printf("%d\n",ans);
	}

	return 0;
}
