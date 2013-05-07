// ZOJ1058.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


int main(int argc, char* argv[])
{
	//ifstream cin("data.txt");
	int N,M,nFrom,nTo,flat=0;
	double matrix[5][5];
	double input,cash;
	vector<int> vecInt;
	cin>>N;
	while(N>0)
	{
		if (flat)
		{
			cout<<endl;
		}
		flat=1;

		for (int i=0 ;i<5;++i)
		{
			for (int j = 0;j<5;++j)
			{
				cin>>input;
				matrix[i][j]=input;
			}
		}

		cin>>M;

		while(M)
		{
			vecInt.clear();
			vecInt.push_back(1);
			while(M)
			{

				cin>>nFrom;
				vecInt.push_back(nFrom);
				--M;
			}
			vecInt.push_back(1);

			cin>>cash;

			nFrom=1;

			for (vector<int>::iterator iter = vecInt.begin()+1;iter != vecInt.end();++iter)
			{
				nTo = *iter;
				cash = cash*matrix[nFrom-1][nTo-1];
				cash = int(cash*100+0.5);
				cash = cash/100;
				nFrom = nTo;
			}

// 			cout.precision(2);
// 			cout<<cash<<endl;
			printf("%.2lf\n",cash);
			cin>>M;
		}



		--N;
	}
	return 0;
}

