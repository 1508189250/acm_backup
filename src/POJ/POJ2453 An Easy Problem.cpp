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

	int n;

	while(scanf("%d",&n) &&n)
	{
		int cnt=0;
		int tmp=0;

		while(1)
		{
			if((1<<tmp & n) && !(1<<(tmp+1) &n))
				break;
			if((1<<tmp & n))
				++cnt;
      ++tmp;
		}

		int mask=INT_MAX<<(tmp+1);
    mask = mask ^ (1<<31);
		int ans=(n & mask) | (1<<(tmp+1));
		for(int i=0;i<cnt;++i)
			ans=ans|(1<<i);

		printf("%d\n",ans);
	}

  return 0;
}
