/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-06-03 00:09
 * Filename : 1240.cpp
 * Description : 
 * *****************************************************************************/
// 1240.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <iostream>
#include <string>

using namespace std;
int main(int argc, char* argv[])
{
	//ifstream cin("data.txt");
	int times;
	string str;
	cin>>times;
	for(int j=1; j <= times; ++j)
	{
		cin>>str;
		for(size_t i=0;i<str.length();++i)
		{
			if(str.at(i) == 'Z') str.at(i) = 'A';
			else ++ (str.at(i));
		}

		cout<<"String #"<<j<<endl;
		cout<<str<<endl<<endl;
	}
	return 0;
}

