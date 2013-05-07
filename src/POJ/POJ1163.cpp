// POJ1163.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ifstream cin("data.txt");
	int matrix[100][100]={0};
	int lines;
	cin>>lines;
	for(int i=0;i<lines;++i)
	{
		for(int j=0;j<=i;++j)
			cin>>matrix[i][j];
	}
	for(int i=lines-2;i>=0;i--)
		for(int j=0;j<=i;++j)
		{
			matrix[i][j] += max(matrix[i+1][j],matrix[i+1][j+1]);
		}

	cout<<matrix[0][0]<<endl;

	return 0;
}
