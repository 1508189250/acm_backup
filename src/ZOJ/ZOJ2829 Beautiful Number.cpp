// ZOJ2829 Beautiful Number.cpp : Defines the entry point for the console application.
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

	int circle[]={0,3,5,6,9,10,12,15};
	int n;
	while(scanf("%d",&n) !=EOF)
	{
		printf("%d\n",(n/7)*15+circle[n%7]);
	}



	return 0;
}

