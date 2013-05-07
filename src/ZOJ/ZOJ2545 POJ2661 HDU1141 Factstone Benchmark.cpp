// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int year;
	
	while(scanf("%d",&year) && year)
	{
		year =  (year-1960)/10+2;
		int p=1<<year;
		double sum=1.0;
		int k=1;
		while(p--)
		{
			sum*=2.0;
			if(sum>k)
			{
				++k;
				sum /=k;
			}
		}
		printf("%d\n",k);
	}

	return 0;
}
