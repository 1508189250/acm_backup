/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-08-08 21:29
 * Filename : ZOJ1889 POJ2551 Ones.cpp
 * Description : 
 * *****************************************************************************/
// ZOJ1889 POJ2551 Ones.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
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
	int n;
	while(cin>>n)
	{
		int temp=0;
		int ones=0;
		while(1)
		{
			temp=(temp*10+1)%n;
			++ones;
			if (!temp)
			{
				cout<<ones<<endl;
				break;
			}
		}
	}


	return 0;
}
