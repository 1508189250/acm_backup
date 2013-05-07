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

using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	set<int> mset;
	int n,temp;
	while(scanf("%d",&n)&&n)
	{
		mset.clear();
		for(int i=0;i<n;++i)
		{
			scanf("%d",&temp);
			mset.insert(temp);
		}
		set<int>::iterator iter=mset.begin();
		printf("%d",*(iter++));
		while(iter!=mset.end())
			printf(" %d",*(iter++));
		printf("\n");
	}

	return 0;
}
