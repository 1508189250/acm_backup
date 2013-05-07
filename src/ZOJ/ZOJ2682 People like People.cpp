/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-09-23 20:28
 # Filename: ZOJ2682 People like People.cpp
 # Description : ���޳������в�������ĿҪ��Ľڵ㣬������ȼ������µĽڵ�
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
}*v[MAX],*rv[MAX],node[6*MAX];//v��¼��������rv��¼����ת�ú��
int n,m,ncount;
int in[MAX],out[MAX],visit[MAX];

void init(void)
{
	memset(v,'\0',sizeof(v));
	memset(rv,'\0',sizeof(rv));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	memset(visit,0,sizeof(visit));//visit���ڼ�¼��Щ���޳����Ľڵ�
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
				if(in[i]==0)	//�����������Ϊ0�Ľڵ㣬�������޳���
				{
					NODE *head=v[i];
					while(head)
					{
						--in[head->to];//�ѱ�Ҳ�޳���
						head=head->next;
					}
					visit[i]=1;
					flag=true;
				}
				if(out[i]==0)	//�ҵ����г���Ϊ0�Ľڵ㣬Ҳ�޳���
				{
					NODE *head=rv[i];
					while(head)
					{
						out[head->to]=0;	//����ڵ�ĳ���Ϊ0����ָ�����Ľڵ���Ϊָ����core��Ľڵ㣬��Ҳ�����޳����������Щ�ڵ�ĳ�����Ϊ0������һ���޳�
						head=head->next;
					}
					visit[i]=1;
					flag=true;
				}
			}
	}
}

int dfs(int index,int sum)
//��ȼ���������һ���ڵ㣬ֻҪû�б����ʹ�������ȼ�����ָ��ģ��Լ�ָ�����Ľڵ�
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
