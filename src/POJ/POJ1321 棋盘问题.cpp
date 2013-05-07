// POJ1321 ∆Â≈ÃŒ Ã‚.cpp : Defines the entry point for the console application.
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

int n,sum;
char mat[10][10];

void dfs(int x,int y,int remain)
{
	if(mat[x][y]=='.') return;

	for(int i=x-1;i>0;--i)
	{
		if(mat[i][y]=='q') return;
	}

	mat[x][y]='q';
	--remain;
	if(!remain)
	{
		++sum;
	}
	else
	{
		for(int i=x+1;i<=n ;++i)
			for(int j=1;j<=n;++j)
				dfs(i,j,remain);
	}
	mat[x][y]='#';
	++remain;
}

int main(void)
{
// 	ifstream cin("data.txt");
	for(int i=0;i<10;++i)
		mat[i][0]=mat[0][i]='.';
	int k;

	while(cin>>n>>k && n>0 &&k >0)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				cin>>mat[i][j];
		for(int i=1;i<=n+1;++i)
			mat[i][n+1]=mat[n+1][i]='.';

		sum=0;
		for(int i=1;i<=n-k+1;++i)
			for(int j=1;j<=n;++j)
				dfs(i,j,k);
		cout<<sum<<endl;
	}



	return 0;
}
