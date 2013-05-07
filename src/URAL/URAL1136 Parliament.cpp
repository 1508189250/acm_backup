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
#define MAX 3010
using namespace std;

int input[MAX],output[MAX];

void func(int *dis,const int *sou,const int &n)
{
	int n_root=sou[n-1];
	dis[n-1]=n_root;
	if(n<=1)
		return;

	int n_count;
	for(int i=0;i<n;++i)
		if(sou[i]>=n_root)
		{
			n_count=i;
			break;
		}
	
	func(dis+(n-n_count-1),sou,n_count);
	func(dis,sou+n_count,n-n_count-1);
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
			scanf("%d",&input[i]);
		func(output,input,n);
		for(int i=0;i<n;++i)
			printf("%d%c",output[i],i==n-1?'\n':' ');
	}

  return 0;
}
