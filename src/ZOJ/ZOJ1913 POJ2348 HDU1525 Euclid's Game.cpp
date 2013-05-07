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

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int a,b,ans;

	while(scanf("%d%d",&a,&b)&& (a||b))
	{
		ans=0;
		if(a==b)
			goto end;
		while(1)
		{
			if(a==0 || b==0)
				break;
			if(a<b)
				swap(a,b);
			if(a/b>1)
				goto end;
			if(a/b==1)
				++ans;
			a-=b;
		}
end:
		if(ans%2)
			printf("Ollie wins\n");
		else
			printf("Stan wins\n");
	}

	return 0;
}
