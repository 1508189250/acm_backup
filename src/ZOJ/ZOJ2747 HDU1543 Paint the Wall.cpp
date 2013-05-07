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
#define MAX 210
using namespace std;

int wall[MAX][MAX];
int area[MAX],x[MAX],y[MAX];
struct REC{int lx,ly,rx,ry,color;}rec[MAX];


int find(const int *array,const int &n,const int &x)
{
	int s=0,e=n-1;
	while(s<=e)
	{
		int mid=(s+e)>>1;
		if(array[mid]==x)
			return mid;
		else if(array[mid]<x)
			s=mid+1;
		else
			e=mid;
	}
}

void func(const int &n,const int &m)
{
	for(int i=0;i<n;++i)
	{
		int lx=find(x,m,rec[i].lx);
		int ly=find(y,m,rec[i].ly);
		int rx=find(x,m,rec[i].rx);
		int ry=find(y,m,rec[i].ry);
		for(int j=lx;j<rx;++j)
			for(int k=ly;k<ry;++k)
				wall[j][k]=rec[i].color;
	}
	for(int i=0;i<m-1;++i)
		for(int j=0;j<m-1;++j)
			if(wall[i][j])
				area[wall[i][j]]+=(x[i+1]-x[i])*(y[j+1]-y[j]);
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int h,w;
	int n,m;
	int ncases=1;

	while(scanf("%d%d",&h,&w)&&(h||w))
	{
		scanf("%d",&n);
		m=0;
		memset(area,0,sizeof(area));
		memset(wall,0,sizeof(wall));
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d%d%d",&rec[i].lx,&rec[i].ly,&rec[i].rx,&rec[i].ry,&rec[i].color);
			x[m]=rec[i].lx;
			y[m++]=rec[i].ly;
			x[m]=rec[i].rx;
			y[m++]=rec[i].ry;
		}
		sort(x,x+m);
		sort(y,y+m);
		func(n,m);
		int ans=0;
    if(ncases>1)
      printf("\n");
    printf("Case %d:\n",ncases++);
		for(int i=0;i<MAX;++i)
			if(area[i])
			{
				printf("%d %d\n",i,area[i]);
				++ans;
			}
		if(ans==1)
			printf("There is 1 color left on the wall.\n");
		else
			printf("There are %d colors left on the wall.\n",ans);
	}

  return 0;
}
