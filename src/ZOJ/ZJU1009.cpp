// ZJU1009.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int keys;
vector<char> router1,router2,router3;
vector<int> distence12,distence23;

void initial()
{
	router1.clear();
	router2.clear();
	router3.clear();

	for(int i=0;i<keys;++i)
	{
		cin>>ch;
		router1.push_back(ch);
	}

	for(int i=0;i<keys;++i)
	{
		cin>>ch;
		router2.push_back(ch);
	}

	for(int i=0;i<keys;++i)
	{
		cin>>ch;
		router3.push_back(ch);
	}

	for(int i=0;i<keys;++k)
	{
		for(int j=0;j<keys;++j)
		{
			if(router1.at(i) == router2.at(j))
			{
				distence12.at(i)=i-j;
				break;
			}
		}
		for(int j=0;j<keys; ++j)
		{
			if(router2.at(i) == router3.at(j))
			{
				distence23.at(i)=i-j;
				break;
			}
		}
	}
}

func(string str)
{
	int length = str.length();
	for(int i=0;i<length;++i)
	{

	}
}

int main(int argc, char* argv[])
{
	char ch;
	int flag=0;
	int cases=1;
	int line;
	string str;
	cin >> keys;
	while(keys >0)
	{
		initial();
		cin>>line;
		cout<<"Enigma "<<cases<<":"<<endl;
		++cases;
		while(line >0)
		{
			cin>>str;
			func(str);

		}

		cin >> keys;
	}
	return 0;
}

