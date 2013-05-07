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
#include <map>
using namespace std;

const int kMAX=20010;
const double kEPS=10E-6;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
  long long x,tmp;

  while(~scanf("%d",&n) && n)
  {
		long long ans=0,array[3]={0ll};
		for(int i=0;i<n;++i)
		{
			scanf("%lld",&tmp);
			ans+=tmp/3;
			++array[tmp%3];
		}

		tmp=ans; //½øÎ»
		if(array[2] && tmp)
    {
      x=min(array[2],tmp);
			ans+=x;
      array[2]-=x;
    }
		while(1)
		{
			if(array[1])
			{
				x=min(array[1],tmp/2);
				tmp-=x;
				array[1]-=x;
			}
			else 
			{
				x=tmp/3;
				tmp-=x*2;
			}
			ans+=x;
			if((array[1] &&tmp<2) || (array[1]==0 && tmp<=2))
				break;
		}

		printf("%lld\n",ans);
  }

  return 0;
}

