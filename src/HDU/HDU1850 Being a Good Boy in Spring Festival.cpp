/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-06-13 16:18
 # Filename: HDU1850 Being a Good Boy in Spring Festival.cpp
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

int num[kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,ncase=1;
//   scanf("%d",&ncase);

  while(~scanf("%d",&n) && n)
  {
		int tmp=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&num[i]);
			tmp^=num[i];
		}
		int ans=0;
		if(tmp)
		{
			for(int i=0;i<n;++i)
			{
				int x=tmp^num[i];
				if(x<num[i])
					++ans;
			}
		}
		printf("%d\n",ans);
  }

  return 0;
}

