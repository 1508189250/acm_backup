#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define	MAX 20
using namespace std;

int board[MAX][MAX];

bool check(const int &x,const int &y)
{
	int color=board[x][y];
	int i,j;
	bool flag=false;

	if(x>=5 && y<=15)
	{
		flag=true;
		for(i=x,j=y;i>=x-4 && flag;--i,++j)
			flag = flag && (board[i][j]==color);
	}
	if(flag) 
		return true;

	if(x<=15)
	{
		flag=true;
		for(i=x;i<=x+4 && flag;++i)
			flag = flag && (board[i][y]==color);
	}
	if(flag) 
		return true;

	if(x<=15 && y<=15)
	{
		flag=true;
		for(i=x,j=y;i<=x+4 && flag;++i,++j)
			flag = flag && (board[i][j]==color);
	}
	if(flag) 
		return true;

	if(y<=15)
	{
		flag=true;
		for(j=y;j<=y+4 && flag;++j)
			flag = flag && (board[x][j]==color);
	}
	if(flag) 
		return true;

	return false;
}

int main(void)
{
#ifdef DEBUG  
	freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
	freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int ncase;
	scanf("%d",&ncase);

	while(ncase--)
	{
		memset(board,0,sizeof(board));
		for(int i=1;i<MAX;++i)
			for(int j=1;j<MAX;++j)
				scanf("%d",&board[i][j]);

		int x,y;
		bool ans=false;
		for(int i=1;i<MAX && !ans;++i)
			for(int j=1;j<MAX && !ans;++j)
				if(board[j][i] && check(j,i))
				{
					x=j;
					y=i;
					ans=true;
				}

		if(ans)
			printf("%d\n%d %d\n\n",board[x][y],x,y);
		else
			printf("0\n\n");
	}

	return 0;
}
