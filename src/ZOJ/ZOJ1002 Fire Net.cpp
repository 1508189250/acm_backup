// ZOJ1002 Fire Net.cpp : Defines the entry point for the console application.
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

int n;
char mat[10][10];

int dfs(int x,int y,int sum)
{
	if (mat[x][y]=='X')
	{
		return 0;
	}
	for(int i=x-1;i>0;--i)
	{
		if(mat[i][y]=='b') return 0;
		else if(mat[i][y]=='X') break;
	}
	for(int i=x+1;i<=n;++i)
	{
		if(mat[i][y]=='b') return 0;
		else if(mat[i][y]=='X') break;
	}
	for(int i=y-1;i>0;--i)
	{
		if(mat[x][i]=='b') return 0;
		else if(mat[x][i]=='X') break;
	}
	for(int i=y+1;i<=n;++i)
	{
		if(mat[x][i]=='b') return 0;
		else if(mat[x][i]=='X') break;
	}

	mat[x][y]='b';
	++sum;

	int temp=sum;

	for(int j=y+1;j<=n;++j)
		temp=max(temp,dfs(x,j,sum));
	for(int i=x+1;i<=n;++i)
		for(int j=1;j<=n;++j)
			temp=max(temp,dfs(i,j,sum));

	mat[x][y]='.';
	--sum;
	return temp;
}

int main(void)
{
// 	ifstream cin("data.txt");
	for(int i=0;i<10;++i)
		mat[0][i]=mat[i][0]='X';
	char ch;

	while(cin>>n && n)
	{
		int sum=0;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				cin>>mat[i][j];

		for (int i=1;i<=n+1;++i)
		{
			mat[n+1][i]=mat[i][n+1]='X';
		}

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				sum=max(sum,dfs(i,j,0));

		cout<<sum<<endl;
	}


	return 0;
}
