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

#define SET_ZERO(array) memset(array,'\0',sizeof(array))
#define MAX 1000010

using namespace std;

int array[MAX],ans[MAX],total[MAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  //   scanf("%d",&ncase);

	memset(array,0,sizeof(array));
  for (int i=1;i<MAX;++i)
		for(int j=1;j*i<MAX;++j)
			++array[i*j];

	memset(ans,0,sizeof(ans));
	memset(total,0,sizeof(total));
	for(int i=1;i<MAX;++i)
	{
		ans[i]=total[array[i]];
		++total[array[i]];
	}

  while(~scanf("%d",&n) && n)
		printf("%d\n",ans[n]);



  return 0;
}
