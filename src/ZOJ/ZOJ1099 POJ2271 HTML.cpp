// ZOJ1099 POJ2271 HTML.cpp : Defines the entry point for the console application.
//

//  #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string> //加入 #include <string>,重载Extraction运算符
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
//  	ifstream cin("data.txt");
// 	ofstream cout("result.txt");
	string str,result;
	string hr,br;
	hr = "--------------------------------------------------------------------------------";
	hr +='\n';
	br = '\n';
	while(cin>>str)
	{
		if(str=="<br>")
		{
			if (result.empty())
			{
				cout<<endl;
			} 
			else
			{
				cout<<result.substr(0,result.length()-1)<<endl;
				result.clear();
			}
		}
		else if(str=="<hr>")
		{
			if (result.empty())
			{
				cout<<hr;
			} 
			else
			{
				cout<<result.substr(0,result.length()-1)<<endl<<hr;
				result.clear();
			}
		}
		else if(result.length() + str.length() < 80)
		{
			result += str;
			result += ' ';
		}
		else
		{
			cout<<result.substr(0,result.length()-1)<<endl;
			result = str;
			result += ' ';
		}
	}
	cout<<result.substr(0,result.length()-1)<<endl;


	return 0;
}
