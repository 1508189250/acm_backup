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
#define MAX 12
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	char num_a[MAX], num_b[MAX];

	while(~scanf("%s %s",num_a,num_b))
	{
		int len_a=strlen(num_a);
		int len_b=strlen(num_b);
		long long ans=0ll;
		for(int i=0;i<len_a;++i)
			for(int j=0;j<len_b;++j)
				ans+=(num_a[i]-'0')*(num_b[j]-'0');
		printf("%lld\n",ans);
	}

  return 0;
}
