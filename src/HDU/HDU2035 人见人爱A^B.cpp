/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-13 16:07
 # Filename: acm.cpp
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
using namespace std;

const int kMAX=10010;
const double kEPS=10E-6;

__int64 exp_mod(const __int64 &base,const __int64 &exp,const __int64 &mod)
{
  if(exp==0) return 1%mod;
  if(exp==1) return base%mod;
  __int64 tmp=exp_mod(base,exp/2,mod);
  tmp=tmp*tmp%mod;
  if(exp&1) tmp=tmp*base%mod;//if n is odd;
  return tmp;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int a,b;

  while(~scanf("%d%d",&a,&b) && (a+b))
  {
    __int64 ans=exp_mod(a,b,1000);
    printf("%I64d\n",ans);
  }

  return 0;
}

