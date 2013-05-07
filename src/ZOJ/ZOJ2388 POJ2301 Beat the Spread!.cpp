// ZOJ2388 POJ2301 Beat the Spread!.cpp : Defines the entry point for the console application.
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
	int ncases,s,d;
	cin>>ncases;
	while(ncases)
	{
		cin>>s>>d;
		if(s<d) cout<<"impossible"<<endl;
		else if (s%2 != d%2)
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			int a=(s+d)/2,b=(s-d)/2;
			if (a>b)
			{
				cout<<a<<' '<<b<<endl;
			} 
			else
			{

				cout<<b<<' '<<a<<endl;
			}
		}
		--ncases;
	}


	return 0;
}
