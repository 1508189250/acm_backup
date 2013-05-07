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

int value[MAX];
int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
  //   scanf("%d",&ncase);

  while(~scanf("%d%d",&n,&m) && n)
  {
    int cnt=1;
    while(n--)
      cnt*=2;
    for(int i=0;i<cnt;++i)
			scanf("%d",&value[i]);
		int maximum=0,minimum=0;
		for(int i=0;i<cnt;++i)
			if(value[i]>value[m])
				++maximum;
		minimum=cnt-maximum;
		int ansb=0;
		while(minimum>1)
		{
			++ansb;
			minimum/=2;
		}
		int ansa=0;
		if(!maximum)
			ansa=ansb;
		printf("%d %d\n",ansa,ansb);
  }

  return 0;
}
