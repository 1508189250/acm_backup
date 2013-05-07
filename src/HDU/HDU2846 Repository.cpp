/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-23 19:29
 # Filename: HDU2846 Repository.cpp
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
#define ALAMAX 26
#define MAX 500010
using namespace std;
struct NODE
{
	NODE *next[ALAMAX];
	int count,ind;
}node[MAX],*root;

int ncou,ind;

void add(const char *str)
{
	if(root==NULL)
	{
		root = &node[ncou++];
		for(int i=0;i<ALAMAX;++i)
			root->next[i]=NULL;
		root->count=0;
    root->ind=-1;
	}
	int i=0;
	NODE *head=root;
	while(str[i])
	{
		int ch=str[i]-'a';
		if(head->next[ch]==NULL)
		{
			head->next[ch] = &node[ncou++];
			for(int i=0;i<ALAMAX;++i)
				head->next[ch]->next[i]=NULL;
			head->next[ch]->count=0;
      head->next[ch]->ind=-1;
		}

		head = head->next[ch];
    if(head->ind !=ind)
    {
		  ++ (head->count);
      head->ind=ind;
    }
		++i;
	}
}

int search(const char *str)
{
	int i=0;
	NODE *head=root;
	while(str[i])
	{
		int ch=str[i]-'a';
		if(head->next[ch]==NULL)
			return 0;
		++i;
		head = head->next[ch];
	}
	return head->count;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n,q;
	char str[30];
	scanf("%d",&n);
	getchar();
	ncou=0;
  root=NULL;
  memset(node,0,sizeof(node));
	for(ind=0;ind<n;++ind)
	{
		scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;++i)
			add(str+i);
	}
	scanf("%d",&q);
	getchar();
	while(q--)
	{
		scanf("%s",str);
		int ans=search(str);
		printf("%d\n",ans);
	}

  return 0;
}
