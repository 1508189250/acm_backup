// POJ3620 Avoid The Lakes.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;

int mat[110][110];

int dfs(int x,int y)
{
	if(!mat[x][y]) return 0;
	mat[x][y]=0;
	int sum=1;
	sum+=dfs(x-1,y)+dfs(x,y-1)+dfs(x,y+1)+dfs(x+1,y);
	return sum;
}

int main(void)
{
// 	ifstream cin("data.txt");
	int m,n,k;

	for(int i=0;i<110;++i)
		mat[i][0]=mat[0][i]=0;

	while(cin>>n>>m>>k)
	{
		int x,y;
		int sum=0;

		for(int i=1;i<=n+1;++i)
			for(int j=1;j<=m+1;++j)
				mat[i][j]=0;

		for(int i=0;i<k;++i)
		{
			cin>>x>>y;
			mat[x][y]=1;
		}

		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(mat[i][j])
					sum=max(sum,dfs(i,j));

		cout<<sum<<endl;
	}

	return 0;
}
