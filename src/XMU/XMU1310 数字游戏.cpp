/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-04-06 14:41
 # Filename: XMU1310 Êý×ÖÓÎÏ·.cpp
 # Description : 
 ******************************************************************************/
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

int num[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  scanf("%d",&ncase);

  for(int nc=1;nc<=ncase;++nc)
  {
    printf("Case %d:\n",nc);
    scanf("%d",&n);
    int beg=1;
    if(n%2)
      beg=0;
    num[0]=0;
    ++n;
    for(int i=1;i<n;++i)
      scanf("%d",&num[i]);

    int ans=0;
    for(int i=beg;i<n;i+=2)
      ans^=(num[i+1]-num[i]);
    if(ans)
      printf("No\n");
    else
      printf("Yes\n");
  }

  return 0;
}
