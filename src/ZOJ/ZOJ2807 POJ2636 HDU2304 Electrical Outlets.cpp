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

	int ncases;
	int n;
	int temp;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		int sum=1-n;
		while(n--)
		{
			scanf("%d",&temp);
			sum+=temp;
		}
		printf("%d\n",sum);
	}

  return 0;
}
