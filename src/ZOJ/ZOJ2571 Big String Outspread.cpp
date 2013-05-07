// ZOJ2571 Big String Outspread.cpp : Defines the entry point for the console application.
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
#define MAX 500

using namespace std;

char str[260],x,LEN;

void unfold(int pos)
{
	if(pos>=LEN)
		return;
	else if(str[pos]=='(')
		unfold(pos+1);
	else if(str[pos]==')')
		x=pos;
	else if(isalpha(str[pos]))
	{
		printf("%c",str[pos]);
		unfold(pos+1);
	}
	else if(isdigit(str[pos]))
	{
		int len=str[pos]-'0';
		if (isalpha(str[pos+1]))
		{
			while(len--) printf("%c",str[pos+1]);
			unfold(pos+2);
		} 
		else
		{
			while(len--)
				unfold(pos+1);
			unfold(x+1);
		}
	}
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int ncases;
	scanf("%d",&ncases);
	getchar();
	while(ncases--)
	{
		gets(str);
		LEN = strlen(str);
		unfold(0);
		printf("\n");
	}


	return 0;
}
