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

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	long long int ans,num;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%lld",&num);
		int i=1;
		ans=0;
		for(;i<=sqrt(num*1.0);++i)
			ans+=num/i;
		--i;
		ans=ans*2-i*i-num;
		printf("%lld\n",ans);
	}

	return 0;
}
