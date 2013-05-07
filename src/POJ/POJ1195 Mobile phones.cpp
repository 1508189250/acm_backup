/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-06 18:29
 # Filename: POJ1195 Mobile phones.cpp
 # Description : 
 ******************************************************************************/
#include "stdafx.h"
#define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#define lowbit(x) (x&(-x))
#define MAX 1030
using namespace std;

int n;
long long c[MAX][MAX];

long long getsum(const int &x,const int &y)
{
	long long sum=0ll;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			sum+=c[i][j];
	return sum;
}

void updata(const int &x,const int &y,const int &val)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			c[i][j]+=val;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int instr;
	int x,y,val,l,b,r,t;

	while(scanf("%d",&instr) && instr!=3)
	{
		if(instr==0)
		{
			scanf("%d",&n);
			memset(c,0,sizeof(c));
		}
		else if(instr==1)
		{
			scanf("%d%d%d",&x,&y,&val);
			updata(x+1,y+1,val);
		}
		else
		{
			scanf("%d%d%d%d",&l,&b,&r,&t);
			long long sum=getsum(r+1,t+1);
			sum-=getsum(l,t+1);
			sum-=getsum(r+1,b);
			sum+=getsum(l,b);
			printf("%lld\n",sum);
		}
	}

	return 0;
}
