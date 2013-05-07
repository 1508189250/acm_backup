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
#define MAX 1002

using namespace std;

long long int T[MAX];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	T[0]=0;
	for(int i=1;i<MAX;++i)
		T[i]=T[i-1]+i;
	for(int i=1;i<=1000;++i)
		T[i]=T[i+1]*i+T[i-1];
	int n,num;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&num);
		printf("%d %d %lld\n",i,num,T[num]);
	}


	return 0;
}
