// ZOJ1874 POJ2562 Primary Arithmetic.cpp : Defines the entry point for the console application.
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
	int lhs,rhs;

	while(cin>>lhs>>rhs &&(lhs||rhs))
	{
		int sum=0;
		if(lhs<rhs)
			swap(lhs,rhs);
		while(lhs && rhs)
		{
			int a=lhs%10,b=rhs%10;
			lhs=lhs/10;
			rhs=rhs/10;
			if(a+b>9)
			{
				++sum;
				++rhs;
			}
		}

		if(!sum)
			cout<<"No carry operation."<<endl;
		else if(sum>1)
			cout<<sum<<" carry operations."<<endl;
		else
			cout<<"1 carry operation."<<endl;
	}


	return 0;
}
