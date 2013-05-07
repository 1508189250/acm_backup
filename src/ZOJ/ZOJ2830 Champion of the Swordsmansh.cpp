// ZOJ2830 Champion of the Swordsmansh.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
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
// 	ifstream cin("data.txt");
	long long n;
	while(cin>>n && n )
	{
		cout<< ((n%2)?((n-1)/2):(n/2))<<endl;
	}


	return 0;
}

