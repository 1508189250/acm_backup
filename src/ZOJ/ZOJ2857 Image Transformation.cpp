// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>

#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <ctype.h>
using namespace std;

int map[120][120];
int n,m;

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	int ncases=0;
	int temp;
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		printf("Case %d:\n",++ncases);
		memset(map,0,sizeof(map));
		for(int k=0;k<3;++k)
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
				{
					scanf("%d",&temp);
					map[i][j]+=temp;
				}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				if(j>0)
					printf(",");
				printf("%d",map[i][j]/3);
			}
			printf("\n");
		}
	}

	return 0;
}
