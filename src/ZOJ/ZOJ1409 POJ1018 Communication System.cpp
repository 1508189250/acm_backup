/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-03-12 20:52
 # Filename: ZOJ1409 POJ1018 Communication System.cpp
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
#include <float.h>
#include <set>
#define MAX 10010
using namespace std;

int dev[MAX][2], total[MAX];


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases,n,m;
	scanf("%d",&ncases);
	total[0]=0;

	while(ncases--)
	{
		scanf("%d",&n);
    set<int> band;
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&m);
			if(i>0)
				total[i]=total[i-1]+m;
			else
				total[i]=m;
			
			for(int j=total[i-1];j<total[i];++j)
      {
				scanf("%d%d",&dev[j][0], &dev[j][1]);
        band.insert(dev[j][0]);
      }
		}

    double ans=0.0;
    for(set<int>::reverse_iterator i=band.rbegin();i!=band.rend();++i)
    {
      double minband=(*i)*1.0;
      int price=0;
      for(int j=1;j<=n;++j)
      {
        double min=1000000;   //这里用DBL_MAX过不了...FUCK
        for (int k=total[j-1];k<total[j];++k)
        {
          if(dev[k][0]>=minband && dev[k][1]<min)
            min=dev[k][1];
        }
        price+=min;
      }
      ans = max(ans,minband/price);
    }

		printf("%.3lf\n",ans);
	}


  return 0;
}
