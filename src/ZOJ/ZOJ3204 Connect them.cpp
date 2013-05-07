// ZOJ3204 Connect them.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define N 110

int n,e;
int pre[N];

struct c
{ 
	int x,y,len;
}pc[N*N],put[N];
typedef struct c NODE;

int find(int x)
{
	while(x!=pre[x])
		x=pre[x];
	return x;
}

int qcmp1(const void *a,const void *b)  
{  
	NODE aa = *(NODE*)a;  
	NODE bb = *(NODE*)b;  
	if( aa.len != bb.len ) return aa.len>bb.len;  
	else if( aa.x != bb.x ) return aa.x-bb.x;  
	else return aa.y-bb.y;  
}  
int qcmp2(const void *a,const void *b)  
{  
	NODE aa = *(NODE*)a;  
	NODE bb = *(NODE*)b;  
	if( aa.x != bb.x ) return aa.x-bb.x;  
	else return aa.y-bb.y;  
} 

bool cmp1(const NODE &lhs,const NODE &rhs)
{
	if(lhs.len != rhs.len)return lhs.len<rhs.len;
	else if(lhs.x != rhs.x)return lhs.x<rhs.x;
	else return lhs.y<rhs.y;
}

bool cmp2(const NODE &lhs,const NODE &rhs)
{
	if(lhs.x != rhs.x)return lhs.x<rhs.x;
	else return lhs.y<rhs.y;
}

void input()
{
	cin>>n;
	e=0;
	int len;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			cin>>len;
			if(j<=i) 
				continue;
			if(len ==0) 
				continue;
			pc[e].x=i;
			pc[e].y=j;
			pc[e].len=len;
			e++;
		}
}

void kruskal()
{
	vector<NODE> result;
	int sum=0,a,b;
	for(int i=1;i<=n;++i)
		pre[i]=i;

	sort(pc,pc+e,cmp1);
// 	qsort(pc,e,sizeof(NODE),qcmp1);

	for(int i=0;i<e;++i)
	{
		a=find(pc[i].x);
		b=find(pc[i].y);
		if(a!=b)
		{
			pre[b]=a;
			result.push_back(pc[i]);
			put[sum]=pc[i];
			++sum;
		}
	}


	if (sum !=n-1)
	{
		cout<<"-1"<<endl;
	}
	else
	{	
// 		qsort(put,sum,sizeof(NODE),qcmp2);
// 		sort(put,put+sum,cmp2);
		sort(result.begin(),result.end(),cmp2);
		for(int i=0;i<sum;++i)
			{
				if (i!=0)
				{
					printf(" ");
				}
				printf("%d %d",result.at(i).x,result.at(i).y);
			}
		cout<<endl;
	}
}




int main(void)
{
	int ncase;

	cin>>ncase;

	while(ncase--)
	{
		input();
		kruskal();
	}


	return 0;
}
