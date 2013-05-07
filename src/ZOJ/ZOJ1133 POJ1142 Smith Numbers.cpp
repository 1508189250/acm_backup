// ZOJ1133 POJ1142 Smith Numbers.cpp : Defines the entry point for the console application.
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

using namespace std;
#define MAX_NUM 10000

int main(void)
{
// 	ifstream cin("data.txt");
	int *prime = new int[MAX_NUM];
// 	int prime[MAX_NUM]; 
	int n;
	vector<int> factors;
// 	memset(prime,0,sizeof(prime));
	for (int i=2;i<MAX_NUM;++i)
	{
		prime[i]=1;
	}

	for(int i=4;i<MAX_NUM;i=i+2)
		prime[i]=0;
	for(int i=6;i<MAX_NUM;i=i+3)
		prime[i]=0;
	for(int i=10;i<MAX_NUM;i=i+5)
		prime[i]=0;

	for(int i=7;i<MAX_NUM;++i)
	{
		if(prime[i])
		{
			int temp = sqrt(i/1.0);
			for(int j=2;j<=temp;++j)
			{
				if(prime[j]&&!(i%j))
				{
					prime[i]=0;
					break;
				}
			}
		}
	}

	while(cin>>n &&n)
	{
		++n;
		for(;;++n)
		{

			if (n==18)
			{
				assert(n==18);
			}
			factors.clear();
			int temp(n);
			int endnum(sqrt(n/1.0));
			int sum(0);

			while(temp>1)
			{
				int flag(0);
				for(int i=2;i<=endnum;++i)
				{
					if(prime[i] && !(temp%i))
					{
						temp /=i;
						factors.push_back(i);
						flag=1;
						break;
					}
				}
				if (!flag)
				{
					factors.push_back(temp);
					break;
				}
			}

			if (factors.size()==1)
			{
				continue;
			}
			

			for(int i=0;i<factors.size();++i)
			{
				temp = factors.at(i);
				while(temp)
				{
					sum+=temp%10;
					temp /=10;
				}
			}

			temp=n;
			while(temp)
			{
				sum-=temp%10;
				temp /=10;
			}

			if(!sum)
			{
				cout<<n<<endl;
				break;
			}
		}
	}
	
	delete []prime;

	return 0;
}
