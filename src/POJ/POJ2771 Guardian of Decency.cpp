// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 510
using namespace std;

struct NODE
{
	int height;
	char sex,style[110],sport[110];
}person[MAX];

int map[MAX][MAX];
int mat[MAX],used[MAX];
int cou,n;

bool find(const int &x)
{
	for(int i=0;i<n;++i)
		if(map[x][i] && !used[i])
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
	for(int i=0;i<n;++i)
	{
		memset(used,0,sizeof(used));
		if(find(i))
			++ans;
	}
	return ans;
}

bool love(const int &x, const int &y)
{
	NODE *pTemp1 = &person[x];
	NODE *pTemp2 = &person[y];
	if(abs(pTemp2->height-pTemp1->height)>40)
		return false;
	if(pTemp2->sex == pTemp1->sex)
		return false;
	if(strcmp(pTemp2->style,pTemp1->style))
		return false;
	if(strcmp(pTemp2->sport,pTemp1->sport)==0)
		return false;
	return true;
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	
	int ncases;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		for(int i=0;i<n;++i)
		{
			scanf("%d %c %s %s",&person[i].height,&person[i].sex,person[i].style,person[i].sport);
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(love(i,j))
				{
					map[i][j]=1;
				}
		int ans=hungary();
		printf("%d\n",n-ans/2);
	}

	return 0;
}
