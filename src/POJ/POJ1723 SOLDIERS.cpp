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
#define MAX 10010
using namespace std;


int x[MAX],y[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n;
  long long sum=0ll;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d %d",&x[i],&y[i]);

	sort(y,y+n);
	sort(x,x+n);
  for(int i=0;i<n;++i)
    x[i]-=i;
  sort(x,x+n);
	for(int i=0;i<n/2;++i)
		sum+=y[n-i-1]-y[i]+x[n-i-1]-x[i];

	printf("%lld",sum);

  return 0;
}
