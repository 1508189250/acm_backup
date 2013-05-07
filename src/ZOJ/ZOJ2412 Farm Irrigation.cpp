// ZOJ2412 Farm Irrigation.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>
#include <assert.h>
#include <ctype.h>

using namespace std;

int mat[55][55];
int visit[55][55];
int mark[55][55];

int find(int a,int b)
{
	while(a*10+b != visit[a][b])
	{
		int x=visit[a][b]/10,y=visit[a][b]%10;
		a=x;
		b=y;
	}
	return visit[a][b];
}

int up2down(int lhs,int rhs)
{
	return lhs&(rhs>>1)&4;
}

int left2right(int lhs,int rhs)
{
	return lhs&(rhs>>1)&1;
}

void trees(int x,int y,int a,int b)
{
	if(!visit[x][y]) return;
	int m,n;
	n=find(a,b);
	m=find(x,y);
	if(m!=n)
	{
		visit[x][y]=n;
		mark[x][y]=1;
	}
	if(up2down(mat[x-1][y],mat[x][y]) &&!mark[x-1][y])
		trees(x-1,y,x,y);
	if(up2down(mat[x][y],mat[x+1][y]) &&!mark[x+1][y])
		trees(x+1,y,x,y);
	if(left2right(mat[x][y],mat[x][y+1]) &&!mark[x][y+1])
		trees(x,y+1,x,y);
	if(left2right(mat[x][y-1],mat[x][y]) &&!mark[x][y-1])
		trees(x,y-1,x,y);
}


int main(void)
{
// 	ifstream cin("data.txt");
	int cell[]={10,9,6,5,12,3,11,14,7,13,15};
	int m,n;

	for(int i=0;i<55;++i)
	{
		mat[0][i]=mat[i][0]=0;
		visit[0][i]=visit[i][0]=0;
		mark[0][i]=mark[i][0]=1;
	}

	while(cin>>m>>n && m>-1&&n>-1)
	{
		int sum=0;
		char ch;
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
			{
				cin>>ch;
				mat[i][j]=cell[ch-'A'];
				visit[i][j]=i*10+j;
				mark[i][j]=0;
			}

		for(int i=1;i<=m+1;++i)
			mark[i][n+1]=mat[i][n+1]=visit[i][n+1]=0;
		for(int j=1;j<=n+1;++j)
			mark[m+1][j]=mat[m+1][j]=visit[m+1][j]=0;

		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
				if(visit[i][j] ==i*10+j)
				{
					++sum;
					mark[i][j]=1;
					trees(i,j,i,j);
				}
		cout<<sum<<endl;
	}

	return 0;
}
