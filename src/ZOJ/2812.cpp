/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-06-02 20:10
 * Filename : 2812.cpp
 * Description : 
 * *****************************************************************************/
// 2812.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	//fstream cin("data.txt");
	//char ch[256];
	string str;
	while(getline(cin,str))
	{
		if(str =="#") break;
		
		int sum(0);
		for (size_t i = 0; i<str.length();++i)
		{
			if (str.at(i) != ' ')
			{
				sum += (i+1) * (str.at(i) - 'A'+1);
			}
		}

		cout << sum <<endl;

	}
	return 0;
}

