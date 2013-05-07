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
#include <limits.h>
#include <assert.h>
#include <ctype.h>

#include <set>
#include <math.h>

using namespace std;

set<long long int> myset;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
	freopen("result.txt","w",stdout);
#endif  

	unsigned int MAX=INT_MAX;
	for(unsigned int i=2;i<=sqrt(MAX*1.0);++i)
	{
		int x=i;
		while(x<=MAX/i)
			myset.insert(x*=i);
	}
	set<long long int>::iterator iter=myset.begin();
	for(;iter!=myset.end();++iter)
	{
		printf("%lld\n",*iter);
	}

	return 0;
}
