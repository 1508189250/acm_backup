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
#define	MAX 1010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	char str[MAX];
	int n;

	scanf("%d",&n);

	while(n--)
	{
		scanf("%s",str);
		int sum=1;
		int i;
		for(i=1;i<strlen(str);++i)
		{
			if(str[i]==str[i-1])
				++sum;
			else
			{
				printf("%d%c",sum,str[i-1]);
				sum=1;
			}
		}
		printf("%d%c\n",sum,str[i-1]);
	}

  return 0;
}
