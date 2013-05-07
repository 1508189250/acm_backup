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

  int s,d;

  while(~scanf("%d%d",&s,&d))
  {
		int ans=-1;
		for(int i=1;i<=4;++i)
			if(i*d>s*(5-i))
			{
				int mon=i*2+(i==4);
				ans=max(ans,(12-mon)*s-mon*d);
			}
		if(ans>0)
			printf("%d\n",ans);
		else
			printf("Deficit\n");
  }

  return 0;
}
