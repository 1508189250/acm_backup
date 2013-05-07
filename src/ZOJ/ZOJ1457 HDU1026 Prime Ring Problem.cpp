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
#define MAX 21
using namespace std;

int prime[MAX*2],num[MAX],visit[MAX];
int n;

void dfs(const int &deep)
{
	if(deep==n+1 )
		if(!prime[num[deep-1]+1])
		{
			printf("1");
			for(int i=2;i<=n;++i)
				printf(" %d",num[i]);
			printf("\n");
			return;
		}
		else
			return;
	else
	{
		for(int i=num[deep-1]%2+1 ; i<=n ; i+=2)
			if(!visit[i]  && !prime[num[deep-1]+i])
			{
				visit[i]=1;
				num[deep]=i;
				dfs(deep+1);
				visit[i]=0;
			}
		return;
	}
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	memset(prime,0,sizeof(prime));
	for(int i=2;i<=sqrt(2.0*MAX);++i)
		if(!prime[i])
			for(int j=2;j*i<2*MAX;++j)
				prime[i*j]=1;

	int ncases=1;
	num[1]=1;
	int flag=1;
	while(~scanf("%d",&n))
	{
		printf("Case %d:\n",ncases++);
		memset(visit,0,sizeof(visit));
		visit[1]=1;
		if(n%2)	//如果n为奇数，必不可能
			goto end;
		dfs(2);
end:
		printf("\n");
	}

	return 0;
}
