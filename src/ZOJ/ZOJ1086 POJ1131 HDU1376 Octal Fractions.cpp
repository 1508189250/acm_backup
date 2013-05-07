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
#define EPS 10e-6
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  char str[50];

	while(~scanf("%s",str))
	{
		printf("%s [8] = ",str);
		int len=strlen(str)-1;
		double x=0.0,y=1.0;
		for(int i=len;i>1;--i)
		{
			x=(x+(str[i]-'0')*y)*125;
			y*=1000;
		}
		x/=y;
		int ind=0;
		while(x)
		{
			str[ind]=int(x*=10)+'0';
			x-=(str[ind++]-'0');
		}
		str[ind]='\0';
		printf("0.%s [10]\n",str);
	}

  return 0;
}
