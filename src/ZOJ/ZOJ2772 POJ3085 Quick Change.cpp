// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int inline func(int &value,int base)
{
		int result=value/base;
		value %=base;
		return result;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int c;
	int n;
	scanf("%d",&c);
	for(int i=1;i<=c;++i)
	{
		scanf("%d",&n);
		int quar=func(n,25);
		int dime=func(n,10);
		int nickels=func(n,5);
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",i,quar,dime,nickels,n);
	}

	return 0;
}
