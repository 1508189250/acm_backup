// ZOJ1797 HDU1019 Least Common Multiple.cpp : Defines the entry point for the console application.
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

int gcd(int x,int y)
{
	if(x<y) swap(x,y);

	if(y==0) return x;
	else
	{
		return gcd(y,x%y);
	}
}

int main(void)
{
// 	ifstream cin("data.txt");
	int ncases,n;
	int x,y;
	cin>>ncases;

	while(ncases--)
	{
		cin>>n;
		y=1;
		for(int i=0;i<n;++i)
		{
			cin>>x;
			y=x/gcd(x,y)*y;
		}

		cout<<y<<endl;

	}



	return 0;
}
