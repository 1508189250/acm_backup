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

  long long base[]={1,9,81,729,6561,59049,531441,4782969,43046721};
	long long n;

	while(scanf("%lld",&n) && n)
	{
		printf("%lld: ",n);
		long long ans=0ll;
		int index=0;

		while(n)
		{
			long long tmp=n%10;
			if(tmp>4)
				--tmp;
			ans+=tmp*base[index++];
			n/=10;
		}
		printf("%lld\n",ans);
	}

  return 0;
}
