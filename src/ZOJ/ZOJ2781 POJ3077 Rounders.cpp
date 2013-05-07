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
	int ncases;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&num);
		int k=0;
		while(num>9)
		{
			int x=num%10;
			num /=10;
			if(x>4)
				++num;
			++k;
		}
		printf("%d",num);
		while(k--)
			printf("0");
		printf("\n");
	}

  return 0;
}
