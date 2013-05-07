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

  int n,ncase=1;
  char str[MAX];
  //   scanf("%d",&ncase);

  while(~scanf("%s",str) && str[0]!='#')
  {
		if(next_permutation(str,str+strlen(str)))
			puts(str);
		else
			puts("No Successor");
  }

  return 0;
}
