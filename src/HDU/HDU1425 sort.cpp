/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-13 16:07
 # Filename: acm.cpp
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

const int kMAX=1000010;


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
	int tmp;

  while(~scanf("%d%d",&n,&m) && n)
  {
		bool hash[kMAX]={false};
		for(int i=0;i<n;++i)
		{
			scanf("%d",&tmp);
			hash[tmp+500000]=true;
		}
		int cnt=0,idx=kMAX-1;
		while(cnt!=m && idx)
		{
			if(hash[idx])
			{
				printf("%d%c",idx-500000,cnt==(m-1)?'\n':' ');
				++cnt;
			}
			--idx;
		}
  }

  return 0;
}

