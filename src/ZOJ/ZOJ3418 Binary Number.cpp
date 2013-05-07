// ZOJ3418 Binary Number.cpp : Defines the entry point for the console application.
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

int aset[110],bset[110];

int func(const int &lhs,const int &rhs)
{
	int temp=lhs^rhs;
	int sum=0;
	while(temp)
	{
		sum+=temp%2;
		temp/=2;
	}
	return sum;
}

int main(void)
{
// 	ifstream cin("data.txt");
	int ncases;
	int m,n;
	cin>>ncases;

	while(ncases--)
	{
		cin>>m>>n;
		for(int i=0;i<m;++i)
			cin>>aset[i];
		for(int i=0;i<n;++i)
			cin>>bset[i];

		sort(aset,aset+m);

		for(int i=0;i<n;++i)
		{
			int temp,sum=100000,result;
			for(int j=0;j<m;++j)
			{
				temp=func(aset[j],bset[i]);
				if(sum>temp)
				{
					sum=temp;
					result=aset[j];
				}
			}
			cout<<result<<endl;
		}
	}
	return 0;
}

