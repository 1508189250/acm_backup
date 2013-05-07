/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-13 16:07
 # Filename: acm.cpp
 # Description : 
 ******************************************************************************/
#ifdef _MSC_VER
// #define DEBUG
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

const int kMAX=200010;
const double kEPS=10E-6;

#define lowbit(x) (x&(-x))
using namespace std;

int c[kMAX],num[kMAX];
int lsmall[kMAX],rsmall[kMAX],lbig[kMAX],rbig[kMAX];
int n;

int getsum(int x)
{
  int sum=0;
  for(;x>0;x-=lowbit(x))
      sum+=c[x];
  return sum;
}

void updata(int x,int y)
{
  for(;x<kMAX;x+=lowbit(x))
      c[x]+=y;
}


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  scanf("%d",&ncase);

  while(~scanf("%d",&n) && n)
  {
    memset(c,0,sizeof(c));
		memset(lsmall,0,sizeof(lsmall));
		memset(lbig,0,sizeof(lbig));
		memset(rsmall,0,sizeof(rsmall));
		memset(rbig,0,sizeof(rbig));

		for(int i=0;i<n;++i)
		{
			scanf("%d",&num[i]);
			lsmall[i]=getsum(num[i]);
			lbig[i]=i-lsmall[i];
			updata(num[i],1);
		}

    memset(c,0,sizeof(c));
		for(int i=n-1;i>=0;--i)
		{
			rsmall[i]=getsum(num[i]);
			rbig[i]=n-i-1-rsmall[i];
			updata(num[i],1);
		}

    __int64 ans=0;
		for(int i=0;i<n;++i)
			ans+=(lsmall[i]*rbig[i]+lbig[i]*rsmall[i]);
		printf("%I64d\n",ans);
  }

  return 0;
}

