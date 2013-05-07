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
#define MAX 1000010
using namespace std;

char stra[MAX],strb[MAX];

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
			scanf("\n%c %c",&stra[i],&strb[i]);

		for(int i=n-1;i>=0;--i)
		{
			stra[i]+=(strb[i]-'0');
			if(stra[i]>'9')
			{
				++stra[i-1];
				stra[i]-=10;
			}
		}
		stra[n]='\0';
		puts(stra);
	}

  return 0;
}
