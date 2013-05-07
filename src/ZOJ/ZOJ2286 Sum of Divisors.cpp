// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>
#define MAX 1000001
using namespace std;

int num[MAX];

int find(int begin,int end,int x)
{
	int mid=(begin+end)/2;

	if(begin ==end) return end-1;
	if(num[end-1]<=x && num[end]>x)
		return end-1;
	if(num[mid]<=x)
		return find(mid+1,end,x);
	else
		return find(begin,mid,x);
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	for (int i=1;i<MAX;++i)
		num[i]=1;

	for(int i=2;i<=MAX;++i)
		for(int j=2;j*i<MAX;++j)
			num[i*j]+=i;

	sort(num,num+MAX);

	int n;

	while(scanf("%d",&n)!=EOF)
	{
		int ans;
		if(n==1)
			ans=78499;
		else if(n>=3392928)
			ans=1000000;
		else
			ans=find(0,MAX-1,n);
		printf("%d\n",ans);
	}

	return 0;
}
