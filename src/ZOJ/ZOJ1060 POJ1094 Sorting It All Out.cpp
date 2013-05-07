// ZOJ1060 POJ1094 Sorting It All Out.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #define DEBUG


#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <queue>
#define MAX 30

using namespace std;

int map[MAX][MAX];
queue<int> mqueue;
int n;

int Floyd() //判断是否有环。  
{  
	int i,k,j;  
	for(i=0; i<n; i++)  
		for(k=0; k<n; k++)  
			for(j=0; j<n; j++)  
				if( map[k][i] && map[i][j] )  
					map[k][j] = 1;  
	for(i=0; i<n; i++)  
		if( map[i][i] == 1 )  
			return 1;  
	return 0;  
}  

int topo(void)
{
	int degree[MAX],used[MAX];
	memset(degree,0,sizeof(degree));
	memset(used,0,sizeof(used));
	while(!mqueue.empty()) mqueue.pop();
	for(int j=0;j<n;++j)
		for(int i=0;i<n;++i)
			if(map[i][j])
				++degree[j]; //save in degree
	for(int i=0;i<n;++i)
	{
		int index=-1;
		for(int j=0;j<n;++j)
		{
			if(degree[j]==0 && !used[j])
			{
				index=j;
			}
		}
		if(index==-1) return 1; //have circle
		if(!mqueue.empty() && !map[mqueue.back()][index])
			return 0; //不能确定
		mqueue.push(index);
		used[index]=1;
		for(int j=0;j<n;++j)
			if(map[index][j])
				--degree[j];
	}
	return 2;	//ok
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int m;
	char str[5];
	while(scanf("%d %d",&n,&m) && (n||m))
	{
		memset(map,0,sizeof(map));
		int flag=0;
		int index=-1;
		for(int i=0;i<m;++i)
		{
			scanf("%s",str);
			map[str[0]-'A'][str[2]-'A']=1;
			if(!flag)
			{
				int temp=Floyd();
				if(temp)
				{
					flag=1;
					index=i;
				}
				else
				{
					flag=topo();
					if(flag)
						index=i;
				}
			}

		}
		if(flag==0)
			printf("Sorted sequence cannot be determined.\n");
		else if(flag==1)
		{
			if(index==-1)
				index=m;
			printf("Inconsistency found after %d relations.\n",index+1);
		}
		else
		{
			if(index==-1)
				index=m;
			printf("Sorted sequence determined after %d relations: ",index+1);
			while(!mqueue.empty())
			{
				printf("%c",mqueue.front()+'A');
				mqueue.pop();
			}
			printf(".\n");
		}			

	}

	return 0;
}
