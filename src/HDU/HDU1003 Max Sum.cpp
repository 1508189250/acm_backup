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

const int kMAX=100100;
const double kEPS=10E-6;

int num[kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
  getchar();

  while(~scanf("%d",&n) && n)
  {
		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);

		int total_end=0,total_len=0;
		int now_end=0,now_len=-1;
		int total=-1,now=0;

		for(int i=0;i<n;++i)
		{
			if(now<0)
			{
				now=0;
				now_len=-1;
			}

			now+=num[i];
			now_end=i;
			++now_len;

			if(now>total)
			{
				total=now;
				total_len=now_len;
				total_end=now_end;
			}
		}

    if(ncase>1)
      printf("\n");
    printf("Case %d:\n",ncase++);

		if(total<0)
		{
			printf("0 %d %d\n",1,n);
		}
		else
			printf("%d %d %d\n",total,1+total_end-total_len,1+total_end);
  }

  return 0;
}

