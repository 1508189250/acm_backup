/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-21 19:38
 # Filename: ZOJ1919 POJ2337 Catenyms.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct node
{
	int to,id;		//id��������ڵ���edge�е�λ��
	bool used;		//���ڼ�¼����ڵ��Ƿ�����������������ù�
	string str;
	node *next;
}*adj[26],edge[2000],nTemp;

int cou,n,start;
int pre[26],ancient[2000],indegree[26],outdegree[26];	//pre���ڲ��鼯�������е�·���Ƿ���ͨ��ancient���ڼ�¼ÿ�����ʳ���˳��indegree���ڼ�¼��ȣ�outdegree���ڼ�¼����

void init()
{
	memset(adj,'\0',sizeof(adj));
	memset(indegree,0,sizeof(indegree));
	memset(outdegree,0,sizeof(outdegree));
	for(int i=0;i<26;++i)
		pre[i]=-1;
	for(int i=0;i<n;++i)
		ancient[i]=-1;
	cou=0;
}
int find(const int &x)
{
	if(pre[x]==-1) pre[x]=x;
	return x==pre[x]?x:find(pre[x]);
}

bool check()
{
	int x=0;
	while(pre[x]==-1)
		++x;
	start = x;		//start���ڼ�¼��㣬�����ŷ����·�Ļ���������㶼���ԣ�����ֱ�Ӽ�¼��һ����
	int tep = pre[x];
	for(;x<26;++x)
	{
		if(pre[x]!=-1)
			if(tep!=find(x))
				return false;	//����ͬһ�����ϣ�����
	}

	int sum=0;
	int temp[26];
	memset(temp,0,sizeof(temp));
	for(x=0;x<26;++x)
		if(outdegree[x]!=indegree[x])
			temp[sum++]=x;

	if(sum==0)
		return true;	//ŷ����·

	if(sum ==2)		//ŷ��ͨ·
		if(outdegree[temp[0]]-indegree[temp[0]]==1 && indegree[temp[1]]-outdegree[temp[1]]==1)
		{
			start = temp[1];	//������ȱȳ��ȴ�1
			return true;
		}
		else if(outdegree[temp[1]]-indegree[temp[1]]==1 && indegree[temp[0]]-outdegree[temp[0]]==1)
		{
			start = temp[0];
			return true;
		}

	return false;
}

bool dfs(const int &s,const int &num)	//�������������s�ǵ�ǰ�ڵ㣬num�ǵ�ǰ���
{
	int to,id;
	bool used;
	if(num==n)		//�ҵ�������
		return true;
	node *head=adj[s];

	while(head)
	{
		if(head->used)
		{
			head=head->next;
			continue;
		}
		to=head->to;
		id=head->id;
		ancient[num]=id;		//��¼������
		head->used=true;	
		if(dfs(to,num+1))
			return true;
		head->used=false;
		head=head->next;
	}
	return false;
}

void input()
{
	cin>>edge[cou].str;
	string &str= edge[cou].str;
	int to = *str.rbegin()-'a';
	int from = *str.begin()-'a';
	edge[cou].to= to;
	edge[cou].id=cou;
	edge[cou].used=false;

	++indegree[from];
	++outdegree[to];

	int a=find(from);
	int b=find(to);
	pre[a]=pre[b]=pre[from]=pre[to]=min(a,b);		//���鼯


	//���������жϣ����ڸ�ÿ���ڵ㰴�մʵ�������
	node *head=adj[from];
	if(!head || head&&head->str > str)		//string����ֱ����<��>�жϣ����ؽ���Ǵʵ��������жϵ�һ���ڵ��Ƿ���ڣ����ߵ�һ���ڵ�����ұȱ������
	{
		edge[cou].next=head;
		adj[from] = &edge[cou++];
	}
	else if(head && !head->next && head->str <str)		//��һ���ڵ���ڣ��ڶ����ڵ㲻���ڣ��ҵ�һ���ڵ�ȱ�����С
	{
		edge[cou].next = head->next;
		adj[from]->next = &edge[cou++];
	}
	else
	{
		while(head->next && head->next->str < str)		//�ҵ�һ��λ�ã�ʹ�ô�λ�õĽڵ�ȱ�����С���ڵ����һ���ڵ�Ҫô�����ڣ�Ҫô�ȱ������
			head=head->next;
		edge[cou].next = head->next;
		head->next = &edge[cou++];
	}
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d",&n);
		init();
		for(int i=0;i<n;++i)
			input();
		if(!check())
		{
			cout<<"***"<<endl;
			continue;
		}
		dfs(start,0);
		cout<<edge[ancient[0]].str;
		for(int i=1;i<n;++i)
		{
			cout<<'.'<<edge[ancient[i]].str;
		}
		cout<<endl;
	}

	return 0;
}
