/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-12 16:58
 * Filename : ZOJ1045_HangOver.cpp
 * Description : ZOJ1045 HangOver
 * *****************************************************************************/
// ZOJ1045_HangOver.cpp : 定义控制台应用程序的入口点。
//

 #include "stdafx.h"
 #include <fstream>

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <math.h>

using namespace std;

int main(void)
{
	ifstream cin("data.txt");
	double c;
	double length[1000];
	int i,n;
	length[0]=0.0;
	for(i=1;length[i-1]<=5.20;++i)
	{
		//c = 1.0/(i+1);
		length[i]=length[i-1]+1.0/(i+1);
	}

	n=i;

	while(cin>>c &&  c > 0.000001)
	{
		for(i=0;i<n;++i)
		{
			if(c<length[i])
			{
				cout<<i<<" card(s)"<<endl;
				break;
			}
		}

	}


	return 0;
}
