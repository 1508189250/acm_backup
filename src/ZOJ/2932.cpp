// 2932.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	//ifstream cin("data.txt");

	string str,getstr;
	char chr[80];
	cin.getline(chr,80);
	while(chr[0] != '#')
	{
		str="";
		getstr=chr;
		for(int i=0;i<getstr.size();++i){
			if (getstr[i]==' ')
			{
				str+="%20";
			} 
			else if(getstr[i]=='!')
			{
				str+="%21";
			}
			else if(getstr[i]=='$')
			{
				str+="%24";
			}
			else if (getstr[i]=='%')
			{
				str+="%25";
			}
			else if(getstr[i]=='(')
			{
				str+="%28";
			}
			else if (getstr[i]==')')
			{
				str+="%29";
			}
			else if (getstr[i]=='*')
			{
				str+="%2a";
			}
			else
				str+=getstr[i];
		}
		
		//printf("%s",str);
		cout<<str<<endl;
		cin.getline(chr,80);
	}
	//printf("%s",str);
	return 0;
}

