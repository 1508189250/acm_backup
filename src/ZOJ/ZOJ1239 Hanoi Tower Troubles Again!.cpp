// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <set>
#define MAX 100000
using namespace std;

set<int> squrt;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int n,peg[55],num[55],len;
	for(int i=1;i<MAX;++i)
		squrt.insert(i*i);

	memset(peg,0,sizeof(peg));
	peg[0]=1;
	num[0]=1;
	n=2;
	len=1;
	int flag=1;
	while(flag)
	{
		flag=0;
		for(int i=0;i<len;++i)
			if(squrt.find(peg[i]+n)!=squrt.end())
			{
				peg[i]=n++;
				flag=1;
				break;
			}
		if(flag==0)
			if(len<55)
			{
				num[len]=n-1;
				peg[len++]=n++;
				flag=1;
			}
			else
				break;
	}

	int ncases;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d",&n);
		printf("%d\n",num[n]);
	}

	return 0;
}
