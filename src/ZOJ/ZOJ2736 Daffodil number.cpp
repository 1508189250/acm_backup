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

using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int num;

	while(~scanf("%d",&num))
	{
		int a=num;
		int c=a%10;
		a /=10;
		int b=a%10;
		a /=10;
		if(a*a*a+b*b*b+c*c*c == num)
			printf("Yes\n");
		else
			printf("No\n");
	}

  return 0;
}
