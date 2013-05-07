/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-26 19:45
 * Filename : ZOJ2001 POJ1504 Adding Reversed Numbers.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ2001 POJ1504 Adding Reversed Numbers.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>

using namespace std;



int main(void)
{
// 	ifstream cin("data.txt");
	int ncases;
	cin>>ncases;
	while(ncases--)
	{
		string stra,strb,result;
		int num1=0,num2=0,sum;
		int flag=0;
		cin>>stra>>strb;

		for (int i=stra.length()-1;i>=0;--i)
		{
			num1 *=10;
			num1 +=stra.at(i)-'0';
		}
		for (int i=strb.length()-1;i>=0;--i)
		{
			num2 *=10;
			num2 +=strb.at(i)-'0';
		}

		sum = num1+num2;

		while(sum)
		{
			int temp(sum%10);

			if (temp)
			{
				flag=1;
			}
			if (flag)
			{
				cout<<temp;
			}

			sum /=10;
		}
		cout<<endl;

	}



	return 0;
}
