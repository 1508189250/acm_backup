// ZOJ1712 POJ1565 Skew Binary.cpp : Defines the entry point for the console application.
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
	vector<unsigned int> myvec;
	string str;
	myvec.push_back(0);
	for(int i=1;i<=32;++i)
	{
		myvec.push_back((myvec.at(i-1)+1)*2-1);
	}
	while(cin>>str &&str!="0")
	{
		int sum(0);
		int j(1);
		for(int i=str.length()-1;i>=0;++j,--i)
		{
			sum+=(str.at(i)-'0')*myvec.at(j);
		}
		printf("%d\n",sum);
	}


	return 0;
}
