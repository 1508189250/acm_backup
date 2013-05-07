/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-05 17:08
 * Filename : ZOJ2104.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ2104.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <string>
#include <iostream>

#include <map>

using namespace std;


int main(int argc, char* argv[])
{
	map<string,int> myMap;
	map<string,int>::iterator iter;
	//ifstream cin("data.txt");
	int N;
	int max;
	string color;
	cin>>N;
	while(N)
	{
		myMap.clear();
		while(N)
		{
			cin>>color;
			iter = myMap.find(color);
			if(iter == myMap.end())
			{
				myMap.insert(pair<string,int> (color,1));
			}
			else{
				myMap[color] +=1;
			}
			
			--N;
		}
		max = 0;
		for(iter = myMap.begin();iter != myMap.end();++iter)
		{
			if(iter->second > max)
			{
				max = iter->second;
				color = iter->first;
			}
		}
		cout<<color<<endl;
		cin>>N;
	}
	//cin.close();
	return 0;
}

