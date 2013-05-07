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
#define MAX 20
using namespace std;

int num[MAX][MAX];
int m,n;

int dfs(const int &x,const int &sum_a,const int &sum_b)
{
	if(x==m)
		return abs(sum_a-sum_b);

	int temp_a=num[x][0],temp_b=num[x][1];
	for(int i=2;i<n;++i)
		temp_b+=num[x][i];

	int ans=INT_MAX;
	for(int i=0;i<n-1;++i)
	{
		ans=min(ans,dfs(x+1,sum_a+temp_a,sum_b+temp_b));
		temp_a+=num[x][i+1];
		temp_b-=num[x][i+1];
	}
	return ans;
}


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int diff;

	while(~scanf("%d%d",&m,&n))
	{
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				scanf("%d",&num[i][j]);

		scanf("%d",&diff);
		int ans=dfs(0,0,0);

		if(ans<=diff)
			printf("%d\n",ans);
		else
			printf("You'd better buy another one!\n");

	}
	

  return 0;
}
