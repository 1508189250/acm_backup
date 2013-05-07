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
	int to,id;		//id代表这个节点在edge中的位置
	bool used;		//用于记录这个节点是否在深度优先搜索中用过
	string str;
	node *next;
}*adj[26],edge[2000],nTemp;

int cou,n,start;
int pre[26],ancient[2000],indegree[26],outdegree[26];	//pre用于并查集检索所有的路径是否连通，ancient用于记录每个单词出现顺序，indegree用于记录入度，outdegree用于记录出度

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
	start = x;		//start用于记录起点，如果是欧拉回路的话，所有起点都可以，所以直接记录第一个了
	int tep = pre[x];
	for(;x<26;++x)
	{
		if(pre[x]!=-1)
			if(tep!=find(x))
				return false;	//不在同一棵树上，不行
	}

	int sum=0;
	int temp[26];
	memset(temp,0,sizeof(temp));
	for(x=0;x<26;++x)
		if(outdegree[x]!=indegree[x])
			temp[sum++]=x;

	if(sum==0)
		return true;	//欧拉回路

	if(sum ==2)		//欧拉通路
		if(outdegree[temp[0]]-indegree[temp[0]]==1 && indegree[temp[1]]-outdegree[temp[1]]==1)
		{
			start = temp[1];	//起点的入度比出度大1
			return true;
		}
		else if(outdegree[temp[1]]-indegree[temp[1]]==1 && indegree[temp[0]]-outdegree[temp[0]]==1)
		{
			start = temp[0];
			return true;
		}

	return false;
}

bool dfs(const int &s,const int &num)	//深度优先搜索，s是当前节点，num是当前深度
{
	int to,id;
	bool used;
	if(num==n)		//找到，返回
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
		ancient[num]=id;		//记录这条边
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
	pre[a]=pre[b]=pre[from]=pre[to]=min(a,b);		//并查集


	//以下三个判断，用于给每个节点按照词典序排序
	node *head=adj[from];
	if(!head || head&&head->str > str)		//string可以直接用<，>判断，返回结果是词典序结果。判断第一个节点是否存在，或者第一个节点存在且比本输入大
	{
		edge[cou].next=head;
		adj[from] = &edge[cou++];
	}
	else if(head && !head->next && head->str <str)		//第一个节点存在，第二个节点不存在，且第一个节点比本输入小
	{
		edge[cou].next = head->next;
		adj[from]->next = &edge[cou++];
	}
	else
	{
		while(head->next && head->next->str < str)		//找到一个位置，使得此位置的节点比本输入小，节点的下一个节点要么不存在，要么比本输入大
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
