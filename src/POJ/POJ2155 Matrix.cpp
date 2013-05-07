/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-05 21:04
 # Filename: POJ2155 Matrix.cpp
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
#include <algorithm>
#define MAX 1010
#define lowbit(x) (x&(-x))
using namespace std;

int c[MAX][MAX];
int n;

int getsum(int x,int y)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			sum+=c[i][j];
	return sum;
}

void updata(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			++c[i][j];
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases,x1,y1,x2,y2;
	char ch;
	scanf("%d",&ncases);
	int flag=0;

	while(ncases--)
	{
		if(flag)
			printf("\n");
		else
			flag=1;

		memset(c,0,sizeof(c));
		int t;
		scanf("%d%d",&n,&t);
		while(t--)
		{
			getchar();
			scanf("%c",&ch);
			if(ch=='C')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				updata(x1,y1);
				updata(x2+1,y1);
				updata(x1,y2+1);
				updata(x2+1,y2+1);
			}
			else
			{
				scanf("%d%d",&x1,&y1);
				printf("%d\n",getsum(x1,y1)%2);
			}
		}
	}

	return 0;
}
