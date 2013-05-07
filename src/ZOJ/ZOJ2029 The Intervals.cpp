/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-04 19:33
 # Filename: ZOJ2029 The Intervals.cpp
 # Description : 
 ******************************************************************************/
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
using namespace std;

const int kMAX=10010;
const double kEPS=10E-6;
int n,m,num[kMAX];

int BinSearch(const int &x)
{
	int l=0,r=n-1;
	if(x<num[l] || x>=num[r])
		return -1;

	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(x<num[mid])
			r=mid;
		else
			l=mid;
	}
	return l;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int tmp;

  while(~scanf("%d%d",&n,&m) )
  {
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);
    sort(num,num+n);

		while(m--)
		{
			scanf("%d",&tmp);
			int ans=BinSearch(tmp);
			if(ans>-1)
				printf("[%d,%d)\n",num[ans],num[ans+1]);
			else
				printf("no such interval\n");
		}
    puts("");
  }

  return 0;
}

