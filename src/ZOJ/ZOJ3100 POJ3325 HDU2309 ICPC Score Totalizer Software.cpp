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
	int temp;

	while(scanf("%d",&n)&&n)
	{
		int max_score=INT_MIN,min_score=INT_MAX;
		long long ans=0ll;

		for(int i=0;i<n;++i)
		{
			scanf("%d",&temp);
			max_score=max(max_score,temp);
			min_score=min(min_score,temp);
			ans+=temp;
		}
		printf("%d\n",(ans-max_score-min_score)/(n-2));
	}

  return 0;
}
