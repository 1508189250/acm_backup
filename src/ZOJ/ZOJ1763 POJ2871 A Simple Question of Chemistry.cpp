// ZOJ1763 POJ2871 A Simple Question of Chemistry.cpp : Defines the entry point for the console application.
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
	double current,previous;

	cin>>previous;

	while(cin>>current && current !=999.0)
	{
		double temp = (current - previous);
		printf("%4.2f\n",temp);
		previous = current;
	}

	cout<<"End of Output"<<endl;

	return 0;
}
