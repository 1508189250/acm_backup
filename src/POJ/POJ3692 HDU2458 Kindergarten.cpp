/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-10-28 08:47
 # Filename: POJ3692 HDU2458 Kindergarten.cpp
 # Description : 
	������Ҫ��ͼ�е������ȫ��ͼ������ţ��ж���ĸ���������ԭͼ�Ĳ�ͼ��һ������ͼ���������ȫ���ȼ����䲹ͼ������������Ԫ�صĸ��������ǿ��Ը��ݶ���ͼ��������������������������ͨͼ�����������һ��NP���⡣

	��������ͼ����������Ԫ�ظ���=������-����ͼ���ƥ����

	�����ȫ����ͼ�������ȫ��ͼ�Ķ��������

	��������ͼ�������������㶼�������Ķ��㼯�ϡ�
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
#define MAX 450
using namespace std;

int map[MAX][MAX];
int used[MAX],mat[MAX],g,b,n,m;

bool find(const int &x)
{
	for(int i=1;i<=b;++i)
		if(used[i]==0 && !map[x][i])		//��������ͼ�����������map[x][i]Ҫ����0
		{
			used[i]=1;
			if(mat[i]==0 || find(mat[i]))
			{
				mat[i]=x;
				return true;
			}
		}
	return false;
}

int hungary()
{
	int ans=0;
	memset(mat,0,sizeof(mat));
	for(int i=1;i<=g;++i)
	{
		memset(used,0,sizeof(used));
		if(find(i))
			++ans;
	}
	return ans;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int u,v;
	int ncases=1;
	while(scanf("%d%d%d",&g,&b,&m) && (g||b||m))
	{
		memset(map,0,sizeof(map));
		n=g+b;
		while(m--)
		{
			scanf("%d%d",&u,&v);
			map[u][v]=1;
		}
		int ans=hungary();
		printf("Case %d: %d\n",ncases++,n-ans);

	}

	return 0;
}
