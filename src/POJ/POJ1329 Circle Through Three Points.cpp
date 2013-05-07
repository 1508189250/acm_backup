// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#define EPS 1e-3
using namespace std;

/************************************************************************/
/* 点的定义                                                             */
/************************************************************************/
struct POINT
{
	double x,y;
};

/************************************************************************/
/* 计算两点的距离                                                       */
/************************************************************************/
double inline Distance(const POINT &lhs,const POINT &rhs)
{
	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }

/************************************************************************/
/* 两直线的交点                                                         */
/************************************************************************/
POINT intersectPoint(const POINT &a,const POINT &b,const POINT &c,const POINT &d)
{
	POINT ans;
	if(_equal(a.y,b.y))
	{
		ans.y=a.y;
		double f=(d.x-c.x)/(d.y-c.y);
		ans.x=f*(ans.y-c.y)+c.x;
		return ans;
	}
	if (_equal(c.y,d.y))
	{
		ans.y=c.y;
		double e=(b.x-a.x)/(b.y-a.y);
		ans.x=e*(ans.y-a.y)+a.x;
		return ans;
	}
	double e=(b.x-a.x)/(b.y-a.y);
	double f=(d.x-c.x)/(d.y-c.y);
	ans.y = (e*a.y-a.x-f*c.y+c.x)/(e-f);
	ans.x = e*ans.y-e*a.y+a.x;
	return ans;
}

/************************************************************************/
/* 获取三角形外心算法                                                   */
/************************************************************************/
POINT circumcenter(const POINT &pa,const POINT &pb, const POINT &pc)
{
	POINT a,b,c,d;
	a.x=(pa.x+pb.x)/2;	//根据k1=-1/k2获取ab的中垂线,其中k为斜率
	a.y=(pa.y+pb.y)/2;
	b.x=a.x-pa.y+pb.y;
	b.y=a.y+pa.x-pb.x;

	c.x=(pa.x+pc.x)/2;
	c.y=(pa.y+pc.y)/2;
	d.x=c.x-pa.y+pc.y;
	d.y=c.y+pa.x-pc.x;

	return intersectPoint(a,b,c,d);
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	POINT pa,pb,pc;
	double cx,cy;
	while(~scanf("%lf%lf%lf%lf%lf%lf",&pa.x,&pa.y,&pb.x,&pb.y,&pc.x,&pc.y))
	{
		POINT ans=circumcenter(pa,pb,pc);
		cx=ans.x;
		cy=ans.y;
		double r=Distance(ans,pa);
		double a=2*cx;
		double b=2*cy;
		double c=cx*cx+cy*cy-r*r;
		printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",_less_or_equal(cx,0.0)?'+':'-',fabs(cx),_less_or_equal(cy,0.0)?'+':'-',fabs(cy),r);
		printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n",_less_or_equal(a,0.0)?'+':'-',fabs(a),_less_or_equal(b,0.0)?'+':'-',fabs(b),_less_or_equal(0.0,c)?'+':'-',fabs(c));
	}

	return 0;
}
