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

#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int num[10][100];

int func(const int &x, const int &total)
{
	if(x*6<total || total<=0)
		return 0;
	if(x==1 && total<=6)
		return 1;
	int sum=0;
	for(int i=1;i<=6;++i)
		sum+=func(x-1,total-i);
	return sum;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	memset(num,0,sizeof(num));
	for(int i=1;i<=8;++i)
		for(int j=i;j<=i*6;++j)
			num[i][j]=func(i,j) ;

	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int sum=0;
		double ans=0.0;
		double temp;
		if (n<=1)
			goto end;
		temp=pow(6.0,m+n);
		for(int i=m;i<=m*6;++i)
		{
			sum=0;
			for(int j=i+1;j<=n*6;++j)
				sum+=num[n][j];
			ans += sum*1.0*num[m][i]/pow(6.0,m);
		}
end:
		printf("%.16lf\n",ans/pow(6.0,n));
	}

	return 0;
}
