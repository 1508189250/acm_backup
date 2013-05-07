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

	char *haab[19]={"pop", "no", "zip", "zotz", "tzec", "xul", 
    "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", 
		"kankin", "muan", "pax", "koyab", "cumhu","uayet"};
	char *tzolkin[20]={"imix", "ik", "akbal", "kan", "chicchan", 
    "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", 
		"ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

	int n,day, years,num;
	char str[20];
	scanf("%d",&n);
	printf("%d\n",n);
	while(n--)
	{
		scanf("%d. %s %d",&day,&str,&years);
		int ind=0;
		for(;ind<19;++ind)
			if(strcmp(str,haab[ind])==0)
				break;

    long long total=years*365 + ind*20+day+1;
    years = (total-1)/260;
    if((total%=260)==0) total=260;
    if((day=total%20)==0) day=20;
    if((num=total%13)==0) num=13;

		printf("%d %s %d\n",num,tzolkin[day-1],years);

	}

  return 0;
}
