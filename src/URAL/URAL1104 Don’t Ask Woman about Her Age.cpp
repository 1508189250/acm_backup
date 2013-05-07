#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 1000010
using namespace std;

char num[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	scanf("%s",num);
	int n=strlen(num);

	int max_num=0;
	for(int i=0;i<n;++i)
	{
		if(num[i]>='0' && num[i]<='9')
			num[i]-='0';
		else
			num[i]-=('A'-10);
		max_num=max(max_num,(int)num[i]);
	}
	if(max_num<2)
  {
		printf("2\n");
    return 0;
  }

	int temp,base;
	for(base=max_num+1;base<=36;++base)
	{
		temp=0;
		for(int i=0;i<n;++i)
		{
			temp*=base;
			temp+=num[i];
			temp%=(base-1);
		}
		if(!temp)
			break;
	}

	if(!temp)
		printf("%d\n",base);
	else
		printf("No solution.\n");

  return 0;
}
