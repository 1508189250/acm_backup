// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int ropes[1010];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int t,n;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&ropes[i]);
		}
		sort(ropes,ropes+n);
		for(int i=0;i<n;++i)
			if(ropes[i]*(n-i)>sum)
				sum = ropes[i]*(n-i);

		printf("%d\n",sum);
	}

	return 0;
}
