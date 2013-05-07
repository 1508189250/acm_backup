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

int tarray[MAX];
int prime[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	memset(tarray,true, sizeof(tarray));
	for(int i=2;i<MAX;++i)
		if(tarray[i])
			for(int j=2;i*j<MAX;++j)
				tarray[i*j]=false;

	int cnt=0;
	for(int i=2;i<MAX;++i)
		if(tarray[i])
			prime[cnt++]=i;

	int n;
	while(scanf("%d",&n) &&n)
	{
		int ans=0;
		for(int i=0;i<cnt && n>=prime[i];++i)
		{
			int tmp=n;
			for(int j=i;j<MAX;++j)
				if(tmp<prime[j])
					break;
				else
					tmp-=prime[j];
			if(!tmp)
				++ans;
		}
		printf("%d\n",ans);
	}
	

  return 0;
}
