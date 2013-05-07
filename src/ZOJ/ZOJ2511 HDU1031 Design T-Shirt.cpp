/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-12-23 18:37
 # Filename: ZOJ2511 HDU1031 Design T-Shirt.cpp
 # Description : 
 ******************************************************************************/
// #include "stdafx.h"
// #define DEBUG

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
#include <map>
#define MAX 10010
using namespace std;

pair<int,double> pool[MAX];

bool cmp(const pair<int,double> &lhs,const pair<int,double> &rhs)
{
	if(lhs.second == rhs.second)
		return lhs.first<rhs.first;
	return lhs.second > rhs.second;
}

int main(void)
{
#ifdef DEBUG  
  freopen("C:/Users/neo/Desktop/stdin.txt","r",stdin);
  freopen("C:/Users/neo/Desktop/stdout.txt","w",stdout); 
#endif  

	int n,m,k;
	double lf_temp;
	int result[MAX];

	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(int i=1;i<=m;++i)
		{
			pool[i].first=i;
			pool[i].second=0.0;
		}
		for(int i=0;i<n;++i)
			for(int j=1;j<=m;++j)
			{
				scanf("%lf",&lf_temp);
				pool[j].second+=lf_temp;
			}
		sort(pool+1,pool+1+m,cmp);
		for(int i=1;i<=k;++i)
			result[i-1]=pool[i].first;
		sort(result,result+k);
		for(int i=k-1;i>=0;--i)
			printf("%d%c",result[i],i==0?'\n':' ');
	}

  return 0;
}
