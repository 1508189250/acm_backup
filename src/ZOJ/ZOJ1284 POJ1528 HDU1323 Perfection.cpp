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
#define MAX 60010
using namespace std;

int num[MAX];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	memset(num,0,sizeof(num));
	for(int i=1;i<MAX;++i)
		for(int j=1;j*i<MAX;++j)
			num[j*i]+=i;
	int n;

	printf("PERFECTION OUTPUT\n");

	while(scanf("%d",&n) &&n)
	{
		if(num[n]==2*n)
			printf("%5d  PERFECT\n",n);
		else if(num[n]<2*n)
			printf("%5d  DEFICIENT\n",n);
		else
			printf("%5d  ABUNDANT\n",n);
	}

	printf("END OF OUTPUT\n");

	return 0;
}
