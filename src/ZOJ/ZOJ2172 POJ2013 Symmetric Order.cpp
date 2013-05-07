// ZOJ2172 POJ2013 Symmetric Order.cpp : Defines the entry point for the console application.
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
	int set=1,n;
	int i;
	vector<string> myvec;
	string str;
	while(cin>>n &&n)
	{
		printf("SET %d\n",set++);
		myvec.clear();
		for(i=0;i<n;++i)
		{
			cin>>str;
			myvec.push_back(str);
		}
		for(i=0;i<n;i=i+2)
			cout<<myvec.at(i)<<endl;
			
		if(n%2)
			i=myvec.size()-2;
		else
			i=myvec.size()-1;
		for(;i>=0;i=i-2)
			cout<<myvec.at(i)<<endl;;
	}


	return 0;
}
