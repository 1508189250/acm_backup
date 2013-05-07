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

	int clock[60];
	int s,d;
	while(scanf("%d%d",&s,&d)&&(s||d))
	{
		memset(clock,0,sizeof(clock));
		int num=0;
		while(!clock[s] && s)
		{
			clock[s]=1;
			s=(s*d+s)%60;
			++num;
		}
		if(s==0)
			printf("%d\n",num);
		else
			printf("Impossible\n");
	}

	return 0;
}
