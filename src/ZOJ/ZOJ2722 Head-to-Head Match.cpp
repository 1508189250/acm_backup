// ZOJ2722 Head-to-Head Match.cpp : Defines the entry point for the console application.
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
// 	ifstream cin("data.txt");
	int n;
	while(scanf("%d",&n)&&n)
	{

		printf("%d\n",(int)(log10(n*1.0)/log10(2.0)+0.9999999999));
	}


	return 0;
}
