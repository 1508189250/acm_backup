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
#define MAX 128
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	char stra[MAX],strb[MAX];
	int suma[MAX],sumb[MAX];

	while(gets(stra))
	{
		gets(strb);
		memset(suma,0,sizeof(suma));
		memset(sumb,0,sizeof(sumb));

		for(int i=0;stra[i];++i)
      if(isalpha(stra[i]))
		  	++suma[stra[i]];

		for(int i=0;strb[i];++i)
      if(isalpha(strb[i]))
			  ++sumb[strb[i]];

		sort(suma,suma+MAX,greater<int>());
		sort(sumb,sumb+MAX,greater<int>());

		bool flag=true;
		for(int i=0;i<MAX;++i)
			if(suma[i]!=sumb[i])
			{
				flag=false;
				break;
			}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

  return 0;
}
