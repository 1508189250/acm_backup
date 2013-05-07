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
  scanf("%d",&ncases);


  while(ncases--)
  {
    int tab=0,space=0;
    while(gets(str))
    {
      if(!strcmp(str,"##"))
        break;

      bool flag=true;
      int n=strlen(str);
      while(n>0)
      {
        --n;
        if(str[n]==' ' && flag)
          ++space;
        else if(str[n]=='\t'&& flag)
        {
          ++tab;
          space+=4;
        }
        else if(str[n]=='\t')
          ++tab;
        else
          flag=false;
      }
    }			
    printf("%d tab(s) replaced\n",tab);
    printf("%d trailing space(s) removed\n",space);
  }

  return 0;
}
