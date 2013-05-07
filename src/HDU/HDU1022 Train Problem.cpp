/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-08-13 13:47
 # Filename: HDU1022 Train Problem.cpp
 # Description : 
 ******************************************************************************/
// HDU1022 Train Problem.cpp : Defines the entry point for the console application.
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
	int n;
	string strin,strout;
	vector<string> order;
	stack<char> stop;
	int visit[128];

	while(cin>>n)
	{
		while(!stop.empty()) stop.pop();
		memset(visit,0,sizeof(visit));
		int i,j;
		int flag(0);
		order.clear();
		cin>>strin>>strout;

		for(i=0,j=0;i<strout.length();)
		{
			if(visit[strout.at(i)]==1 && stop.top() == strout.at(i))
			{
				order.push_back("out");
				stop.pop();
				flag=0;
				++i;
			}
			else if(!visit[strout.at(i)]&& j<strin.length())
			{
				order.push_back("in");
				stop.push(strin.at(j));
				visit[strin.at(j)]=1;
				flag=0;
				++j;
			}
			else if(flag)
			{
				break;
			}
			else if(!flag)
			{
				flag=1;
			}
		}
		
		if(order.size() == 2*n)
		{
			cout<<"Yes."<<endl;
			for(i=0;i<2*n;++i)
				cout<<order.at(i)<<endl;
			cout<<"FINISH"<<endl;
		}
		else
			cout<<"No."<<endl
				<<"FINISH"<<endl;

	}


	return 0;
}
