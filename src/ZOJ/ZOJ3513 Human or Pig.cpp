/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-12 19:26
 # Filename: ZOJ3513 Human or Pig.cpp
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

const int kMAX=1<<16;
char grid_[kMAX];
int n,m;

char& grid(const int &x,const int &y)
{
	return grid_[x*m+y];
}

char Get(const int &x,const int &y)
{
	char &ret = grid(x,y);
	if(ret!='?')
		return ret;
	else
	{
		ret='P';
		for(int k=1;x>k*y;++k)
			if(Get(x-k*y,y) == 'P')
			{
				ret='H';
				break;
			}
		for(int k=1;y>k*x;++k)
			if(Get(x,y-k*x) == 'P')
			{
				ret='H';
				break;
			}
	}
	return ret;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int cases=1;

  while(~scanf("%d%d",&n,&m) )
  {
    ++n;
    ++m;
    printf("Case #%d:\n",cases++);
    memset(grid_,'?',sizeof(grid_));

		for(int i=1;i<n;++i)
		{
			for(int j=1;j<m;++j)
				putchar(Get(i,j));
			puts("");
		}
  }

  return 0;
}
