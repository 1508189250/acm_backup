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

int cards[MAX],temp[MAX];

int func(const int &p,const int &c,const int &n)
{
	for(int i=0;i<c;++i)
		cards[i]=temp[i+p];
	for(int i=0;i<p;++i)
		cards[i+c]=temp[i];
	memcpy(temp,cards,sizeof(cards));
	return cards[0];
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,r;
	int a,b,ans;
	
	while(scanf("%d%d",&n,&r) &&(n||r))
	{
		for(int i=0;i<n;++i)
			cards[i]=n-i;
		memcpy(temp,cards,sizeof(cards));

		while(r--)
		{
			scanf("%d%d",&a,&b);
			ans=func(a-1,b,n);
		}
		printf("%d\n",ans);
	}

  return 0;
}
