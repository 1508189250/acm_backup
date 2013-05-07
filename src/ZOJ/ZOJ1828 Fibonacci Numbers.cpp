// ZOJ1828 Fibonacci Numbers.cpp : Defines the entry point for the console application.
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
#include <limits>
#include <assert.h>
#include <ctype.h>

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	vector<string> myvec;
	string str="1";
	myvec.push_back(str);
	myvec.push_back(str);

	while(myvec.back().length()<1020)
	{
		vector<string>::reverse_iterator iter=myvec.rbegin();
		string rhs=*iter,lhs=*(++iter);
		for(int i=0;i<lhs.length();++i)
			rhs.at(i)=lhs.at(i)+rhs.at(i)-'0';

		for(int i=0;i<rhs.length()-1;++i)
		{
			if(rhs.at(i)>'9')
			{
				rhs.at(i)-=10;
				++rhs.at(i+1);
			}
		}

		if(*(rhs.end()-1)>'9')
		{
			rhs.at(rhs.length()-1)-=10;
			rhs+=str;
		}
		myvec.push_back(rhs);
	}

	int n;
	while(cin>>n)
	{
		str=myvec.at(n-1);

		for(int i=str.length()-1;i>=0;--i)
			printf("%c",str.at(i));
		printf("\n");
	}



	return 0;
}
