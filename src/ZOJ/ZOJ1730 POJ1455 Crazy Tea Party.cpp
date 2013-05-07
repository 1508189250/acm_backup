// ZOJ1730 POJ1455 Crazy Tea Party.cpp : Defines the entry point for the console application.
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
// 	ifstream cin("3.txt");
	int ncases,n;
	cin>>ncases;

	while(ncases--)
	{
		int a,b;
		cin>>n;
		if(n%2)
			a=n/2+1;
		else
			a=n/2;
		b=n/2;

		int sum=((a-1)*a+(b-1)*b)/2;
		cout<<sum<<endl;
	}


	return 0;
}


