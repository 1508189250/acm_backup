/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-03 21:13
 # Filename: URAL1069 Prufer Code.cpp
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
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 7510
using namespace std;

struct NODE
{
	int to;
	NODE *next;
}*node[MAX],edge[2*MAX];

int n_count,n;
int order[MAX],degree[MAX];
int result[MAX];
void init()
{
	n_count=0;
	n=0;
	memset(node,'\0',sizeof(node));
	memset(degree,0,sizeof(degree));
}

void add(const int &lhs,const int &rhs)
{
	edge[n_count].to=rhs;
	edge[n_count].next=node[lhs];
	node[lhs]=&edge[n_count++];
}

void output(const int &x)
{
	printf("%d:",x);
	NODE *pos=node[x];
	int n_cou=0;
	while(pos)
	{
		result[n_cou++]=pos->to;
		pos=pos->next;
	}
	sort(result,result+n_cou);
	for(int i=0;i<n_cou;++i)
		printf(" %d",result[i]);
	printf("\n");
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int temp;

	init();
	while(~scanf("%d",&temp))
	{
		order[n++]=temp;
		++degree[temp];
	}
	for(int i=0;i<n;++i)
	{
		int x=order[i];
		int flag=0;
		for(int j=1;j<=n+1;++j)
			if(degree[j]==0)
			{
				flag=j;
				break;
			}
		--degree[x];
		--degree[flag];
		add(x,flag);
		add(flag,x);
	}
	for(int i=1;i<=n+1;++i)
		output(i);

  return 0;
}
