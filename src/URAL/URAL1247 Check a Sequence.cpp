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
#define MAX 30010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int s,n;
	int num[MAX];

	while(~scanf("%d%d",&s,&n))
	{
		for(int i=0;i<s;++i)
		{
			scanf("%d",&num[i]);
			--num[i];
		}
		int sum=0,temp=0;
		for(int i=0;i<s;++i)
		{
			temp=max(0,temp);
			temp+=num[i];
			sum=max(sum,temp);
		}
		if(sum>n)
			printf("NO\n");
		else
			printf("YES\n");

	}

  return 0;
}
