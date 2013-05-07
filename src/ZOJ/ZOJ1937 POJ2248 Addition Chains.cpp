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
using namespace std;
int a[101],f[101];
int n,cns,minDeep;
bool done;

void dfs(int k)
{
	int i,j;
	if(a[k-1]>n ) return;		//如果最后的数据比n大，减掉
	if(a[k-1]==n&&k<minDeep)		//当我们找到一个可行解，并且可行解的长度少于最短长度的时候，更新之
	{
		for(j=0;j<k;++j)
			f[j]=a[j];
		minDeep=k;
		return;
	}
	for(i=k-1;i>=0;--i)
	{
		if(k<minDeep)		//只要现在的长度少于最短长度，从后往前检索之
		{
			a[k]=a[k-1]+a[i];
			dfs(k+1);
		}
	}
	return;
}

int main()
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int i;

	while(scanf("%d",&n)&&n)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		a[0]=1;
		cns=0;minDeep=99999;
		dfs(1);
		for(i=0;i<minDeep;++i)
		{
			printf("%d",f[i]);
			if(i<minDeep-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}