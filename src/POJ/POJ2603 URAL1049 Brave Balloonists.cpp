#include "stdafx.h"
#define DEBUG

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
#include <ctype.h>
#include <map>
#define MAX 10000
using namespace std;
int num[10];
int notPrime[MAX],prime[MAX];
map<int,int> g_map;
int n_prime_count;

void func(int x)
{
	int ind=0;
	while(x!=1)
	{
		if(! (x%prime[ind]))
		{
			++g_map[prime[ind]];
			x /=prime[ind];
		}
		else
			++ind;
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	memset(notPrime,0,sizeof(notPrime));
	for(int i=2;i<MAX;++i)
		if(!notPrime[i])
			for(int j=2;j*i<MAX;++j)
				notPrime[i*j]=1;
	n_prime_count = 0;
	for(int i=2;i<MAX;++i)
		if(!notPrime[i])
			prime[n_prime_count++]=i;

	for(int i=0;i<10;++i)
		scanf("%d",&num[i]);

	g_map.clear();
	for(int i=0;i<10;++i)
		func(num[i]);

	int ans=1;
	for(map<int,int>::const_iterator iter=g_map.begin();iter!=g_map.end();++iter)
  {
		ans*=(iter->second+1);
    ans %=10;
  }
	
	printf("%d\n",ans);

  return 0;
}
