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

#include <set>
#define MAX 500010

using namespace std;

int arr[MAX];
set<int> mset;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	arr[0]=0;
	mset.insert(0);
	for(int i=1;i<MAX;++i)
	{
		if(arr[i-1]-i>0 && mset.find(arr[i-1]-i)==mset.end())
			arr[i]=arr[i-1]-i;
		else
			arr[i]=arr[i-1]+i;
		mset.insert(arr[i]);
	}
	int n;
	while(scanf("%d",&n) && n>=0)
		printf("%d\n",arr[n]);
	return 0;
}
