/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-02-13 21:12
 # Filename: ZOJ1360 POJ1328 Radar Installation.cpp
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
#define MAX 100010
#define EPS 1e-6
using namespace std;

// 点的定义
struct POINT{
  double l,r;
  bool operator<(const POINT &t) const
  {
    return l<t.l;
  }
}point[MAX];

int func(const double &d,const int &n)
{
	int ans=1;
	double pre=point[0].r;
	for(int i=1;i<n;++i)
		if(point[i].l-pre>EPS)  //前一区间没有嵌套后一区间
		{
			++ans;
			pre=point[i].r;
		}
    else if(point[i].r-pre<EPS) //前一区间嵌套了后一区间
      pre=point[i].r;
	return ans;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int ncases=1,n,d;
	double x,y;

	while(scanf("%d%d",&n,&d)&&(n||d))
	{
		bool flag=true;
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf",&x,&y);
			if(flag && y-d*1.0<EPS)
			{
				double temp=sqrt(d*d-y*y);
				point[i].l=x-temp;
				point[i].r=x+temp;
			}
			else
				flag=false;
		}
		if(!flag)
    {
			printf("Case %d: -1\n",ncases++);
      continue;
    }

		sort(point,point+n);
		int ans=func(d,n);
		printf("Case %d: %d\n",ncases++,ans);
	}

  return 0;
}
