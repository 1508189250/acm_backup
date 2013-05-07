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
#define MAX 120
#define EPS 1e-8
using namespace std;

// double的大小判断
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }

// 点的定义
struct POINT{
  double x,y;
}point[2*MAX];

// 线段的定义
struct LINE{
  POINT a,b;
  void get()
  {
    scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
  }
}line[MAX];

// 计算向量ac在ab的方向的叉积
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
  return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

// 计算两点的距离
double inline Distance(const POINT &lhs,const POINT &rhs)
{
  return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

bool  intersect(const POINT  &a,const POINT &b,const POINT &c,const POINT &d)  
{  
  return _less_or_equal(crossProduct(a,b,c)*crossProduct(a,b,d),0.0);
} 

bool func(const POINT &a,const POINT &b,const int &n)
{
	for(int i=0;i<n;++i)
		if(!intersect(a,b,line[i].a,line[i].b))
			return false;
	return true;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

	int  ncases,n;
	scanf("%d",&ncases);

	while(ncases--)
	{
		scanf("%d",&n);
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			line[i].get();
			point[cnt++]=line[i].a;
			point[cnt++]=line[i].b;
		}

		bool ans=false;
		for(int i=0;i<cnt && !ans;++i)
			for(int j=i+1;j<cnt && !ans ;++j)
				if(Distance(point[i],point[j])<EPS)
					continue;
				else
					ans=func(point[i],point[j],n);

		if(ans)
			printf("Yes!\n");
		else
			printf("No!\n");
	}

  return 0;
}
