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
	int value[MAX],pre_v[MAX],pre_e[MAX],instack[MAX];	//pre_v记录本节点的上一个节点，pre_e记录的是上一个节点到本节点的边的编号
	int ans=0;
	stack<int> mstack;

	while(1)
	{
		//不断进行SPFA，找出残余路径中费用最小的路径
		for(int i=source;i<=target;++i)
			value[i]=INT_MIN;
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
				if(node[i].cap>0 && value[v]<value[u]+node[i].value)	//判断边还有没有余下空间，以及到底v节点后的利润能否增加
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
		if(value[target]<=0)	//如果到了终点，利润是负数，则代表可以走的边都走完了，退出
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

	int from,to,cap,value;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=2;i<=n;++i)
		{
			scanf("%d",&value);
			addEdge(i,n+1,INT_MAX,value);	//这里我们规定从目标城市卖出去的啤酒的价格是正数
		}
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d%d",&from,&to,&cap,&value);
			addEdge(from,to,cap,-value);	//这里我们规定运输成本是负数
			addEdge(to,from,cap,-value);	//不要忘了是双向边
		}
		int ans=EKwithSPFA(1,n+1);
		printf("%d\n",ans);
	}

	return 0;
}
