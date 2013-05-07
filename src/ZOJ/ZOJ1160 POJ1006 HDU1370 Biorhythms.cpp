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
#define MAX 25000
using namespace std;

int date[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int a,b,c,d;
  int ncase;
  scanf("%d",&ncase);


  while(ncase--)
  {
    int nc=1;

    while(scanf("%d%d%d%d",&a,&b,&c,&d)&&a>=0)
    {
      memset(date,0,sizeof(date));

      for(int i=a;i>=0;i-=23)
        ++date[i];
      for(int i=a+23;i<MAX;i+=23)
        ++date[i];

      for(int i=b;i>=0;i-=28)
        ++date[i];
      for(int i=b+28;i<MAX;i+=28)
        ++date[i];

      for(int i=c;i>=0;i-=33)
        ++date[i];
      for(int i=c+33;i<MAX;i+=33)
        ++date[i];

      int ans=1;
      for(;date[d+ans]!=3;++ans);
      printf("Case %d: the next triple peak occurs in %d days.\n",nc++,ans);
    }
    if(ncase!=0)
      printf("\n");
  }

  return 0;
}
