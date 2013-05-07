// ZOJ3355 Football Gambling I.cpp : Defines the entry point for the console application.
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
	int ncases;
	double a,b,c;
	double abet,bbet,cbet;
	double maxodd;
	cin>>ncases;
	while(ncases--)
	{
		cin>>a>>b>>c;
		maxodd = max(a,b);
		maxodd = max(maxodd,c);
		abet=maxodd/a;
		bbet=maxodd/b;
		cbet=maxodd/c;
		double temp(abet+bbet+cbet);
		if(abet*a>temp && bbet*b>temp && cbet*c>temp)
			printf("Aha\n");
		else
			printf("No way\n");
	}


	return 0;
}
