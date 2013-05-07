// ZOJ1582 Careless Tony.cpp : Defines the entry point for the console application.
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
	string stra,strb;
	int n,t;
	
	cin>>n;
	while(n--)
	{
		cin>>t;
		int i;
		getchar();
		getline(cin,stra);
		getline(cin,strb);
		for(i=0;i<stra.length() && i<strb.length();++i)
			if(stra.at(i)!=strb.at(i)) break;

		if(i==stra.length() || i==strb.length())
			cout<<abs((int)(strb.length()-stra.length()))*t<<endl;
		else
			cout<<(stra.length()+strb.length()-2*i)*t<<endl;
	}


	return 0;
}
