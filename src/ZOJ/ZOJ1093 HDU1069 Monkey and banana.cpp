/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-05 19:54
 # Filename: ZOJ1093 HDU1069 Monkey and banana.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG
// 
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
#define MAX 40*3
using namespace std;

struct BOX{int x,y,z;}box[MAX];

bool inline cmp(const BOX &lhs,const BOX &rhs)
{
	if(lhs.x==rhs.x)
		return lhs.y<rhs.y;
	else
		return lhs.y<rhs.y;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  
	int ncases=1,n;
	int temp[3];

	while(scanf("%d",&n) &&n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d",&temp[0],&temp[1],&temp[2]);
			sort(temp,temp+3);
			box[i*3+0].x=temp[0];
			box[i*3+0].y=temp[1];
			box[i*3+0].z=temp[2];
			box[i*3+1].x=temp[1];
			box[i*3+1].y=temp[2];
			box[i*3+1].z=temp[0];
			box[i*3+2].x=temp[0];
			box[i*3+2].y=temp[2];
			box[i*3+2].z=temp[1];
		}
		sort(box,box+n*3,cmp);
		int ans=0;
		for(int i=0;i<n*3;++i)
		{
			int max_h=0;
			for(int j=i-1;j>=0;--j)
				if(box[i].x>box[j].x && box[i].y>box[j].y)
					max_h=max(max_h,box[j].z);

			box[i].z +=max_h;
			ans = max(ans,box[i].z);
		}
		printf("Case %d: maximum height = %d\n",ncases++,ans);

	}

  return 0;
}
