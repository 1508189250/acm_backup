// ZOJ1577 GCD LCM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



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

#define MAX 1000100

using namespace std;

int main(void)
{
	int x,y;


	while(scanf("%d %d",&x,&y)!=EOF)
	{
		if(y%x)
		{
			printf("0\n");
			continue;
		}

		int temp=y/x;
		int endpoint=sqrt(double(temp));
		int n=0;
		for (int i=2;i<endpoint &&temp>1;++i)
		{
			if (temp%i==0)
			{
				++n;
				temp/=i;
				while(temp%i==0)
				{
					temp/=i;
				}
			}
		}
		if(temp!=1)
			++n;
		printf("%d\n",(int)pow((double)2,(double)n));
	}


	return 0;
}
