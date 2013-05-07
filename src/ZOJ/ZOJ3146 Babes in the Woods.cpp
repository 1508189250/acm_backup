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
#include <stack>
#define MAX 40
using namespace std;

int map[40][40],dist[MAX][MAX],in_stk[MAX][MAX];
int total,n,m;
int beg_x,beg_y,end_x,end_y;
int diff[]={-1,0,1,0,0,-1,0,1};

void spfa()
{
	memset(in_stk,0,sizeof(in_stk));
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			dist[i][j]=INT_MAX;
	dist[beg_x][beg_y]=0;
	stack<int> x_stk,y_stk;
	x_stk.push(beg_x);
	y_stk.push(beg_y);
	in_stk[beg_x][beg_y]=1;
	while(!x_stk.empty())
	{
		int x=x_stk.top(),y=y_stk.top();
		x_stk.pop();
		y_stk.pop();
		in_stk[x][y]=0;
		for(int i=0;i<8;i+=2)
		{
			int a=x+diff[i]*map[x][y];
			int b=y+diff[i+1]*map[x][y];
			if(a<0)
				a=0;
			if(b<0)
				b=0;
			if(a>=n)
				a=n-1;
			if(b>=m)
				b=m-1;
			if(dist[a][b]-dist[x][y]>map[x][y])
			{
				dist[a][b]=dist[x][y]+map[x][y];
				if(!in_stk[a][b])
				{
					in_stk[a][b]=1;
					x_stk.push(a);
					y_stk.push(b);
				}
			}
		}
	}
}

int main(void)
{
#ifdef DEBUG  
	freopen("../stdin.txt","r",stdin);
	freopen("../stdout.txt","w",stdout); 
#endif  

	while(~scanf("%d%d%d%d",&n,&m,&beg_x,&beg_y))
	{
		--beg_x;--beg_y;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				scanf("%d",&map[i][j]);
				if(!map[i][j])
				{
					end_x=i;
					end_y=j;
				}
			}
			spfa();
			if(dist[end_x][end_y]!=INT_MAX)
				printf("%d\n",dist[end_x][end_y]);
			else
				printf("No solution\n");

	}

	return 0;
}
