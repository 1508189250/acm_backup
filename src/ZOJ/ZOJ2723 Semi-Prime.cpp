// ZOJ2723 Semi-Prime.cpp : Defines the entry point for the console application.
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

#define N 1000010

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int prime[N];
	for(int i=0;i<N;++i)
		prime[i]=i;
	for(int i=2;i<=500000;++i)
		if(prime[i])
			for(int j=2;j*i<N;++j)
				prime[i*j]=0;

	int n;
	while(cin>>n)
	{
		int count=0;
		int end=n/2;
			for(int i=2;i<=end;)
			{
				if(!(n%i) &&prime[i])
				{
					n=n/i;
					++count;
				}
				else
					++i;
			}

		if(count==2)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}


	return 0;
}
