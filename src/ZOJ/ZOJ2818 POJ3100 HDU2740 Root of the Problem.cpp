// ZOJ2818 POJ3100 HDU2740 Root of the Problem.cpp : Defines the entry point for the console application.
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
	int b,n;
	while(scanf("%d %d",&b,&n)&&b&&n)
	{
		int temp=(int)(pow(b*1.0,1.0/n));
		int temp2=(int)(pow(b*1.0,1.0/n)+0.999999999);
		if (b-pow(temp*1.0,n)>pow(temp2*1.0,n)-b)
		{
			temp=temp2;
		}
		printf("%d\n",temp);
	}


	return 0;
}
