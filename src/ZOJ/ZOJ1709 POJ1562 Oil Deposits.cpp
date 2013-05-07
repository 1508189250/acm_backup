/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-08-26 18:56
 * Filename : ZOJ1709 POJ1562 Oil Deposits.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ1709 POJ1562 Oil Deposits.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"

#include <iostream>

using namespace std;

int mat[110][110];

int find(int x)
{
	while(x != mat[x/1000][x%1000])
		x=mat[x/1000][x%1000];
	return x;
}

void tree(int a,int b,int i,int j)
{
	int m,n;
	if(mat[i][j]!=-1)
	{
		m=find(a*1000+b);
		n=find(i*1000+j);
		if(m!=n)
			mat[m/1000][m%1000]=n;
	}
}

int main(void)
{
// 	ifstream cin("data.txt");
	char ch;
	int m,n;
	for(int i=0;i<110;++i)
		mat[0][i]=mat[i][0]=-1;

	while(cin>>m>>n&&m&&n)
	{
		int sum=0;
		for(int i=1;i<=m;++i)
			mat[i][n+1]=-1;
		for(int i=1;i<=n;++i)
			mat[m+1][i]=-1;

		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
			{
				cin>>ch;
				if(ch=='*') mat[i][j]=-1;
				else
				{
					mat[i][j]=i*1000+j;
					tree(i,j,i-1,j-1);
					tree(i,j,i-1,j);
					tree(i,j,i-1,j+1);
					tree(i,j,i,j-1);
				}
			}

		for(int i=1;i<=m;++i)
			for (int j=1;j<=n;++j)
				if(mat[i][j] ==(i*1000+j))
					++sum;

		cout<<sum<<endl;
	}
	return 0;
}
