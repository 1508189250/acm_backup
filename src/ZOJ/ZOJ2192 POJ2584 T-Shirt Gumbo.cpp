// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 110
using namespace std;

int m_size[128];
int map[MAX][MAX],mat[MAX],used[MAX];
int n,cou;

void init()
{
	memset(map,0,sizeof(map));
	memset(mat,-1,sizeof(mat));
	memset(used,0,sizeof(used));
	cou=0;
}
bool inline find(const int &x)
{
	for(int i=0;i<cou;++i)
	{
		if(used[i]==0 && map[x][i])
		{
			used[i]=1;
			if(mat[i]==-1 || find(mat[i]))
			{
				mat[i]=x;
				return true;
			}
		}
	}
	return false;
}

int func()
{
	int ans=0;
	for(int i=0;i<n;++i)
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
	int contestants[30][2];
	char str[15];
	int a,b,num;
	m_size['S']=0;m_size['M']=1;m_size['L']=2;m_size['X']=3;m_size['T']=4;

	while(scanf("%s",str) && strcmp(str,"ENDOFINPUT")!=0)
	{
		scanf("%d",&n);
		init();
		for(int i=0;i<n;++i)
		{
			scanf("%s",str);
			contestants[i][0]=min(m_size[str[0]],m_size[str[1]]);
			contestants[i][1]=max(m_size[str[0]],m_size[str[1]]);
		}
		for(int i=0;i<5;++i)
		{
			scanf("%d",&num);
			for(int j=0;j<n;++j)
				if(contestants[j][0]<=i && contestants[j][1]>=i)
					for(int k=cou;k<cou+num;++k)
						map[j][k]=1;
			cou+=num;
		}
		int ans=func();
		if(ans==n)
			printf("T-shirts rock!\n");
		else
			printf("I'd rather not wear a shirt anyway...\n");
		scanf("%s",str);
	}

	return 0;
}
