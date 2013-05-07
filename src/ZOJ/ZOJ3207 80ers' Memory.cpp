// ZOJ3207 80ers' Memory.cpp : Defines the entry point for the console application.
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
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	set<string> myset;
	string str;
	int N,K;
	int num;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>str;
		myset.insert(str);
	}
	cin>>K;
	for(int i=0;i<K;++i)
	{
		int sum(0);
		cin>>num;
		for(int j=0;j<num;++j)
		{
			cin>>str;
			if(myset.find(str) != myset.end())
				++sum;
		}
		printf("%d\n",sum);
	}

	return 0;
}

