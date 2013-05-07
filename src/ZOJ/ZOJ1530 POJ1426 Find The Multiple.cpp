/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-19 14:29
 * Filename : ZOJ1530 POJ1426 Find The Multiple.cpp
 * Description : http://poj.org/problem?id=1426
				http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1530
 * *****************************************************************************/
// ZOJ1530 POJ1426 Find The Multiple.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"




// #include <fstream>
#include <stdio.h>
#include <iostream>
// #include <string.h>
#include <string>
// #include <vector>
// #include <stack>
#include <queue>
// #include <map>
// #include <math.h>
// #include <algorithm>
// #include <numeric>
// #include <functional>
// #include <memory.h>

using namespace std;

int main(void)
{
//  	ifstream cin("data.txt");
	int n;
	int mod;
	queue< pair<string,int> > myqueue;
	pair<string,int> mypair;

	while(scanf("%d",&n) && n)
	{
		if(! (1%n))
		{
			cout<<1<<endl;
			continue;
		}
		while( ! myqueue.empty()) 
		{
			myqueue.pop();
		}

		myqueue.push(make_pair("1",1));

		while(1)
		{

			mypair = myqueue.front();
			myqueue.pop();
			string str(mypair.first);
			int temp(mypair.second);
			
			mod=temp*10 % n;
			string str0(str+'0');
			if(!mod)
			{
				cout<<str0<<endl;
				break;
			}
			else
				myqueue.push(make_pair(str0,mod));

			mod=(temp*10+1)%n;
			string str1(str+'1');
			if(!mod)
			{
				cout<<str1<<endl;
				break;
			}
			else
				myqueue.push(make_pair(str1,mod));

		}

	}


	return 0;
}
