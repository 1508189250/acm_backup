/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-24 19:23
 # Filename: ZOJ2470 POJ1904 King's Quest.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <vector>
using namespace std;

const int kMAX=10010;
const double kEPS=10E-6;
int STACK[kMAX],top=0;          //Tarjan 算法中的栈 
bool InStack[kMAX];             //检查是否在栈中 
int DFN[kMAX];                  //深度优先搜索访问次序 
int Low[kMAX];                  //能追溯到的在栈中的最早次序
int ComponentNumber=0;       //有向图强连通分量个数 
int Index=0;                 //索引号 
vector <int> Edge[kMAX];        //邻接表表示 
int InComponent[kMAX];			//记录每个点在第几号强连通分量里
int ComponentDegree[kMAX];    	 //记录每个强连通分量的度
void Tarjan(int i) 
{ 
	int j; 
	DFN[i]=Low[i]=Index++; 
	InStack[i]=true; 
	STACK[++top]=i; 
	for (size_t e=0;e<Edge[i].size();e++) 
	{ 
		j=Edge[i][e]; 
		if (DFN[j]==-1) 
		{ 
			Tarjan(j); 
			Low[i]=min(Low[i],Low[j]); 
		} 
		else if (InStack[j]) //如果指向的节点j仍在栈中，由于j先于i入栈，则j有到i的通路，同时由于i指向j，则i与j构成回路
			Low[i]=min(Low[i],DFN[j]); 	//如果指向的节点扔在栈中，则指向的节点仍未编入强连通分量
		//如果前面两个判断条件都是错误的话，则i和j不在同一个连通分量中
	} 
	if (DFN[i]==Low[i]) //连通分量中最早进栈的点
	{ 
		ComponentNumber++; 
		do 
		{ 
			j=STACK[top--]; 
			InStack[j]=false; 
			InComponent[j]=ComponentNumber;	//给每一个连通分量上的节点染色
		} 
		while (j!=i); 
	} 
}

int output[kMAX];
void solve(int N)     //N是此图中点的个数，注意是0-indexed！ 
{ 
	memset(STACK,-1,sizeof(STACK)); 
	memset(InStack,0,sizeof(InStack)); 
	memset(DFN,-1,sizeof(DFN)); 
	memset(Low,-1,sizeof(Low)); 

	for(int i=1;i<=N;i++) 
		if(DFN[i]==-1) 
			Tarjan(i);

	int n=N/2;
	for(int i=1;i<=n;++i)
	{
		int x=InComponent[i];
		size_t cnt=0;
		for(size_t j=0;j<Edge[i].size();++j)
			if(InComponent[Edge[i][j]]==x)
				output[cnt++]=Edge[i][j]-n;

		sort(output,output+cnt);
		printf("%d",cnt);
		for(size_t j=0;j<cnt;++j)
			printf(" %d",output[j]);
		printf("\n");

	}
// 	printf("\n");
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,tmp,u,v;

  while(~scanf("%d",&n) && n)
  {
	  for(int i=0;i<=2*n;++i)
		  Edge[i].clear();
	  for(int i=1;i<=n;++i)
	  {
		  scanf("%d",&tmp);
		  while(tmp--)
		  {
			  scanf("%d",&v);
			  Edge[i].push_back(v+n);
		  }
	  }
	  for(int i=1;i<=n;++i)
	  {
		  scanf("%d",&u);
		  Edge[u+n].push_back(i);
	  }
	  solve(n+n);
  }

  return 0;
}

