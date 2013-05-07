// ZOJ1884 POJ2538 WERTYU.cpp : Defines the entry point for the console application.
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
	string str="'1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	string text;
// 	cout<<str<<endl;

	while(getline(cin,text))
	{
		for(int i=0;i<text.length();++i)
		{
			char ch=text.at(i);
			if(ch=='`'||ch=='Q'||ch=='A'||ch=='Z'||ch==' ')
				cout<<ch;
			else if (ch=='\'')
			{
				cout<<';';
			}
			else
			{
				int pos=str.find(ch);
				cout<<str.at(pos-1);
			}
		}
		cout<<endl;
	}


	return 0;
}

