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
#include <vector>
using namespace std;

const int kMAX=10010;
const double kEPS=10E-6;

struct NODE
{
	int price,var;
	bool inline operator<(const NODE &tmp) const
	{
		if(price!=tmp.price)
			return price < tmp.price;
		else
			return var<tmp.var;
	}
}cow[kMAX],node;

vector<NODE> offer;

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;

  while(~scanf("%d%d",&n,&m) && n)
  {
		offer.clear();

		for(int i=0;i<n;++i)
			scanf("%d%d",&cow[i].price,&cow[i].var);
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&node.price,&node.var);
			offer.push_back(node);
		}

		sort(offer.begin(),offer.end());
    //unique(offer.begin(),offer.end());
		m=offer.size();

		bool flag=true;
		__int64 ans=0;

		for(int i=0;i<n && flag;++i)
		{
			vector<NODE>::iterator iter=lower_bound(offer.begin(),offer.end(),cow[i]);
			if(iter==offer.end())
				flag=false;
			else
			{
				ans+=iter->price;
				offer.erase(remove(offer.begin(),offer.end(),*iter),offer.end());
			}
		}

		if(!flag)
			printf("-1\n");
		else
			printf("%I64d\n",ans);


  }

  return 0;
}

