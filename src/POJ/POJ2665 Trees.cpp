#ifdef _MSC_VER
#define DEBUG
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <ctype.h>
#define MAX 100010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
	long long sum,beg,end;
	int n;

	while(scanf("%lld%d",&sum,&n) && sum &&n)
	{
		++sum;
		while(n--)
		{
			scanf("%lld %lld",&beg,&end);
			sum-=(end-beg+1);
		}
		printf("%lld\n",sum);
	}

  return 0;
}
