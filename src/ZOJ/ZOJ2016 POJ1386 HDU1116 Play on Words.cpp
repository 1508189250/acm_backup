/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-08 19:53
 # Filename: ZOJ2016 POJ1386 HDU1116 Play on Words.cpp
 # Description : 
 *欧拉回路，所有点连通，并且所有点的入度等于出度。 
 *欧拉通路。从原点S出发，经过所有点，从终点t出去。 
 *本题用并查集方法确定所有的点是否连通
 *所有点除起点终点外的度都是偶数，且出度等于入度
 *起点的出度比入度大1 
 *终点的入度比出度大1 
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
#define MAX 30
using namespace std;
int outD[MAX],inD[MAX],pre[MAX];
int find(int x)
{
	if(pre[x]==-1)
		pre[x]=x;
	return x==pre[x]?x:find(pre[x]);
}
void myUnion(const int &x,const int &y)
{
	int a=find(x);
	int b=find(y);
	pre[a]=pre[b]=pre[x]=pre[y]=min(a,b);
}
int check()
{
	int ind=0;
	while(pre[ind]==-1)
		++ind;
	int tmp=pre[ind];
	for(int i=ind+1;i<26;++i)
		if(pre[i]!=-1 && find(i)!=tmp)
			return 0;
	return 1;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases,n;
	char str[1010];
	scanf("%d",&ncases);
	while(ncases--)
	{
		memset(outD,0,sizeof(outD));
		memset(inD,0,sizeof(inD));
		for(int i=0;i<MAX;++i)
			pre[i]=-1;
		scanf("%d",&n);
		getchar();
		while(n--)
		{
			scanf("%s",str);
			int len=strlen(str);
			myUnion(str[0]-'a',str[len-1]-'a');//并查集
// 			++inD[str[0]-'a'];
// 			++outD[str[len-1]-'a'];
			++outD[str[0]-'a'];
			++inD[str[len-1]-'a'];

		}
		int ans=check();
		if(!ans)
		{
			printf("The door cannot be opened.\n");
			continue;
		}
		int sum=0;
		int temp[MAX];
		memset(temp,0,sizeof(temp));
		for(int i=0;i<26;++i)
			if(outD[i]!=inD[i])
				temp[sum++]=i;
		if (sum==0)
		{
			printf("Ordering is possible.\n");	//所有点的出度等于入度，欧拉回路
			continue;
		}
		if(sum!=2)
		{
			printf("The door cannot be opened.\n");		//除了起点和终点的出入度不等以外，别的点的出入度都必须相等，否则就不是欧拉路径
			continue;
		}
		if((outD[temp[0]]-inD[temp[0]]==1 && inD[temp[1]]-outD[temp[1]]==1) || (outD[temp[1]]-inD[temp[1]]==1 && inD[temp[0]]-outD[temp[0]]==1)  )//判断出入度是否符合要求
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
	}

	return 0;
}
