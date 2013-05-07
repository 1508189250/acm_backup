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
int map[21][21][21];

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	for(int i=0;i<=20;++i)
		for(int j=0;j<=20;++j)
			map[i][j][0]=map[i][0][j]=map[0][i][j]=1;
	for(int a=1;a<=20;++a)
		for(int b=1;b<=20;++b)
			for(int c=1;c<=20;++c)
				if(a<b && b<c)
					map[a][b][c]=map[a][b][c-1]+map[a][b-1][c-1]-map[a][b-1][c];
				else
					map[a][b][c]=map[a-1][b][c]+map[a-1][b-1][c]+map[a-1][b][c-1]-map[a-1][b-1][c-1];

	int x,y,z;
	while(scanf("%d %d %d",&x,&y,&z)&&(x!=-1 || y!=-1 || z!=-1))
	{
		int ans;
		if(x<=0 || y<= 0 || z<=0)
			ans=1;
		else if(x>20 || y>20 ||z>20)
			ans=map[20][20][20];
		else
			ans=map[x][y][z];
		printf("w(%d, %d, %d) = %d\n",x,y,z,ans);

	}


	return 0;
}
