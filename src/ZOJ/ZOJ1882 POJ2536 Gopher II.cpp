#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>
#define MAX 220
using namespace std;
typedef struct COOR{
	double x,y;
}COOR;
COOR g[MAX/2],h[MAX/2];
int map[MAX][MAX];
int used[MAX];
int match[MAX];
double Distance(int i,int k)
{
	double x = g[i].x - h[k].x;
	double y = g[i].y - h[k].y;
	return sqrt( x*x + y*y );
}
int Augement(int n,int x) // n是图节点数的上界 
{
	int i;
	for(i=1; i<=n; i++)      // 寻找增广路 
		if( !used[i] && map[x][i] )
		{
			used[i] = 1;
			if( match[i] == 0 || Augement(n,match[i]) ) // 如果被标记了，就找被标记点是否可以增广 
			{
				match[i] = x;
				return 1;
			}
		}
		return 0;
}
int Hungary(int n)
{
	int i,sum = 0;
	memset(match,0,sizeof(match));
	for(i=1; i<=n; i++)  // 对每个点进行增广 
	{
		memset(used,0,sizeof(used));
		if( Augement(n,i) )
			sum++;
	}
	return sum;
}
int main()
{
	int n,m,s,v,i,k,ans;
// 	double len;
	while( ~scanf("%d%d%d%d",&n,&m,&s,&v) )
	{
		double len=s*v;
		memset(map,0,sizeof(map));
		for(i=1; i<=n; i++)
			scanf("%lf%lf",&g[i].x,&g[i].y);
		for(i=1; i<=m; i++)
			scanf("%lf%lf",&h[i].x,&h[i].y);
		for(i=1; i<=n; i++)
			for(k=1; k<=m; k++)
			{
				if( Distance(i,k) <  len)
					map[i][k+n] = 1;
			}
			ans = Hungary(m+n);
			printf("%d\n",n-ans);
	}
	return 0;
}
