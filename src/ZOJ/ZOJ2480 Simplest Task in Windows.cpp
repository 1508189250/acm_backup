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
#define MAX 1010

using namespace std;

int map[MAX][MAX];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n,m;
	int a,b,c,d;

	while(scanf("%d",&n) &&n)
	{
		memset(map,-1,sizeof(map));
		for(int i=0;i<n;++i)
		{
			scanf("%d %d %d %d",&a,&c,&b,&d);
			for(int j=a;j<=b;++j)
				for(int k=c;k<=d;++k)
					//if(map[j][k]==-1)
						map[j][k]=i;
		}
		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
			scanf("%d %d",&a,&b);
			printf("%d\n",map[a][b]);
		}
	}

	return 0;
}
