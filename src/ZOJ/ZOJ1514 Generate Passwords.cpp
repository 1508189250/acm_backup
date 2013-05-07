// ZOJ1514 Generate Passwords.cpp : Defines the entry point for the console application.
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

struct usr
{
	string name,psw;
}user[1010];

int main(void)
{
// 	ifstream cin("data.txt");
	int n;
	string name,str;

	while(cin>>n &&n)
	{
		int sum=0;
		for(int i=0;i<n;++i)
		{
			cin>>name>>str;
			int flag=0;
			for(int j=0;j<str.length();++j)
			{
				if(str.at(j)=='1')
				{
					str.at(j)='@';
					flag=1;
				}
				else if(str.at(j)=='0')
				{
					str.at(j)='%';
					flag=1;
				}
				else if(str.at(j)=='O')
				{
					str.at(j)='o';
					flag=1;
				}
				else if(str.at(j)=='l')
				{
					str.at(j)='L';
					flag=1;
				}
			}
			if(flag)
			{
				user[sum].name=name;
				user[sum].psw=str;
				++sum;
			}
		}
		if(sum)
		{
			cout<<sum<<endl;
			for(int i=0;i<sum;++i)
				cout<<user[i].name<<' '<<user[i].psw<<endl;
		}
		else
			cout<<"No account is modified."<<endl;
		
	}


	return 0;
}
