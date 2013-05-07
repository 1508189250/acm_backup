/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-01 19:53
 # Filename: ZOJ1992 POJ1637 HDU1956 Sightseeing tour.cpp
 # Description : 
 ���⣺����һ�����ͼ���еı������еı����򣩣��ʴ�ͼ�Ƿ����ŷ����·�� 

 ��˵˵ŷ����·�ɣ������յ���ͬ������ͼG��ÿ����һ�Σ���ֻ����һ�ε�·����Ϊŷ����·�� 
 ����ͼ�Ĳ�ͬ��Ϊ������ͼŷ����·������ͼŷ����·�ͻ��ͼŷ����·�� 

 �ж�һ��ͼ�Ƿ����ŷ����·�� 
 1.����ͼ��ͼ��ͨ����ͼ�о�Ϊż�ȶ��㡣 
 2.����ͼ��ͼ��ͨ����ͼ�����ж���������ȡ� 
 3.���ͼ�����ͼŷ����·���ж�������������ʵ�ַ����� 

 ���ȶ����е��������㶨��֮�����е�����Ȼ��ͳ��ÿ����ĳ���ȣ������ĳ��������֮��Ϊ�������򲻴���ŷ����·����Ϊ���Ϊ�����Ļ���������������ߣ�������ʹ��ÿ����ĳ������ȡ� 
 ����ÿ����ĳ����֮��Ϊż���ˣ������ż������2,��x�����ÿ������ı���֮������x���ߵķ���Ϳ���ʹ�øõ�������ȡ����ÿ���㶼�ܴﵽ�������ȣ���Ȼ�ʹ���ŷ����·�ˡ� 
 ��������ͱ���˸ı���Щ�ߵķ�������ÿ������������ˣ�����������ģ�͡� 
 ����߲��ܸı䷽�����Բ��������ߡ������ڿ�ʼ��ʱ�����ⶨ�������ߣ��������ķ���ӱߣ�����Ϊ1��Դ�������г�>��ĵ����ߣ�����Ϊ�õ��xֵ��������>���ĵ��������ߣ�����Ϊ�õ��xֵ�� 
 ��ͼ����ˣ�����������������������䣬�����ŷ����·����ô��Щ�߸ı䷽����ܵõ�ŷ����·�أ��鿴�������䣬����������0�ı߾���Ҫ�ı䷽��ıߡ� 
 ԭ������Ϊ�������䣬���Ժ�Դ�������ĵ�һ������x�������룬����Щ�߷�����Щ��ͳ��������ˣ��ͻ����������Ȼ��û�к�Դ�����������Ѿ����������ˣ���Ȼ�����޸ģ�����ŷ����·�����ϡ� 

 ����ʵ�ַ�����
 ���¾��ǣ��Ƚ�����߶��򣬾��Ǳ���1<->3�����Զ����ķ���Ϊ1->3��1�ĳ���++��3�����++���ɡ�
 �����ʱ�������������ߣ��������߼�������������У�����Ϊ1���������Ȼ���ó��ȼ���ȵõ�x�����xΪ�������϶�������ŷ����·�����û�������������������⡣
 ���x����0����һ��s��Դ�㣩����ǰ������Ϊx/2�ıߣ����xС��0����һ���ӵ�ǰ�㵽 t����㣩����Ϊ|x/2|�ıߡ�
 Ȼ������������������������s������==t��������ɣ�sָ���ǽ�ͼ��ʱ������s�ıߵ������ͣ�������ŷ����·��
 �������õݹ��dinic���ģ���ʼ�ò��鼯����ͨ��
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
			++ind[v];		//ͳ�Ƴ����
			++outd[u];
			myunion(u,v);
			if(d==0)
				add(u,v,1);		//���������ߣ�ֱ�Ӽ���ȥ
		}

		if(!check())		//���鼯����Ƿ���ͨͼ
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
