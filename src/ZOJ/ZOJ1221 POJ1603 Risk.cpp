// ZOJ1221 POJ1603 Risk.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

#define MAX	25
#define INF 100000

using namespace std;

int map[MAX][MAX]; 

int main(void)
{
// 	ifstream cin("data.txt");
	int ncase=0;
	int n;

	while(cin>>n)
	{
		int a,b;

		for(int i=0;i<MAX;++i)
		{
			for(int j=0;j<MAX;++j)
				map[i][j]=map[j][i]=INF;
			map[i][i]=0;
		}


		for(int i=0;i<n;++i)
		{
			cin>>b;
			map[1][b]=map[b][1]=1;
		}

		for(int i=2;i<20;++i)
		{
			cin>>n;
			for(int j=0;j<n;++j)
			{
				cin>>b;
				map[i][b]=map[b][i]=1;
			}
		}

		for(int k=1;k<=20;++k)
			for(int i=1;i<=20;++i)
				for(int j=1;j<=20;++j)
					if(map[i][j]>map[i][k]+map[k][j])
						map[i][j]=map[i][k]+map[k][j];

		cout<<"Test Set #"<<++ncase<<endl;

		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b;
			cout<<a<<" to "<<b<<": "<<map[a][b]<<endl;
		}

		cout<<endl;

	}



	return 0;
}


