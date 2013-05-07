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

const int kMAX=10010;

struct NODE
{
	double a,b,y;
	bool inline operator<(const NODE &tmp) const 
	{
		if(a==tmp.a)
			return y<tmp.y;
		else 
			return a<tmp.a;
	}
}node[kMAX],house,line;

double inline GetLen(const double &var,const double &lhs,const double &rhs)
{
	return var*rhs/lhs;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int n;

	while(1)
  {
		scanf("%lf%lf%lf",&house.a,&house.b,&house.y);
		if(house.a==0 && house.b==0 && house.y==0)
			break;

		scanf("%lf%lf%lf",&line.a,&line.b,&line.y);
		scanf("%d",&n);

		for(int i=0;i<n;++i)
			scanf("%lf%lf%lf",&node[i].a,&node[i].b,&node[i].y);
		sort(node,node+n);

		double ans=-1.0,idx=line.a;
		for(int i=0;i<n;++i)
		{
			if(node[i].y>=house.y || node[i].y<line.y)
				continue;

			double lhs=node[i].a-GetLen(house.b-node[i].a,house.y-node[i].y,node[i].y-line.y);
			if(lhs>=line.b) continue;
			if(lhs>idx)
				ans=max(ans,lhs-idx);

			double rhs=node[i].b+GetLen(node[i].b-house.a,house.y-node[i].y,node[i].y-line.y);
      idx=max(idx,rhs);
      if(idx>=line.b) continue;
		}

		if(idx<line.b)
			ans=max(ans,line.b-idx);
		if(ans>0.0)
			printf("%.2lf\n",ans);
		else
			printf("No View\n");
  }

  return 0;
}

