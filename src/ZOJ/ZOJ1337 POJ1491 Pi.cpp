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
#define MAX 100
using namespace std;

int num[MAX];

bool check(const int &lhs,const int &rhs)
{
	for(int i=2;i<=lhs;++i)
		if(rhs%i==0 && lhs%i==0)
			return false;
	return true;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  //   scanf("%d",&ncase);

  while(~scanf("%d",&n) && n)
  {
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);
		sort(num,num+n);
		int cnt=0;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if(check(num[i],num[j]))
					++cnt;
		if(!cnt)
			printf("No estimate for this data set.\n");
		else
		{
			double ans=cnt*1.0;
			ans/=(n*(n-1)/2);
			printf("%.6lf\n",sqrt(6/ans));
		}
  }

  return 0;
}
