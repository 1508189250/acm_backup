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

char map[15][15],used[15][15];
int diff[]= {0,1,0,-1,1,0,-1,0};  ;
int n,m,Time,dx,dy,t;
bool ans;

void dfs(int x,int y)
{
	if(ans)
		return;
	int a,b,i;
	if(map[x][y]=='D' && t==Time)
	{
		ans=true;
		return;
	}

	int d=abs(x-dx)+abs(y-dy);
	if(d%2!=(Time-t)%2 || d+t>Time)
		return;
	else
	{
		++t;
		used[x][y]=1;
		for(i=0;i<8 && !ans;i+=2)
		{
			a=x+diff[i];
			b=y+diff[i+1];
			if(a>=0 && a<n && b>=0 && b<m && !used[a][b] &&map[a][b]!='X')
			{
				dfs(a,b);
			}
		}
		used[x][y]=0;
		--t;
	}
}


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int x,y,wall;
	while(scanf("%d%d%d",&n,&m,&Time) && (m||n||Time))
	{
		wall=0;
		getchar();
		for(int i=0;i<n;++i)
		{
			for (int j=0;j<m;++j)
			{
				scanf("%c",&map[i][j]);
				if (map[i][j]=='S')
				{
					x=i;
					y=j;
				} 
				else if (map[i][j]=='D')
				{
					dx=i;
					dy=j;
				}
				else if(map[i][j]=='X')
					++wall;
			}
			getchar();
		}
		if( n*m-wall-1 < Time || abs(x-dx)+abs(y-dy)>Time)  
		{  
			printf("NO\n");  
			continue;  
		}  
		t=0;
		ans = false;
		memset(used,0,sizeof(used));
// 		used[x][y]=1;
		dfs(x,y);
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
