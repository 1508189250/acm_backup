// ZOJ1242_Carbon_Dating.cpp : 定义控制台应用程序的入口点。
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
	double w,d,years,count=1;
	while((cin>>w>>d)&&(w!=0)&&(d!=0))
	{
		w = w*810;
		d = d / w;
		years = -5730*log(d) / log(2.0);

// 		if (count!=1)
// 		{
// 			cout<<endl;
// 		}

		cout<<"Sample #"<<count<<endl;
		++count;

		if (years<10000)
		{
			
			cout<<"The approximate age is "<<(int((years+50)/100))*100<<" years."<<endl<<endl;
			//cout<<years<<endl;
		}
		else
		{
			cout<<"The approximate age is "<<(int((years+500)/1000))*1000<<" years."<<endl<<endl;

		}

	}


	return 0;
}
