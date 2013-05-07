// ZOJ2186 POJ2578 Keep on Truckin'.cpp : Defines the entry point for the console application.
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
	int n,result=0,flag=0;
	for(int i=0;i<3;++i)
	{
		cin>>n;
		if(n<=168)
		{
			if(!flag)
				result=n;
			++flag;
		}

	}

	if(flag==3)
		cout<<"NO CRASH"<<endl;
	else
		cout<<"CRASH "<<result<<endl;


	return 0;
}
