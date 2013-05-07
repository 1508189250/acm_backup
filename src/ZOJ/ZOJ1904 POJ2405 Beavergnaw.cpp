// ZOJ1904 POJ2405 Beavergnaw.cpp : Defines the entry point for the console application.
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

#define PI 3.1415927 

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");

	double d,D,V;

	while(cin>>D>>V &&(D||V))
	{
// 		d=pow((21*V/PI - pow(D,3.0))/2,1/3.0);
		d=pow((D*D*D-6*V/PI),1/3.0);
// 		cout<<d<<endl;
		printf("%0.3f\n",d);

	}

	return 0;
}
