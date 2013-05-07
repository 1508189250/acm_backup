// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>
#include <assert.h>
#include <ctype.h>

#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,x,y,z,ncases;
	scanf("%d",&ncases);
	while(ncases--)
	{
		scanf("%d %d %d %d",&n,&x,&y,&z);
		int temp=x*1000+y*100+z*10;
		int ans=0;
		if (n==0)
			goto end;
		int i,j;
		for(i=9;i>0;--i)
			for(j=9;j>=0;--j)
				if((temp+i*10000+j)%n==0)
				{
					ans=(temp+i*10000+j)/n;
					goto end;
				}
end:
		if(ans==0)
			printf("0\n");
		else
			printf("%d %d %d\n",i,j,ans);
	}

	return 0;
}
