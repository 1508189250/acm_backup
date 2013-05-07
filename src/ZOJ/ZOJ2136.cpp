// ZOJ2136.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int N,M,num,result,max;
	vector<int> vecInt;
	vector<int> vecOpt;
	//ifstream cin("data.txt");
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>M;
		vecInt.clear();
		vecOpt.clear();
		cin>>num;
		vecInt.push_back(num);
		vecOpt.push_back(1);
		result=vecOpt.at(0);

		for(int j=1;j<M;++j)
		{
			cin>>num;
			vecInt.push_back(num);
			vecOpt.push_back(1);
			max=1;
			for(int k=j-1;k>-1;--k)
			{
				if(vecInt.at(k)<num && max<=vecOpt.at(k))
				{
					max=vecOpt.at(j)=vecOpt.at(k)+1;
				}
			}
			if(result<vecOpt.at(j)) result=vecOpt.at(j);
		}

		if (i==0)
		{
			cout<<result<<endl;
		} 
		else
		{
			cout<<endl<<result<<endl;
		}
	}
	//cout << "Hello world!" << endl;
	return 0;
}
