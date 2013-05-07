/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-07-16 19:30
 # Filename: ZOJ3278 8G Island.cpp
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

const int kMAX=100010;
int boys[kMAX],girls[kMAX];

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n,m,key;

  while(~scanf("%d%d%d",&n,&m,&key) )
  {
    key;
		for(int i=1;i<=n;++i)
			scanf("%d",&boys[i]);
		for(int i=1;i<=m;++i)
			scanf("%d",&girls[i]);

		sort(boys+1,boys+1+n,greater<long long>());
		sort(girls+1,girls+1+m,greater<long long>());

		long long left=1ll*boys[n]*girls[m],right=1ll*boys[1]*girls[1];
    long long ans=left;

		while(left<=right)
		{
			long long mid=left+((right-left)>>1);
			int sum=0;
			
			for(int i=1;i<=n;++i)
			{
				int l=1,r=m,t=0;
				while(l<=r)
				{
					int k=l+((r-l)>>1);
					if(1ll*boys[i]*girls[k]>=mid)
          {
            t=k;
						l=k+1;
          }
					else
						r=k-1;
				}
				sum+=t;
			}

			if(sum>=key)
      {
        ans=mid;
				left=mid+1;
      }
			else
				right=mid-1;
		}

		printf("%lld\n",ans);
  }

  return 0;
}