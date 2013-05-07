/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-17 18:57
 # Filename: POJ2478 Farey Sequence.cpp
 # Description : 
 ******************************************************************************/
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
using namespace std;

const int kMAX=1000010;
const double kEPS=10E-6;
int prime[kMAX]={0},num_prime=0;//num_pirme记录素数个数
bool is_prime[kMAX];

void GetPrime(const int m)
{
  memset(is_prime,true,sizeof(is_prime));
  for(int i=2;i<m;i++)
  {
    if(is_prime[i])
      prime[num_prime++]=i;
    for(int j=0;j<num_prime && i*prime[j]<m;j++)
    {
      is_prime[i*prime[j]]=false;//合数标为1，同时，prime[j]是合数i*prime[j]的最小素因子
      if(!(i%prime[j]))//即比一个合数大的质数和该合数的乘积可用一个更大的合数和比其小的质数相乘得到
        break;
    }
  }	
}

long long dp[kMAX]={0ll};
void Solve(void)
{
	GetPrime(kMAX);
	for(int i=2;i<kMAX;++i)
	{
		if(is_prime[i])
			dp[i]=i-1;
		else
		{
			for(int j=0;j<num_prime;++j)
				if(i%prime[j]==0)
				{
					if((i/prime[j])%prime[j]==0)
						dp[i]=dp[i/prime[j]]*prime[j];
					else
						dp[i]=dp[i/prime[j]]*(prime[j]-1);
					break;
				}
		}
	}
	for(int i=3;i<kMAX;++i)
		dp[i]+=dp[i-1];
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;

  Solve();
  while(~scanf("%d",&n) && n)
  {
		printf("%lld\n",dp[n]);
  }

  return 0;
}

