// ZOJ1243_URLs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int main(void)
{
	//ifstream cin("data.txt");
	int ncases;
	string Protocol,Host,Port,Path;
	string url;
	int start,end;
	cin>>ncases;
	for(int i =1;i<=ncases;++i)
	{
		start=end=0;
		cin>>url;
		end=url.find(':');
		Protocol = url.substr(start,end-start);
		start=end+3;
		end=url.find(":",start);
		int end2 = url.find("/",start);
		if(end == -1)
		{
			Port = "<default>";
			end = url.find("/",start);
			//end = url.find()
			if(end == -1)
			{
				Host = url.substr(start,url.length()-start);
				Path = "<default>";
			}
			else
			{
				Host = url.substr(start,end-start);
				start = end+1;
				Path = url.substr(start,url.length()-start);
			}
		}
		else
		{
			if (end2 !=-1&&end2<end)
			{
				Path = url.substr(end2+1,end-end2-1);
				Host = url.substr(start,end2-start);
				Port = url.substr(end+1,url.length()-end-1);
			} 
			else
			{
				Host = url.substr(start,end-start);
				start = end+1;
				end = url.find("/",start);
				if(end ==-1)
				{
					Path = "<default>";
					Port = url.substr(start,url.length()-start);
				}
				else
				{
					Port = url.substr(start,end - start);
					start = end+1;
					Path = url.substr(start,url.length()-start);
				}
			}
			
		}

		cout<<"URL #"<<i<<endl;
		cout<<"Protocol = "<<Protocol<<endl;
		cout<<"Host     = "<<Host<<endl;
		cout<<"Port     = "<<Port<<endl;
		cout<<"Path     = "<<Path<<endl<<endl;

		
	}


	return 0;
}

