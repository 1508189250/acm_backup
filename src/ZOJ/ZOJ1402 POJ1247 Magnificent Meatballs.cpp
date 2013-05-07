// ZOJ1402 POJ1247 Magnificent Meatballs.cpp : Defines the entry point for the console application.
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

int main(void)
{
// 	ifstream cin("data.txt");
	int n;
	int seats[35];
	while(cin>>n &&n)
	{
		int sum(0);
		for(int i=1;i<=n;++i)
		{
			cin>>seats[i];
			sum+=seats[i];
		}

		if(sum%2)
		{
			cout<<"No equal partitioning."<<endl;
			continue;
		}

		sum /=2;

		int flag(0);
		for(int i=1;i<=n;++i)
		{
			sum -=seats[i];
			if(sum==0)
			{
				flag=i;
				break;
			}
			if(sum<0)
				break;
		}

		if(flag)
		{
			printf("Sam stops at position %d and Ella stops at position %d.\n",flag,flag+1);
		}
		else
		{
			printf("No equal partitioning.\n");
		}

	}


	return 0;
}
