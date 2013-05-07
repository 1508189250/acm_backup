// ZOJ1494 Climbing Worm.cpp : Defines the entry point for the console application.
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
	int n,u,d;

	while(cin>>n>>u>>d && n)
	{
		int temp;
		temp = int(((n-u)/((u-d)*1.0)+0.99999))*2+1;
		cout<<temp<<endl;
	}


	return 0;
}
