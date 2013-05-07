/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-24 10:25
 * Filename : ZOJ2482 POJ2105 IP Address.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ2482 POJ2105 IP Address.cpp : Defines the entry point for the console application.
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
	int power[8]={128,64,32,16,8,4,2,1};
	int ncases;
	int sum;
	char ch;
	
	cin>>ncases;

	while(ncases--)
	{
		for(int i=0;i<4;++i)
		{
			sum=0;
			for(int j=0;j<8;++j)
			{
				cin>>ch;
				ch -='0';
				if(ch)
					sum +=power[j];
			}
			
			if(i !=0)
				cout<<'.';
			cout<<sum;
		}
		cout<<endl;
	}


	return 0;
}
