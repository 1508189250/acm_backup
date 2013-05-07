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
#define MAX 15
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	char str_a[MAX][MAX],str[MAX];
	int n,a,b;

	scanf("%d",&n);

	while(n--)
	{
		scanf("%d",&a);
		for(int i=0;i<a;++i)
			scanf("%s",str_a[i]);

		bool flag=true;
		scanf("%d",&b);
		if(a!=b)
			flag=false;
		for(int i=0;i<b;++i)
		{
			scanf("%s",str);
			if(str[0]!=str_a[i][0])
				flag=false;
		}
		if(flag)
			printf("SAME\n");
		else
			printf("DIFFERENT\n");

	}

  return 0;
}
