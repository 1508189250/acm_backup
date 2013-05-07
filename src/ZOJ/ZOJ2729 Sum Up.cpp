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
	int n;
	while(scanf("%d",&n) && n>=0)
	{
		int sum=0;
		int temp=0,num,remain=0;
		while(n--)
		{
			scanf("%d",&num);
			temp=temp<<16;
			temp+=num;
			remain+=16;
			while(remain>=7)
			{
				remain=(remain/7-1)*7+remain%7;
				num=(temp>>remain)&127;
				if(num>63)
					sum+=64-num;
				else
					sum+=num;
			}
		}
		printf("%d\n",sum);
	}

	return 0;
}
