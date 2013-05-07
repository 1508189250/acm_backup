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
int inline func(int n,int base)
{
	if(n==0)
		return 0;
	else
		return n%base+func(n/base,base);
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	for(int i=2992;i<10000;++i)
	{
		int base10=func(i,10),base12=func(i,12),base16=func(i,16);
		if(base10==base12 &&base12==base16)
			printf("%d\n",i);
	}

	return 0;
}
