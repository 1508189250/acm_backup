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
#include <numeric>
#include <functional>
#include <ctype.h>

using namespace std;

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n;
	while(scanf("%d",&n) && n!=-1)
	{
		int pre=0,now;
		int speed;
		long long sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",&speed,&now);
			sum+=speed*(now-pre);
			pre=now;
		}
		printf("%lld miles\n",sum);

	}

  return 0;
}
