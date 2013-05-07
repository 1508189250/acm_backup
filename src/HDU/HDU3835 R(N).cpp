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
#include <set>
using namespace std;

int squrt[100000];

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int cnt=0;
	for(cnt=0;cnt*cnt<1000000010;++cnt)
		squrt[cnt]=cnt*cnt;

	int n;
	while(~scanf("%d",&n))
	{
		int ans=0;
		for(int i=0;i<sqrt(1.0*n);++i)
			if(binary_search(squrt,squrt+cnt,n-i*i))
				++ans;
		printf("%d\n",ans*4);
	}

  return 0;
}
