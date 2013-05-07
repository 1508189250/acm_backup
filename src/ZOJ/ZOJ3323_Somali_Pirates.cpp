// ZOJ3323_Somali_Pirates.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
//#include <ctype.h>

using namespace std;

int main(void)
{
	//ifstream cin("data.txt");
	char ch;
	int ncases;
	cin>>ncases;
	getchar();
	while(ncases)
	{
		--ncases;
		while(ch=getchar())
		{

			if (ch=='\n')
			{
				break;
			}
			if(ch>='0'&&ch<='9')
			{
				;
			}
			else
			{
				cout<<ch;
			}
			
		}
		cout<<endl;
	}


	return 0;
}
