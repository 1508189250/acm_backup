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
	long long m;
  scanf("%d",&ncase);

	while(ncase--)
  {
		scanf("%d%lld",&n,&m);
    num[0]=0;
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);
		int sum=0,ans=INT_MAX;
    int beg=0,end=0;
		for(;end<n || sum>= m;)
		{
			if(sum>=m)
			{
				sum-=num[beg++];
				ans=min(ans,end-beg+1);
			}
			else
				sum+=num[end++];
		}
    if(beg==0)
      printf("0\n");
    else
  		printf("%d\n",ans);
  }

  return 0;
}
