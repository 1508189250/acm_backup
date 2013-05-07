/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-16 17:08
 * Filename : ZOJ1005_POJ1606_Jugs.cpp
 * Description : http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=5
 * *****************************************************************************/
// ZOJ1005_Jugs.cpp : Defines the entry point for the console application.
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
	int a,b,result;
	int aleft,bleft;
	
	while(cin>>a>>b>>result)
	{
		aleft=bleft=0;
		while(aleft!=result && bleft!=result)
		{
			bleft = b;
			cout<<"fill B"<<endl;
			if(1)
			{
				if(a-aleft>=bleft)
				{
					aleft+=bleft;
					bleft=0;
					cout<<"pour B A"<<endl;
				}
				else
				{
					while(bleft > a-aleft && bleft != result)
					{
						bleft = bleft-a+aleft;
						cout<<"pour B A"<<endl;
						aleft =0;
						cout<<"empty A"<<endl;
					}
					if (bleft == result)
					{
						break;
					}
					aleft = bleft;
					bleft =0 ;
					cout<<"pour B A"<<endl;
				}
			}
		}

		cout<<"success"<<endl;
	}


	return 0;
}
