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

//可扩展欧几里得算法, a,b为系数, x,y为一组解, 返回值为a,b的最大公约数
long long exGcd(long long a, long long b, long long &x, long long &y)
{
  if(b == 0)
  {
    x = 1;
    y = 0;
    return a;
  }
  long long r = exGcd(b, a % b, x, y);
  long long t = x;
  x = y;
  y = t - a / b * y;
  return r;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  long long a,b,m,n,L,x,y,s,t;

  scanf("%lld%lld%lld%lld%lld",&s,&t,&m,&n,&L);

  if(m==n)
  {
    printf("Impossible\n");
    exit(0);
  }
  a = L ;
  b = m - n ;
  long long ans = t - s ;
  if ( b < 0 )
    b = n - m , ans = s - t ;
  long long d=exGcd(a,b,x,y);

  if(ans%d)
    printf("Impossible\n");
  else
  {
    long long tmp = L/d;
    ans = (ans/d * y)%tmp; //求出答案，因答案要求最小，故还得对答案的“周期”取余
    if(ans<0)
      ans+=tmp;
    printf("%lld\n",ans);
  }

  return 0;
}
