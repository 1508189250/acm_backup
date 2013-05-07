// ZOJ3168 Sort ZOJ7.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const char &lhs,const char &rhs)
{
	int a,b;
	if(lhs=='Z')
		a=1;
	else if(lhs=='O')
		a=2;
	else if(lhs=='J')
		a=3;
	else if(lhs=='7')
		a=4;
	else
		a=5;

	if(rhs=='Z')
		b=1;
	else if(rhs=='O')
		b=2;
	else if(rhs=='J')
		b=3;
	else if(rhs=='7')
		b=4;
	else
		b=5;

		return a<b;
}

int main(void)
{
	string str;

	while(getline(cin,str))
	{
		stable_sort(str.begin(),str.end(),cmp);
		//ÎÈ¶¨ÅÅÐò
		cout<<str<<endl;
	}


	return 0;
}
