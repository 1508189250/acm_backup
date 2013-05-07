// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define maxlen 5000
using namespace std;

int alen,blen,clen;
int a[maxlen],b[maxlen],c[maxlen];

void func(int k)
{
	for(int i=0;i<max(alen,blen);++i)
	{
		c[i]+=(k-1)*(a[i]+b[i]);
		if(c[i]>9)
		{
			c[i+1]+=c[i]/10;
			c[i] %=10;
		}
	}
  while(c[clen])
    ++clen;
	while(c[clen-1]>9)
	{
		c[clen]+=c[clen-1]/10;
		c[clen-1]%=10;
		++clen;
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int n,k;

	while(~scanf("%d%d",&n,&k))
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		a[0]=k-1;
		alen=1;
		b[0]=(k-1)*k%10;
		blen=1;
		if((k-1)*k>9)
		{
			b[1]=(k-1)*k/10;
			blen=2;
		}
    clen=blen;
		for(int i=2;i<n;++i)
		{
			func(k);
			memcpy(a,b,sizeof(b));
			memcpy(b,c,sizeof(c));
      memset(c,0,sizeof(c));
			blen=clen;
		}
		bool flag=false;
		for(int i=maxlen-1;i>=0;--i)
			if(flag || b[i])
			{
				flag=true;
				printf("%d",b[i]);
			}
			else if(b[i])
				flag=true;
		printf("\n");
	}

  return 0;
}
