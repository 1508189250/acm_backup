// ZOJ1047 POJ1111 Image Perimeters.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <assert.h>

using namespace std;

int mat[30][30];
int mark[30][30];

int find(int a,int b)
{
	if (a==1&&b==1)
	{
		assert(a==1);
	}
	if(mat[a][b]==-1) return -1;
	while(a*100+b!=mat[a][b])
	{
		int temp=mat[a][b];
		a=temp/100;
		b=temp%100;
	}
	return mat[a][b];
}

void tree(int x,int y,int a,int b)
{
	if(mat[x][y]==-1 || mark[x][y]) return;
	int m,n;
	m=find(x,y);
	n=find(a,b);
	if(m!=n)
	{
		mat[m/100][m%100]=n;
	}

	mark[x][y]=1;

	tree(x-1,y-1,x,y);
	tree(x-1,y,x,y);
	tree(x-1,y+1,x,y);
	tree(x,y-1,x,y);
	tree(x,y+1,x,y);
	tree(x+1,y-1,x,y);
	tree(x+1,y,x,y);
	tree(x+1,y+1,x,y);

}

int main(void)
{
// 	ifstream cin("data.txt");
	int r,c,x,y;
	char ch;
	for(int i=0;i<30;++i)
		mat[0][i]=mat[i][0]=-1;

	while(cin>>r>>c>>x>>y&&r&&c)
	{
		int sum=0;

		for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
			{
				cin>>ch;
				if(ch=='X')
					mat[i][j]=i*100+j;
				else
					mat[i][j]=-1;
				mark[i][j]=0;
			}

			for(int i=1;i<=r+1;++i)
				mat[i][c+1]=-1;
			for(int i=1;i<=c+1;++i)
				mat[r+1][i]=-1;

			tree(x,y,x,y);
			int temp=find(x,y);

			for(int i=0;i<=r+1;++i)
				for(int j=0;j<=c+1;++j)
				{
					if(mat[i][j]==-1)
					{

						if(i>0&&mat[i-1][j]!=-1 && temp==find(i-1,j))
							++sum;
						if(j>0&&mat[i][j-1]!=-1 && temp==find(i,j-1))
							++sum;
						if(j<=c&&mat[i][j+1]!=-1 && temp==find(i,j+1))
							++sum;
						if(i<=r&&mat[i+1][j]!=-1 && temp==find(i+1,j))
							++sum;
					}
				}

				cout<<sum<<endl;
	}


	return 0;
}


