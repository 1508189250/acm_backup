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
#define MAX 10010
using namespace std;

int num[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n;

	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);

		sort(num,num+n);
		
		long long ans=0ll;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				ans+=static_cast<long long>(num[j]-num[i]);

		printf("%lld\n",ans*2);
	}

  return 0;
}
