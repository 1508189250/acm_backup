// HDU1040 As Easy As A+B.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>
#include <assert.h>
#include <ctype.h>

using namespace std;

// void quick_sort(int *A,int beg,int end)
// {
// 	if(beg>=end) return;
// 	int p,r,temp;
// 	r=beg;
// 	p=beg-1;
// 	temp=A[end];
// 	for(;r<end;++r)
// 	{
// 		if(A[r]>A[end]);
// 		else
// 			swap(A[++p],A[r]);
// 	}
// 	swap(A[++p],A[end]);
// 	quick_sort(A,beg,p-1);
// 	quick_sort(A,p+1,end);
// }

void heap_insert(int x,int *A,int total)
{
	++total;
	A[total]=x;
	while(total>1 && A[total]>A[total/2])
	{
			swap(A[total],A[total/2]);
			total=total/2;
	}
}

void heap_update(int *A,int total)
{
	if(total==1) return;
	int flag=1;
	for(int i=1;flag;)
	{
		int temp=i;
		flag=0;
		if(i*2<=total && A[i]<A[i*2])
		{
			flag=1;
			temp=i*2;
		}
		if(i*2+1<=total && A[temp]<A[i*2+1])
		{
			flag=1;
			temp=i*2+1;
		}
		swap(A[temp],A[i]);
		i=temp;
	}
}

void heap_sort(int *A,int total)
{
	for(int i=total;i>1;--i)
	{
		swap(A[1],A[i]);
		heap_update(A,i-1);
	}
}

int main(void)
{
// 	ifstream cin("data.txt");
	int num[1010];
	int ncases;
	int n;

	cin>>ncases;
	while(ncases--)
	{
		int temp;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>temp;
			heap_insert(temp,num,i);
		}

		heap_sort(num,n);
					
// 		quick_sort(num,0,n-1);
		int flag=1;
		for(int i=1;i<=n;++i)
		{
			if(flag)
				flag=0;
			else
				cout<<' ';
			cout<<num[i];
		}
		cout<<endl;
	}

	return 0;
}
