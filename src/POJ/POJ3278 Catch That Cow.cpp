/*******************************************************************************
 * Author : Neo Fung
 * Email : neosfung@gmail.com
 * Last modified : 2011-07-15 15:52
 * Filename : POJ3278 Catch That Cow.cpp
 * Description : http://poj.org/problem?id=3278
 * *****************************************************************************/
// POJ3278 Catch That Cow.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #include <fstream>

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int N,K;
	int temp,sum,count,level;
	int a,b,c;
	int location[100001];
	memset(location,1,sizeof(location));
	deque<int> mydeque;
	sum=count=level=0;
	int flag=1;
	cin>>N>>K;
	mydeque.push_back(N);
	location[N]=0;
	count=1;
	while(flag)
	{
		sum=0;
		for(int i=0;i<count;++i)
		{
			temp=mydeque.front();
			mydeque.pop_front();
			if(temp==K)
			{
				flag=0;
				break;
			}
			else
			{
				a=temp-1;
				b=temp+1;
				c=temp*2;
				if(a>-1 && location[a])
				{
					mydeque.push_back(a);
					++sum;
					location[a]=0;
				}
				if (location[b])
				{
					mydeque.push_back(b);
					++sum;
					location[b]=0;
				}
				if(c<=100000 && location[c])
				{
					mydeque.push_back(c);
					++sum;
					location[c]=0;
				}
			}
		}
		count = sum;
		++level;
		
	}

	cout<<--level<<endl;

	return 0;
}
