// ZOJ3166 Lazy Tourist.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"



#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory.h>
#include <limits>
#include <assert.h>
#include <ctype.h>

#define INF 1<<30

using namespace std; 

int main(void)
{
	int n,c,m;
	int a,b,len;
	int hotels[110];
	int mat[110][110];

	while(scanf("%d %d",&n,&c) !=EOF)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				mat[i][j]=INF;
// 			mat[i][i]=0;
		}

		for(int i=0;i<c;++i)
			scanf("%d",&hotels[i]);

		scanf("%d",&m);

		for(int i=0;i<m;++i)
		{
			scanf("%d %d %d",&a,&b,&len);
			mat[a][b]/*=mat[b][a]*/=len;
		}

		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					if(mat[i][k]<INF &&mat[k][j]<INF && mat[i][j]>mat[i][k]+mat[k][j])
						mat[i][j]=mat[i][k]+mat[k][j];

		int minlen=INF;
		int index;
		for(int i=0;i<c;++i)
		{
			if(minlen>mat[hotels[i]][hotels[i]])
			{
				minlen=mat[hotels[i]][hotels[i]];
				index=hotels[i];
			}
		}

		if(minlen<INF)
			printf("%d\n",index);
		else
			printf("I will nerver go to that city!\n");
	}

	return 0;
}
