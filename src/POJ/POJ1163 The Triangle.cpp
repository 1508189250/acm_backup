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
#define MAX 110
using namespace std;

int num[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<=i;++j)
				scanf("%d",&num[i][j]);

		for(int i=n-2;i>=0;--i)
			for(int j=0;j<=i;++j)
				num[i][j]+=max(num[i+1][j],num[i+1][j+1]);

		printf("%d\n",num[0][0]);
	}

  return 0;
}
