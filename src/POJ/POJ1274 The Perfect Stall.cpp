/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-24 19:24
 # Filename: POJ1274 The Perfect Stall.cpp
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
#define MAX 410
using namespace std;

int map[MAX][MAX];		//�ڽӾ���
int used[MAX];				//��ÿ��������·�������ڼ�¼��ǰ�ڵ��Ƿ�������·����
int link[MAX];				//�����ڵ��Ӧ��ƥ����
int m,n;

bool find(const int &x)		//��x��ʼ�Ƿ�������·
{
	int i;
	for(i=n+1;i<=m+n;++i)
	{
		if(map[x][i] && !used[i])		//��x��i�б�������i���ڵ�ǰ������·��
		{
			used[i]=1;
			if(!link[i] || find(link[i]))	//��iû��ƥ������i��ƥ���ʼ������·
			{
				link[i]=x;
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int num,to;
	while(~scanf("%d%d",&n,&m))
	{
		memset(map,0,sizeof(map));
		memset(link,0,sizeof(link));
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&num);
			for(int j=0;j<num;++j)
			{
				scanf("%d",&to);
				map[i][n+to]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n+m;++i)
		{
			memset(used,0,sizeof(used));
			if(find(i)) ++ans;
		}
		printf("%d\n",ans);
	}

	return 0;
}
