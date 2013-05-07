/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-20 17:07
 * Filename : POJ1836 Alignment.cpp
 * Description : http://poj.org/problem?id=1836
 * *****************************************************************************/
// POJ1836 Alignment.cpp : Defines the entry point for the console application.
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
	int DP[1001];
	int DP2[1001];
	double height[1001];
	int n;
	int maxdp,maxdp2;

	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>height[i];
	}
	DP[0]=1;
	DP2[n-1]=1;

	for(int i=1;i<n;++i)
	{
		maxdp=1;
		for(int j=i-1;j>=0;--j)
		{
			if(height[i]>height[j] && DP[j]>=maxdp) maxdp=DP[j]+1;
		}
		DP[i]=maxdp;
	}

	for(int i=n-2;i>=0;--i)
	{
		maxdp2=1;
		for (int j=i+1;j<n;++j)
		{
			if(height[i]>height[j] && DP2[j]>=maxdp2) maxdp2=DP2[j]+1;
		}
		DP2[i]=maxdp2;
	}

	maxdp=0;
	int maxindex;

	for (int i=0;i<n;++i)
	{
		if (maxdp<=DP[i]+DP2[i])
		{
			maxdp=DP[i]+DP2[i];
			maxindex = i;
		}
	}

	for (int i=0;i<maxindex;++i)
	{
		if (height[i]==height[maxindex])
		{
			++maxdp;
		}
	}

	cout<<n-maxdp+1<<endl;


	return 0;
}
