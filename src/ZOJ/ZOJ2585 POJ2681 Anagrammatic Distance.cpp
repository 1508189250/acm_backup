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
#define MAX 100010
using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
	char str[100];
	int sum[128];
	int ncases;
	scanf("%d",&ncases);
	getchar();
	for(int nc=1;nc<=ncases;++nc)
	{
		memset(sum,0,sizeof(sum));
		gets(str);
		for(int i=0;str[i];++i)
			++sum[str[i]];

		gets(str);
		for(int i=0;str[i];++i)
			--sum[str[i]];

		int ans=0;
		for(int i=0;i<128;++i)
			ans+=abs(sum[i]);
		printf("Case #%d:  %d\n",nc,ans);
	}

  return 0;
}
