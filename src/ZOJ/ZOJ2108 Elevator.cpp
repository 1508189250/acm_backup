// ZOJ2108 Elevator.cpp : Defines the entry point for the console application.
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

using namespace std;

int main(void)
{
// 	ifstream cin("data.txt");
	int n;
	while(cin>>n &&n)
	{
		int previous,next,distence;
		int sum(0);
		previous=0;
		for(int i=0;i<n;++i)
		{
			cin>>next;
			distence=next-previous;
			if(distence>0)
				sum=sum+distence*6+5;
			else if(distence<0)
				sum=sum-distence*4+5;
			else
				sum+=5;
			previous=next;
		}
		printf("%d\n",sum);
	}


	return 0;
}

