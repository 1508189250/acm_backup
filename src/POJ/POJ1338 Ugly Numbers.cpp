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
#define MAX 1510
using namespace std;

long long ans[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  long long n;
  int i1=0,i2=0,i3=0;
  ans[0]=1;
  for(long long i=1;i<MAX;++i)
  {	
    long long t1=ans[i1]*2;
    long long t2=ans[i2]*3;
    long long t3=ans[i3]*5;
    ans[i]=min(t1,min(t2,t3));
    if(ans[i]==t1) ++i1;
    if(ans[i]==t2) ++i2;
    if(ans[i]==t3) ++i3;
  }

  while(cin>>n && n)
  {
    cout<<ans[n-1]<<endl;
  }

  return 0;
}
