/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-02 20:21
 # Filename: URAL1056 Computer Net.cpp
 # Description : 
 ******************************************************************************/
#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#define MAX 10010
using namespace std;

struct NODE
{
  int to;
  NODE *next;
}*node[MAX],elem[2*MAX];

int n_count;
int depth[MAX],len[MAX];

void init()
{
	memset(node,'\0',sizeof(node));
	memset(depth,-1,sizeof(depth));
	memset(len,0,sizeof(len));
	n_count=0;
}

void add(const int &from,const int &to)
{
	elem[n_count].to=to;
	elem[n_count].next=node[from];
	node[from] = &elem[n_count++];
}

int dfs(const int &now)
{
	if(!node[now])
	{
		depth[now]=0;
		len[now]=0;
		return 0;
	}

	NODE *pos=node[now];
	int temp=0;
	int a=0,b=0;
	while(pos)
	{
		int tmp=dfs(pos->to)+1;
		if(tmp>a && tmp>b)
		{
			b=a;
			a=tmp;
		}
		else if(tmp<=a && tmp>b)
		{
			b=tmp;
		}
		temp=max(tmp,temp);
		pos=pos->next;
	}
	depth[now]=temp;
	len[now]=a+b;
	return depth[now];
}

int result[2];
void dfs(const int &now,const int &max_len)
{
	if(depth[now]==max_len/2 || (max_len-depth[now])==max_len/2)
	{
		result[n_count++]=now;
	}
	NODE *pos=node[now];
	while(pos)
	{
		dfs(pos->to,max_len);
		pos=pos->next;
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n;

	while(~scanf("%d",&n))
	{
		int from,to;
		init();
		for(int i=2;i<=n;++i)
		{
			scanf("%d",&from);
			add(from,i);
		}
		dfs(1);
		int max_len=-1,center_1;
		for(int i=1;i<=n;++i)
			if(max_len<len[i])
			{
				max_len=len[i];
				center_1=i;
			}
		n_count=0;
		dfs(center_1,max_len);
		sort(result,result+n_count);
		if(n_count==1)
			printf("%d\n",result[0]);
		else
			printf("%d %d\n",result[0],result[1]);
	}


  return 0;
}
