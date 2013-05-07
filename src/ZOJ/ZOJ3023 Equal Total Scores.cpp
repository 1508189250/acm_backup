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
#define MAX 120
using namespace std;

int array_a[MAX],array_b[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n,m;

	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		int sum_a=0,sum_b=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&array_a[i]);
			sum_a+=array_a[i];
		}

		for(int i=0;i<m;++i)
		{
			scanf("%d",&array_b[i]);
			sum_b+=array_b[i];
		}

		int diff=abs(sum_a-sum_b);

		bool flag=true;
    int temp_a=10000,temp_b=10000;
		for(int i=0;i<n ;++i)
      for(int j=0;j<m;++j)
        if(sum_a-array_a[i]+array_b[j] == sum_b-array_b[j]+array_a[i])
          if(array_a[i]+array_b[j]<temp_a+temp_b)
          {
            temp_a=array_a[i];
            temp_b=array_b[j];
            flag=false;
          }

		if(flag)
			printf("-1\n");
    else
      printf("%d %d\n",temp_a,temp_b);

	}


  return 0;
}
