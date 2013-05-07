// ZOJ1879 POJ2575 Jolly Jumpers.cpp : Defines the entry point for the console application.
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
	vector<int> vTemp;
	int n;
	while(cin>>n)
	{
		int temp;
		if(n==1)
		{
			cout<<"Jolly"<<endl;
			cin>>temp;
			continue;
		}
		vTemp.clear();
		int check[3010];
		memset(check,0,sizeof(check));
		for(int i=0;i<n;++i)
		{
			cin>>temp;
			vTemp.push_back(temp);
		}

		for(int i=1;i<n;++i)
		{
			check[abs(vTemp.at(i)-vTemp.at(i-1))]=1;
		}
	
		int flag=0;
		for(int i=1;i<n;++i)
		{
			if(!check[i])
				flag=1;
		}
		if(flag)
			cout<<"Not jolly"<<endl;
		else
			cout<<"Jolly"<<endl;
	}


		
	return 0;
}
