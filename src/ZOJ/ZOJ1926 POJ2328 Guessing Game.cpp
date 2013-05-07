// ZOJ1926 POJ2328 Guessing Game.cpp : Defines the entry point for the console application.
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
#include <limits>
#include <assert.h>
#include <ctype.h>

using namespace std;

int main(void)
{
	int num[15];
	int n;
	int flag=1;
	string str;

	while(cin>>n &&n)
	{
		if(flag)
		{
			flag=0;
			memset(num,0,sizeof(num));
		}
		getchar();
		getline(cin,str);
		if(str=="too high")
			for(int i=n;i<=10;++i)
				num[i]=-1;
		if(str=="too low")
			for(int i=1;i<=n;++i)
				num[i]=-1;
		if(str=="right on")
		{
			flag=1;
			if(num[n]==-1)
				cout<<"Stan is dishonest"<<endl;
			else
				cout<<"Stan may be honest"<<endl;
		}
	}


	return 0;
}
