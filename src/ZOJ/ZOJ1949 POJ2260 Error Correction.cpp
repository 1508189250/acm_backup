// ZOJ1949 POJ2260 Error Correction.cpp : Defines the entry point for the console application.
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

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int n;
	int matrix[110][110];
	int rowindex,columnindex,rowcount,columncount;
	int sum;

	while(cin>>n && n)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				cin>>matrix[i][j];
		rowcount=columncount=0;
		for(int i=1;i<=n;++i)
		{
			sum=0;
			for(int j=1;j<=n;++j)
			{
				sum+=matrix[i][j];
			}
			if(sum%2)
			{
				++rowcount;
				rowindex=i;
			}
		}
		for(int j=1;j<=n;++j)
		{
			sum=0;
			for(int i=1;i<=n;++i)
			{
				sum+=matrix[i][j];
			}
			if(sum%2)
			{
				++columncount;
				columnindex=j;
			}
		}
		if(!rowcount && !columncount)
		{
			cout<<"OK"<<endl;
		}
		else if(rowcount==1 && columncount==1)
		{
			cout<<"Change bit ("<<rowindex<<','<<columnindex<<')'<<endl;
		}
		else
			cout<<"Corrupt"<<endl;
	}


	return 0;
}
