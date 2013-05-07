// ZOJ2105 Number Sequence.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>
#include <assert.h>
#include <ctype.h>

#define  N 350

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int myarry[N];
	int a,b,n;
	myarry[1]=myarry[2]=1;

	while(cin>>a>>b>>n &&(a||b||n))
	{
		int offset=0,cycle=0,index=0;

		for(int i=3;i<N;++i)
			myarry[i]=(a*myarry[i-1]+b*myarry[i-2])%7;

		if(n<N)
		{
			cout<<myarry[n]<<endl;
			continue;
		}

		for(int i=1;i<N && !cycle;++i)
		{
			for(int j=i+2;j<N-1;++j)
			{
				if(myarry[i]==myarry[j] && myarry[i+1]==myarry[j+1])
				{
					cycle=j-i;
					offset=i;
					break;
				}
			}
		}

		n=(n-offset)%cycle+offset;
		cout<<myarry[n]<<endl;

	}

	return 0;
}
