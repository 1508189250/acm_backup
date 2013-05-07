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
#define MAX 1000010
using namespace std;

long long ans[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	long long n,p1,p2,p3;
	int i1=0,i2=0,i3=0;
// 	scanf("%lld%lld%lld%lld",&p1,&p2,&p3,&n);
  while(cin>>p1>>p2>>p3>>n)
  {
	ans[0]=1;
	for(long long i=1;i<=n;++i)
	{	
		long long t1=ans[i1]*p1;
		long long t2=ans[i2]*p2;
		long long t3=ans[i3]*p3;
		ans[i]=min(t1,min(t2,t3));
		if(ans[i]==t1) ++i1;
		if(ans[i]==t2) ++i2;
		if(ans[i]==t3) ++i3;
	}

// 	printf("%ld\n",ans[n]);
  cout<<ans[n]<<endl;
  }

  return 0;
}
