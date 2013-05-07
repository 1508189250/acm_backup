/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-09-12 10:10
 # Filename: ZOJ3170 7 Levels of Binary Search Tree.cpp
 # Description : 
 ******************************************************************************/
// ZOJ3170 7 Levels of Binary Search Tree.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int num[256];
vector<int> result;

struct node 
{
	int data;
	struct node *left,*right;
}*Head;
void insert(int elem,struct node * & p)
{
	if( p == NULL )
	{
		p = (struct node*)malloc(sizeof(struct node));
		p->data = elem;
		p->left = p->right = NULL;
		return ;
	}
	if( elem > p->data )
		insert(elem,p->right);
	else 
		insert(elem,p->left);
}

void postorder(struct node *p)
{
	if(p==NULL) return;
	else
	{
		postorder(p->left);
		postorder(p->right);
		result.push_back(p->data);
	}
}


int main(void)
{
	int n,l;
	int a,b,c;
	queue<int> start,index,end;

	while(scanf("%d",&n)!=EOF)
	{
		memset(num,0,sizeof(num));
		result.clear();
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);
		sort(num,num+n);
		scanf("%d",&l);
		if (n==1)
		{
			printf("%d\n",num[0]);
			continue;
		}
		scanf("%d %d",&a,&c);
		start.push(0);
		index.push(a);
		end.push(a+c);

		while(!start.empty())
		{
			a=start.front();
			b=index.front();
			c=end.front();
			start.pop(),index.pop(),end.pop();

			insert(num[b],Head);
			if(b-a>0)
			{
				int temp1=0,temp2=0;
				if(b-a>1)
					scanf("%d %d",&temp1,&temp2);
				start.push(a);index.push(a+temp1);end.push(a+temp1+temp2);
			}
			if(c-b>0)
			{
				int temp1=0,temp2=0;
				if(c-b>1)
					scanf("%d %d",&temp1,&temp2);
				start.push(b+1);index.push(b+1+temp1);end.push(b+1+temp1+temp2);
			}
		}
		postorder(Head);
		printf("%d",result[0]);
		for(int i=1;i<n;++i)
			printf(" %d",result[i]);
		Head=NULL;
		printf("\n");
	}
	return 0;
}
