// ZOJ2060 Fibonacci Again.cpp : Defines the entry point for the console application.
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
	int myarry[1000000];
	myarry[0]=7%3;
	myarry[1]=11%3;
	for(int i=2;i<1000000;++i)
		myarry[i]=(myarry[i-1]+myarry[i-2])%3;

	int n;

	while(cin>>n)
	{
		if(myarry[n])
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}


	return 0;
}
