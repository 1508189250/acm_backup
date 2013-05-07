/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2011-11-19 18:57
 # Filename: ZOJ1377 POJ1228 Grandpa's Estate.cpp
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
#include <memory.h>
#include <limits.h>
#include <algorithm>
#include <math.h>
#define MAX 1020
#define EPS 1e-6
using namespace std;

int result[kMAX];
bool used[kMAX];

struct POINT
{
	int id;
	double x,y,val,len;
}point[MAX];

double inline Distance(const POINT &lhs,const POINT &rhs)
{
	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	
//向量ac在ab的方向
{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

/************************************************************************/
/*double的大小判断                                                      */
/************************************************************************/
bool inline _less(const double &lhs,const double &rhs)			{	return lhs < rhs - EPS;  }
bool inline _less_or_equal(const double &lhs,const double &rhs)	{	return lhs < rhs + EPS;  }
bool inline _equal(const double &lhs,const double &rhs)			{	return fabs(lhs-rhs)< EPS;  }
bool inline _greater(const double &lhs,const double &rhs)		{	return lhs>rhs+EPS;}
bool inline _greater_ou_equal(const double &lhs,const double &rhs){	return lhs>rhs-EPS;}

/************************************************************************/
/* 按照点的坐标排序，使得最左下角的点排在首位                           */
/************************************************************************/
bool inline cmpByCoordinate(const POINT &lhs,const POINT &rhs)
{
	if (_equal(lhs.y,rhs.y))
		return _less(lhs.x,rhs.x);
	else
		return _less(lhs.y,rhs.y);
}

/************************************************************************/
/* 按照点相对于左下角的点的极角排序，使其按逆时针扇形排列               */
/************************************************************************/
bool inline cmpByPolarAngle(const POINT &lhs,const POINT &rhs)
{
	double temp=crossProduct(point[0],lhs,rhs);
	if (_equal(temp,0.0))
		return	_less(Distance(lhs,point[0]),Distance(rhs,point[0]));
	else
		return _less(temp,0.0);
}

POINT *stk[MAX];  // 用指针来保存凸包的顶点，减少运算时间
int graham(const int &n)
{
	sort(point,point+n,cmpByCoordinate);
	sort(point+1,point+n,cmpByPolarAngle);	//这样排序使得各点相对于point[0]成扇形分布

	if (!_equal(crossProduct(point[0],point[1],point[2]),0.0))
	{
		return false;
	}
	for(int i=0;i<3;++i)
		stk[i]=&point[i];
	int top=2;

	// 求凸包
	for(int i=3;i<n;++i)
	{
		while(top!=0)
		{
			POINT *a = stk[top];
			POINT *b = stk[top-1];
			if(_less_or_equal(crossProduct(*a,*b,point[i]),0.0))
				--top;
			else
				break;
		}
		stk[++top]=&point[i];
	}
	++top;

  return top;
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  
	int n;
	int ncases;

	while(scanf("%d",&n) && n)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%lf%lf%lf%lf",&point[i].x,&point[i].y,&point[i].val,&point[i].len);

		int num=(1<<(n-1));
		int min_val=INT_MAX,cnt;
		for(int x=0;x<num;++x)
		{
		}
	}

	return 0;
}
