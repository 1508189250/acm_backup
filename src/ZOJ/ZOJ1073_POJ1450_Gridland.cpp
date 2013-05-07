/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-17 10:14
 * Filename : ZOJ1073_POJ1450_Gridland.cpp
 * Description :	http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1037
					http://poj.org/problem?id=1450
 * *****************************************************************************/
// ZOJ1073_POJ1450_Gridland.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
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
	//ifstream cin("data.txt");
	int ncases,m,n;
	int i;
	double result;
	cin>>ncases;
	for(i =1;i<=ncases;++i)
	{
		cin>>m>>n;
		if(m%2 && n%2)
		{
			result = m*n -1 + sqrt(2.0);
		}
		else
		{
			result = m*n;
		}

		cout<<"Scenario #"<<i<<":"<<endl;
		printf("%.2f\n\n",result);
	}


	return 0;
}
