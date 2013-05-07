// ZOJ2022 POJ1401 Factorial.cpp : Defines the entry point for the console application.
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
	int T;
	int N;
	scanf("%d",&T);

	for(int i=0;i<T;++i)
	{
		int sum(0);
		scanf("%d",&N);
		while(N)
		{
			sum+=N/5;
			N /=5;
		}
		printf("%d\n",sum);
	}


	return 0;
}
