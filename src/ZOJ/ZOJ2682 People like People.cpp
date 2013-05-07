/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-09-23 20:28
 # Filename: ZOJ2682 People like People.cpp
 # Description : 先剔除掉所有不符合题目要求的节点，接着深度检索余下的节点
 ******************************************************************************/
// ZOJ2682 People like People.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#define MAX 10010

using namespace std;

struct NODE
{
	int to;
	NODE *next;
}*v[MAX],*rv[MAX],node[6*MAX];//v记录的是正序，rv记录的是转置后的
int n,m,ncount;
int in[MAX],out[MAX],visit[MAX];

void init(void)
{
	memset(v,'\0',sizeof(v));
	memset(rv,'\0',sizeof(rv));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	memset(visit,0,sizeof(visit));//visit用于记录那些被剔除掉的节点
	ncount=0;
}
void dele(void)
{
	bool flag=true;
	while(flag)
	{
		flag=false;
		for(int i=1;i<=n;++i)
			if(!visit[i])
			{
				if(in[i]==0)	//对于所有入度为0的节点，把他们剔除掉
				{
					NODE *head=v[i];
					while(head)
					{
						--in[head->to];//把边也剔除掉
						head=head->next;
					}
					visit[i]=1;
					flag=true;
				}
				if(out[i]==0)	//找到所有出度为0的节点，也剔除掉
				{
					NODE *head=rv[i];
					while(head)
					{
						out[head->to]=0;	//如果节点的出度为0，则指向它的节点因为指向了core外的节点，故也必须剔除，这里把这些节点的出度设为0留到下一次剔除
						head=head->next;
					}
					visit[i]=1;
					flag=true;
				}
			}
	}
}

int dfs(int index,int sum)
//深度检索，对于一个节点，只要没有被访问过，就深度检索它指向的，以及指向它的节点
{
	if(visit[index]) return sum;
	++sum;
	visit[index]=1;
	NODE *head=v[index];
	while(head)
	{
		sum=dfs(head->to,sum);
		head=head->next;
	}
	head=rv[index];
	while(head)
	{
		sum=dfs(head->to,sum);
		head=head->next;
	}
	return sum;
}
int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases,start,end,temp;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d %d",&n,&m);
		init();
		for(int i=0;i<m;++i)
		{
			scanf("%d %d",&start,&temp);
			for(int j=0;j<temp;++j)
			{
				scanf("%d",&end);
				node[ncount].to=end;
				node[ncount].next=v[start];
				v[start]=&node[ncount++];
				node[ncount].to=start;
				node[ncount].next=rv[end];
				rv[end]=&node[ncount++];
				++in[end];
				++out[start];
			}
		}
		dele();
		int maxsum=0,temp;
		for(int i=1;i<=n;++i)
		{
			temp=dfs(i,0);
			if(temp>maxsum)
				maxsum=temp;
		}
		printf("%d\n",maxsum);
	}
	return 0;
}
