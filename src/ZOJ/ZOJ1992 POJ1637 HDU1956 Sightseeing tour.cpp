/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-01 19:53
 # Filename: ZOJ1992 POJ1637 HDU1956 Sightseeing tour.cpp
 # Description : 
 题意：给出一个混合图（有的边有向，有的边无向），问此图是否存在欧拉回路。 

 先说说欧拉回路吧，起点和终点相同，经过图G的每条边一次，且只经过一次的路径称为欧拉回路。 
 按照图的不同分为：无向图欧拉回路、有向图欧拉回路和混合图欧拉回路。 

 判断一个图是否存在欧拉回路： 
 1.无向图：图连通，且图中均为偶度顶点。 
 2.有向图：图连通，且图中所有顶点出入度相等。 
 3.混合图：混合图欧拉回路的判断是用网络流，实现方法： 

 首先对所有的无向边随便定向，之后会进行调整。然后统计每个点的出入度，如果有某个点出入度之差为奇数，则不存在欧拉回路，因为相差为奇数的话，无论如果调整边，都不能使得每个点的出入度相等。 
 现在每个点的出入度之差为偶数了，把这个偶数除以2,得x。则对每个顶点改变与之相连的x条边的方向就可以使得该点出入度相等。如果每个点都能达到出入度相等，自然就存在欧拉回路了。 
 现在问题就变成了改变哪些边的方向能让每个点出入度相等了，构造网络流模型。 
 有向边不能改变方向，所以不添加有向边。对于在开始的时候任意定向的无向边，按所定的方向加边，容量为1。源点向所有出>入的点连边，容量为该点的x值；所有入>出的点向汇点连边，容量为该点的x值。 
 建图完成了，求解最大流，如果能满流分配，则存在欧拉回路。那么哪些边改变方向才能得到欧拉回路呢？查看流量分配，所有流量非0的边就是要改变方向的边。 
 原理是因为满流分配，所以和源点相连的点一定都有x条边流入，将这些边反向这些点就出入度相等了，和汇点相连的亦然。没有和源、汇相连的已经出入度相等了，当然不用修改，至此欧拉回路求解完毕。 

 具体实现方法：
 大致就是，先将无向边定向，就是比如1<->3，可以定它的方向为1->3，1的出度++，3的入度++即可。
 读入的时候如果遇到无向边，把这条边加入待建的网络中，流量为1。读入完后，然后用出度减入度得到x，如果x为奇数，肯定不存在欧拉回路，如果没有奇数，就用最大流求解。
 如果x大于0，则建一条s（源点）到当前点容量为x/2的边，如果x小于0，建一条从当前点到 t（汇点）容量为|x/2|的边。
 然后求最大流，如果是满流（即s出的流==t入的流即可，s指的是建图的时候连接s的边的容量和）就满足欧拉回路。
 这题我用递归的dinic做的，开始用并查集判连通了
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
#define MAX 210
using namespace std;

struct NODE
{
	int to,cap,next;
}edge[3000];
int apex[MAX],level[MAX];
int ind[MAX],outd[MAX],pre[MAX];
queue<int> mq;
int n,s,t,cou;

void init()
{
	cou=0;
	memset(edge,'\0',sizeof(edge));
	memset(apex,-1,sizeof(apex));
	memset(ind,0,sizeof(ind));
	memset(outd,0,sizeof(outd));
	while(!mq.empty()) mq.pop();
	for(int i=1;i<=n;++i)
		pre[i]=i;
}

int inline find(int x)
{
	while( x != pre[x] )  
		x = pre[x];  
	return x;  
}
void myunion(const int &x,const int &y)
{
	int a=find(x);
	int b=find(y);
	pre[a]=pre[b]=pre[x]=pre[y]=min(a,b);
}
bool check()
{
	for(int i=1;i<=n;++i)
		if(find(i)!=1)
			return false;
	return true;
}

bool BFS()
{
	memset(level,-1,sizeof(level));
	level[s]=0;
	mq.push(s);
	while(!mq.empty())
	{
		int u=mq.front();
		mq.pop();
		int head=apex[u];
		while(head!=-1)
		{
			if(edge[head].cap>0 && level[edge[head].to]==-1)
			{
				level[edge[head].to]=level[u]+1;
				mq.push(edge[head].to);
			}
			head=edge[head].next;
		}
	}
	return level[t]!=-1;
}

int dinic(const int &now,int sum)
{
	int i,a,os;
	if(now==t)
		return sum;
	os=sum;
	int head=apex[now];
	while(head!=-1 && sum)
	{
		i=edge[head].to;
		if(level[i]==level[now]+1 && edge[head].cap>0)
		{
			a = dinic(i,min(sum,edge[head].cap));
			edge[head].cap-=a;
			edge[head^1].cap+=a;
			sum -=a;
		}
		head = edge[head].next;
	}
	return os-sum;
}

void add(const int &u,const int &v,const int &c)
{
	edge[cou].to=v;
	edge[cou].cap=c;
	edge[cou].next=apex[u];
	apex[u] = cou++;

	edge[cou].to=u;
	edge[cou].cap=0;
	edge[cou].next=apex[v];
	apex[v] = cou++;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	scanf("%d",&ncases);
	int m,u,v,d;

	while(ncases--)
	{
		scanf("%d%d",&n,&m);
		s=0;t=n+1;
		int ans=0;
		int flag=1,sum=0;

		init();

		while(m--)
		{
			scanf("%d%d%d",&u,&v,&d);
			if(u==v) continue;
			++ind[v];		//统计出入度
			++outd[u];
			myunion(u,v);
			if(d==0)
				add(u,v,1);		//如果是有向边，直接加上去
		}

		if(!check())		//并查集检查是否连通图
		{
			flag=0;
			goto end;
		}

		for(int i=1;i<=n;++i)
		{
			outd[i]-=ind[i];
			if(outd[i]%2)
			{
				flag=0;
				goto end;
			}
			outd[i]/=2;
			if(outd[i]>0)
			{
				add(0,i,outd[i]);
				sum+=outd[i];
			}
			else
				add(i,t,-outd[i]);
		}
		
		while(BFS())
			ans+=dinic(0,INT_MAX); 
end:		
		if(flag==0 || ans!=sum)
			printf("impossible\n");
		else
			printf("possible\n");
	}

	return 0;
}
