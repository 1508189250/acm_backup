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
#define MAX 1000
using namespace std;

long long ans[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  long long n;
	int ncases=0;
  //   scanf("%d",&ncase);

  while(~scanf("%lld",&n) && n)
  {
		if(ncases++)
			printf("\n");
		long long cnt=0ll;
		ans[cnt++]=1ll;
		long long total=1ll,now=3ll;
		while(total+now<=n)
		{
			ans[cnt++]=now;
			total+=now;
      if(n-total-now*2-1<0)   //·ÀÖ¹ÉÏÒç
        break;      
			now*=2;
			++now;
		}
    if(total<n)
      ans[cnt-1]+=n-total;
		printf("%lld\n",cnt);
		for(long long i=cnt-1;i>=0ll;--i)
			printf("%lld%c",ans[i],(i==0)?'\n':' ');
  }

  return 0;
}
