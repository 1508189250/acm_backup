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
#define MAX 512
using namespace std;

bool func(char *str,const int &len)
{
	if(len==1 && 'p'<=str[0] && 'z'>=str[0])
		return true;
	else if(len==1)
		return false;

	if(str[0]=='N')
		return func(str+1,len-1);

	if(str[0]=='C' || str[0]=='D' || str[0]=='E' || str[0]=='I')
	{
		for(int i=1;i<len-1;++i)
			if(func(str+1,i) && func(str+1+i,len-1-i))
				return true;
	}
	return false;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  char str[MAX];
//   scanf("%d",&ncase);

  while(~scanf("%s",str))
  {
    int len=strlen(str);
		if(func(str,len))
			printf("YES\n");
		else
			printf("NO\n");
  }

  return 0;
}
