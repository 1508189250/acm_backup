/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-05 21:26
 * Filename : ZOJ2201.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ2201.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
	//ifstream cin("data.txt");

	int N;
	int temp1,temp2;
	cin>>N;
	while(N>0)
	{
		cin>>temp1>>temp2;
		cout<< ((temp2 > temp1)?"NO BRAINS":"MMM BRAINS")<<endl;
		--N;
	}
	return 0;
}

