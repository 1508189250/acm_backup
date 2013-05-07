/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-12 16:35
 * Filename : ZOJ1094_POJ2246.cpp
 * Description : ZOJ1094 POJ2246	Matrix Chain Multiplication
 * *****************************************************************************/
// ZOJ1094_POJ2246.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int main(void)
{
	//ifstream cin("data.txt");
	pair<int,int> A,B,TEMP,alap2pair[26];
	char alaph[128]={0};
	char ch;
	int a,b;
	string str;
	stack<pair<int,int> > mystack;
	int n;
	cin>>n;
	int i,j,k;
	for(i=0;i<n;++i)
	{
		cin>>ch>>a>>b;
		alaph[ch]=i;
		alap2pair[i]=make_pair(a,b);
	}

	while(cin>>str)
	{
		int length(str.length());
		int sum(0);
		while(!mystack.empty()) mystack.pop();
		for(i=0;i<length;++i)
		{
			if(str.at(i) ==')')
			{				
				B = mystack.top();
				mystack.pop();
				A = mystack.top();
				mystack.pop();
				if (A.second != B.first)
				{
					sum =-1;
					break;
				}
				sum += A.first * A.second * B.second;
				TEMP = make_pair(A.first,B.second);
				mystack.pop();
				mystack.push(TEMP);
			}
			else
			{
				if (str.at(i) == '(')
				{
					mystack.push(make_pair(0,0));
				}
				else
					mystack.push(alap2pair[alaph[str.at(i)]]);
			}
		}
		if (sum ==-1)
		{
			cout<<"error"<<endl;
		} 
		else
		{
			cout<<sum<<endl;
		}
	}


	return 0;
}

