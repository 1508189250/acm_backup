// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define MAX 10000010
using namespace std;

int num[MAX],n;

int bfs(const int &len)
{
	if(len<3)
		return 0;
	if(len==3)
		return 1;
	int rhs=len/2;
	int lhs=len-rhs;
	return bfs(lhs)+bfs(rhs);
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	while(~scanf("%d",&n))
	{
		printf("%d\n",bfs(n));
	}

	return 0;
}
