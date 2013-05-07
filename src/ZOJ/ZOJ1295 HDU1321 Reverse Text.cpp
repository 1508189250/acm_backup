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
	int ncases;
	char str[100];
	scanf("%d",&ncases);
	getchar();
	while(ncases--)
	{
		gets(str);
		for(int i=strlen(str)-1;i>=0;--i)
			printf("%c",str[i]);
		printf("\n");
	}

	return 0;
}
