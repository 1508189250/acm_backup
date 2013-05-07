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

int num[1010];
char input[1010];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int ncases;
	scanf("%d",&ncases);
	while(ncases--)
	{
		getchar();
		scanf("%s",input);
		int len=0;
		for(int i=strlen(input)-1;i>=0;--i)
			num[len++]=input[i]-'0';
		int flag;
		for(flag=0;flag<len;++flag)
			if(num[flag]!=0 )
				break;
		--num[flag];
		int tab;
		for(tab=flag+1;tab<len;++tab)
			if (num[tab]!=9)
				break;
		if(tab==len)
		{
			num[tab]=1;
			++len;
		}
		else
			++num[tab];
		sort(num,num+tab,greater<int>());
		for(int i=len-1;i>=0;--i)
			printf("%d",num[i]);
		printf("\n");
	}
	return 0;
}


