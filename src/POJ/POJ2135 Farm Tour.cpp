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
	int value[MAX],pre_v[MAX],pre_e[MAX],instack[MAX];	//pre_v记录本节点的上一个节点，pre_e记录的是上一个节点到本节点的边的编号
	int ans=0;
	stack<int> mstack;

	while(1)
	{
		//不断进行SPFA，找出残余路径中费用最小的路径
		for(int i=source;i<=target;++i)
			value[i]=INT_MAX;
		value[source]=0;
		memset(instack,0,sizeof(instack));
		memset(pre_v,-1,sizeof(pre_v));	//全部指向无效节点
		instack[source]=1;
		mstack.push(source);	//我们用栈而不是队列可以减少时间
		//spfa根据每条边的value求最短路
		while(!mstack.empty())
		{
			int u=mstack.top();
			mstack.pop();
			instack[u]=0;
			for(int i=city[u];i!=-1;i=node[i].next)
			{
				int v=node[i].to;
				if(node[i].cap>0 && value[v]>value[u]+node[i].value)	//判断边还有没有余下空间，以及到底v节点后的路径能否减少
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
		if(value[target]==INT_MAX)	//如果到了终点，路径仍是无限大，退出
			break;
		int a=INT_MAX;
		for(int u=target;u!=source;u=pre_v[u])
		{
			int e=pre_e[u];
			a=min(a,node[e].cap);	//找出这条通路的瓶颈
		}
		for(int u=target;u!=source;u=pre_v[u])
		{
			int e=pre_e[u];
			node[e].cap-=a;
			node[e^1].cap+=a;	//更新这条通路上所有边的容量，异或求反向边，偶数和1异或代表加1，奇数和1异或代表减1
		}
		ans+=value[target]*a;	//瓶颈乘以终点的费用就是新增的费用
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
			addEdge(to,from,1,cost);	//记得是双向的
		}
		int ans=EKwithSPFA(0,n+1);
		printf("%d\n",ans);
	}

	return 0;
}
