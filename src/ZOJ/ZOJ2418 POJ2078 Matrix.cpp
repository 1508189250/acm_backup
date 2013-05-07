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
#define MAX 9
using namespace std;
int map[MAX][MAX];
int g_max;

void func(const int &num,const int *sum,const int &n)
{
	if(num==n)
	{
		int max_sum=INT_MIN;
		for(int i=0;i<n;++i)
			max_sum=max(max_sum,sum[i]);
    g_max=min(g_max,max_sum);
	}
	int array[MAX];
  memcpy(array,sum,sizeof(int)*n);
	int max_temp=INT_MAX;
	for(int i=0;i<n;++i)
	{
		bool flag=false;
		for(int j=0;j<n;++j)
    {
      array[j]+=map[num][(i+j)%n];
      if(array[j]>=g_max)
      {
        memcpy(array,sum,sizeof(int)*n);
        flag = true;
        break;
      }
    }
    if (flag)
      continue;
    func(num+1,array,n);
    memcpy(array,sum,sizeof(int)*n);
  }
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n;
	int sum[MAX];
	while(scanf("%d",&n)&&n>0)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&map[i][j]);
		memset(sum,0,sizeof(sum));
    g_max=INT_MAX;
    func(0,sum,n);
		printf("%d\n",g_max);
	}

  return 0;
}
