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

const int kMAX=100100;
const double kEPS=10E-6;

int ans[kMAX],tans[kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,tmp;

  while(~scanf("%d",&n) && n)
  {
		map<int,int> mmap;
		int sum=0;
		while(n--)
		{
			scanf("%d",&tmp);
			mmap[tmp]++;
			sum+=tmp;
		}

		memset(ans,0,sizeof(ans));
		memset(tans,0,sizeof(tans));
		ans[0]=1;

		for(map<int,int>::iterator iter=mmap.begin();iter!=mmap.end();++iter)
		{
			for(int j=0;j<=sum;++j)
				if(ans[j])
        {
					for(int k=0,remain=iter->second+1;k+j<=sum && remain;k+=iter->first,--remain)
          {
						tans[k+j]+=ans[j];
            tans[abs(j-k)]+=ans[j];
          }
        }

			memcpy(ans,tans,sizeof(ans));
			memset(tans,0,sizeof(tans));
		}
		int cnt=0;
		for(int i=1;i<=sum;++i)
			if(!ans[i])
				tans[cnt++]=i;

		printf("%d\n",cnt);
		for(int i=0;i<cnt;++i)
			printf("%d%c",tans[i],i==(cnt-1)?'\n':' ');
  }

  return 0;
}

