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
#include <map>
using namespace std;

struct point{int x,y;};
point array[10000];

bool inline cmp(const point &lhs,const point &rhs)
{
	if(lhs.y==rhs.y)
		return lhs.x<rhs.x;
	else
		return lhs.y<rhs.y;
}

bool inline cmp1(const point &lhs,const point &rhs)
{
	if(lhs.x==rhs.x)
		return lhs.y<rhs.y;
	else
		return lhs.x<rhs.x;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n;

	while(~scanf("%d",&n)&&n)
	{
		int sum=0;
		for(int i=0;i<n;++i)
			scanf("%d%d",&array[i].x,&array[i].y);
		
		sort(array,array+n,cmp);
		for(int i=0;i<n;i+=2)
			sum+=array[i+1].x-array[i].x;
		sort(array,array+n,cmp1);
		for(int i=0;i<n;i+=2)
			sum+=array[i+1].y-array[i].y;

		printf("The length of the fence will be %d units.\n",sum);
	}

  return 0;
}
