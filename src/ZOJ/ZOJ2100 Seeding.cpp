// ZOJ2100 Seeding.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>

char mat[7][7];
int n,m,sum;

using namespace std;

int dfs(int x,int y)
{
	int temp=0;
	mat[x][y]='S';
	++sum;
	if(x+1<n &&mat[x+1][y]=='.')
		temp=max(temp,dfs(x+1,y));
	if(x-1>=0 &&mat[x-1][y]=='.')
		temp=max(temp,dfs(x-1,y));
	if(y+1<m &&mat[x][y+1]=='.')
		temp=max(temp,dfs(x,y+1));
	if(y-1>=0 &&mat[x][y-1]=='.')
		temp=max(temp,dfs(x,y-1));

	temp=max(temp,sum);
	--sum;
	mat[x][y]='.';
	return temp;
}



int main(void)
{
// 	ifstream cin("data.txt");

	while(cin>>n>>m&&m&&n)
	{
		sum=0;

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				cin>>mat[i][j];
				if(mat[i][j]=='S')
					++sum;
			}

		if(mat[0][0]=='S')
		{
			cout<<"NO"<<endl;
			continue;
		}

		sum=dfs(0,0);
		if(sum==n*m)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}

	return 0;
}
