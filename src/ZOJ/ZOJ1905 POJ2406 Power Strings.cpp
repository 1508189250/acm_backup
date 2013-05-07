// ZOJ1905 POJ2406 Power Strings.cpp : Defines the entry point for the console application.
//

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

#define MAX 1001010 

char str[MAX],temp[MAX];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	while(gets(str) &&strlen(str))
	{
		if (strlen(str)==1 && str[0]=='.')
			break;
		int len=strlen(str);
		for(int i=1;i<=len;++i)
		{
			if(len%i) continue;
			bool btmp=true;
			strncpy(temp,str,i);
			for(int j=1;j*i<=len && btmp;++j)
			{
				for(int k=0;k<i;++k)
					if(temp[k]!=str[k+i*(j-1)])
					{
						btmp=false;
						break;
					}
			}
			if(btmp)
			{
				printf("%d\n",len/i);
				break;
			}
		}
	}

	return 0;
}

