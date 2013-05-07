// ZOJ2476 Total Amount.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
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
	freopen("result.txt","w",stdout);
#endif  
	char ch;
	int n;
	double sum;
	char amount[20];
	while(scanf("%d",&n)&&n)
	{
		sum=0.0;
		getchar();
		while(n--)
		{
			int ind=0;
			getchar();
			while(ch=getchar())
			{
				if(ch=='\n') break;
				if(ch!=',')
					amount[ind++]=ch;
			}
			amount[ind]='\0';
			sum+=atof(amount);
		}
		sprintf(amount,"%0.2lf",sum);
		int len=strlen(amount),ind=0,comma=0;
		char result[30];
		for(int i=len-1;i>=len-3;--i)
			result[ind++]=amount[i];
		for (int i=len-4;i>=0;--i)
		{
			result[ind++]=amount[i];
			++comma;
			if(comma%3==0 && i)
				result[ind++]=',';
		}
		result[ind]='$';
		for (int i=ind;i>=0;--i)
		{
			putchar(result[i]);
		}
		printf("\n");
	}

	return 0;
}
