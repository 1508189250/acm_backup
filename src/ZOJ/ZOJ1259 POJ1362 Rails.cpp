// ZOJ1259 POJ1362 Rails.cpp : Defines the entry point for the console application.
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
	stack<int> rails;
	int n;
	int temp;
	int order[1020];

	while(scanf("%d", &n) && n)
	{
		while(scanf("%d", &temp) &&temp)
		{
			order[0]=temp;
			for(int i=1;i<n;++i)
				scanf("%d",&order[i]);

			int num=1;
			int flag=1;
			while(!rails.empty())
				rails.pop();

			for(int i=0;i<n;++i)
			{
				if(!rails.empty() && rails.top()>order[i])
				{
					flag=0;
					break;
				}
				else
				{
					while(rails.empty() || rails.top()<order[i])
						rails.push(num++);

					rails.pop();
				}
			}

			if(flag)
				printf("Yes\n");
			else
				printf("No\n");
		}
		printf("\n");
	}



			

	return 0;
}
