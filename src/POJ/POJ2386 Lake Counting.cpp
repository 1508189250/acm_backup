// POJ2386 Lake Counting.cpp : Defines the entry point for the console application.
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

char mat[110][110];

void dfs(int x,int y)
{
	if( mat[x][y] == '.') return;
	mat[x][y]='.';
	dfs(x-1,y-1);
	dfs(x-1,y);
	dfs(x-1,y+1);
	dfs(x,y-1);
	dfs(x,y+1);
	dfs(x+1,y-1);
	dfs(x+1,y);
	dfs(x+1,y+1);
}

int main(void)
{
// 	ifstream cin("data.txt");
	
	for(int i=0;i<110;++i)
		mat[0][i]=mat[i][0]='.';
	int n,m;
	char ch;
	int sum=0;

	cin>>n>>m;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>mat[i][j];

	for(int i=1;i<=n+1;++i)
		mat[i][m+1]='.';
	for(int i=1;i<=m+1;++i)
		mat[n+1][i]='.';

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(mat[i][j]=='W')
			{
				dfs(i,j);
				++sum;
			}

	cout<<sum<<endl;
	


	return 0;
}
