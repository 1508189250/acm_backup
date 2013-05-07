/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-06-03 14:48
 * Filename : 1383.cpp
 * Description : zju ACM 1383号题
 * *****************************************************************************/
// 1383.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int times;
	vector<int> IntVec;
	
	//fstream cin("data.txt");
	cin>>times;
	for(int i=0;i<times;++i)
	{
		int trans;
		cin>>trans;
		while(trans)
		{
			//int tmp(trans%2);
			IntVec.push_back(trans%2);
			trans  = trans /2;
		}
		//reverse(IntVec.begin(),IntVec.end());

		int p(1);
		for(size_t j=0;j<IntVec.size();++j)
		{
			if(IntVec.at(j) == 1)
				if (p)
				{
					cout<<j;
					p=0;
				}
				else
					cout<<' ' <<j;

		}
		cout<<endl;
		IntVec.clear();
		//IntVec.resize(0);

	}

	return 0;
}

