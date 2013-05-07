// ZOJ1526 POJ1423 HDU1018 Big Number.cpp : Defines the entry point for the console application.
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

#define PI 3.14159265

using namespace std;

int main(void)
{
	int ncases;
	int N;

	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&N);
		double sum=0;

		if(N==1) sum=1;
		else
		{
			sum=(int)ceil((N*log((double)N)-N + log(2.0*N*PI)/2)/log(10.0));
		}

		printf("%d\n",(int)sum);
	}



	return 0;
}
