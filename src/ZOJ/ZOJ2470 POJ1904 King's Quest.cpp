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
int STACK[kMAX],top=0;          //Tarjan �㷨�е�ջ 
bool InStack[kMAX];             //����Ƿ���ջ�� 
int DFN[kMAX];                  //��������������ʴ��� 
int Low[kMAX];                  //��׷�ݵ�����ջ�е��������
int ComponentNumber=0;       //����ͼǿ��ͨ�������� 
int Index=0;                 //������ 
vector <int> Edge[kMAX];        //�ڽӱ��ʾ 
int InComponent[kMAX];			//��¼ÿ�����ڵڼ���ǿ��ͨ������
int ComponentDegree[kMAX];    	 //��¼ÿ��ǿ��ͨ�����Ķ�
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
		else if (InStack[j]) //���ָ��Ľڵ�j����ջ�У�����j����i��ջ����j�е�i��ͨ·��ͬʱ����iָ��j����i��j���ɻ�·
			Low[i]=min(Low[i],DFN[j]); 	//���ָ��Ľڵ�����ջ�У���ָ��Ľڵ���δ����ǿ��ͨ����
		//���ǰ�������ж��������Ǵ���Ļ�����i��j����ͬһ����ͨ������
	} 
	if (DFN[i]==Low[i]) //��ͨ�����������ջ�ĵ�
	{ 
		ComponentNumber++; 
		do 
		{ 
			j=STACK[top--]; 
			InStack[j]=false; 
			InComponent[j]=ComponentNumber;	//��ÿһ����ͨ�����ϵĽڵ�Ⱦɫ
		} 
		while (j!=i); 
	} 
}

int output[kMAX];
void solve(int N)     //N�Ǵ�ͼ�е�ĸ�����ע����0-indexed�� 
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

