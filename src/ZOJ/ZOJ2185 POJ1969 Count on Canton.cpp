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
	int a,b,n;
	int flag;

	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		a=1;
		b=1;
		for(int i=2;i<=n;++i)
		{
			if(flag==0 && a==1)
			{
				++b;
				flag=1;
			}
			else if(flag==1 && b==1)
			{
				++a;
				flag=0;
			}
			else if(flag==0)
			{
				--a;
				++b;
			}
			else if(flag==1)
			{
				++a;
				--b;
			}
		}
		printf("TERM %d IS %d/%d\n",n,a,b);
	}
	

	return 0;
}
