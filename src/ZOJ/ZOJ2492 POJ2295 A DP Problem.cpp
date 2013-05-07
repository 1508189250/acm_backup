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

	int ncases;
	char str[MAX];
	scanf("%d\n",&ncases);
	while(ncases--)
	{
		gets(str);
		bool flag=false;
		int sign=1;
		int a=0,b=0,tmp=0;

		for(int i=0;str[i];++i)
		{
			if(str[i]=='-')
			{
				b+=tmp*sign;
				if(flag)
					sign=1;
				else
					sign=-1;
				tmp=0;
			}
			else if(str[i]=='+')
			{
				b+=tmp*sign;
				if(flag)
					sign=-1;
				else
					sign=1;
				tmp=0;
			}
			else if(str[i]=='=')
			{
				b+=tmp*sign;
				flag=true;
				sign=-1;
				tmp=0;
			}
			else if(str[i]=='x')
			{
				if(!tmp)
					tmp=1;
				a+=tmp*sign;
				tmp=0;
			}
			else if(isdigit(str[i]))
				tmp=tmp*10+str[i]-'0';
		}
    if(tmp)
    {
      b+=tmp*sign;
    }
		if(!a&&!b)
			printf("IDENTITY\n");
    else if(!a)
      printf("IMPOSSIBLE\n");
		else
			printf("%d\n",static_cast<int>(floor(static_cast<double>(b)/-a)));
	}

  return 0;
}
