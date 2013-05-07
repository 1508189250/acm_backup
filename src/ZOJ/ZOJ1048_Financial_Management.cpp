// ZOJ1048_Financial_Management.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
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
	//ifstream cin("data.txt");
	double temp,sum;
	sum=0.0;
	for(int i=0;i<12;++i)
	{
		cin>>temp;
		sum +=temp;
	}

	sum *=100;
	sum /=12;
	
	cout<< '$'<<(int(sum))/100.0<<endl;


	return 0;
}
