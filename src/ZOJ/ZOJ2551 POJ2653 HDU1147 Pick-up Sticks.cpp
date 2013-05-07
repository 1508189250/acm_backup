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
#include <list>
#define MAX 120
#define EPS 1e-10
using namespace std;

/************************************************************************/
/* ��Ķ���                                                             */
/************************************************************************/
struct POINT
{
	double x,y;
}point[MAX];

/************************************************************************/
/* �߶εĶ���                                                           */
/************************************************************************/
struct LINE{
	POINT a,b;
	int id;
}line[MAX];

bool inline _equal(const double &lhs,const double &rhs){	
	return fabs(lhs-rhs)< EPS;  }

/************************************************************************/
/* ��������ac��ab�ķ���Ĳ��                                           */
/************************************************************************/
double inline crossProduct(const POINT &a,const POINT &b,const POINT &c)	{
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}

/************************************************************************/
/* ȷ�������߶��Ƿ��ཻ�����˵��ཻ��                                   */
/************************************************************************/
int   intersect(const LINE  &lhs,const LINE &rhs)  
{  
	return((max(lhs.a.x,lhs.b.x)>=min(rhs.a.x,rhs.b.x))&&  
		(max(rhs.a.x,rhs.b.x)>=min(lhs.a.x,lhs.b.x))&&  
		(max(lhs.a.y,lhs.b.y)>=min(rhs.a.y,rhs.b.y))&&  
		(max(rhs.a.y,rhs.b.y)>=min(lhs.a.y,lhs.b.y))&&  
		(crossProduct(lhs.a,lhs.b,rhs.a)*crossProduct(lhs.a,rhs.b,lhs.b)>=0)&&  
		(crossProduct(rhs.a,rhs.b,lhs.a)*crossProduct(rhs.a,lhs.b,rhs.b)>=0));  
} 


/************************************************************************/
/* �ж��������Ƿ����                                                   */
/************************************************************************/
bool inline Euqal_Point(const POINT & p1,const POINT & p2)  
{  
	return(_equal(p1.x,p2.x) && _equal(p1.y,p2.y));  
}   

/************************************************************************/
/*һ���߶��ཻ�жϺ��������ҽ���u,v�ཻ���ҽ��㲻��u,v�Ķ˵�ʱ����Ϊtrue*/
/************************************************************************/
bool segIntersect(const LINE & u,const LINE &v)  
{  
	return((intersect(u,v))&&  
		(!Euqal_Point(u.a,v.a))&&  
		(!Euqal_Point(u.a,v.b))&&  
		(!Euqal_Point(u.b,v.a))&&  
		(!Euqal_Point(u.b,v.b)));  
} 


int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	list<LINE> mlist;
	LINE tline;
	int n;

	while(scanf("%d",&n)&&n)
	{
		mlist.clear();
		for(int i=1;i<=n;++i)
		{
			scanf("%lf%lf%lf%lf",&tline.a.x,&tline.a.y,&tline.b.x,&tline.b.y);
			tline.id=i;
			for(list<LINE>::iterator iter=mlist.begin();iter!=mlist.end();)
			{
				if(segIntersect(*iter,tline))
					iter=mlist.erase(iter);
				else
					++iter;
			}
			mlist.push_back(tline);
		}
		int flag=1;
		printf("Top sticks: ");
		for(list<LINE>::iterator iter=mlist.begin();iter!=mlist.end();++iter)
		{
			if(flag)
				flag=0;
			else
				printf(", ");
			printf("%d",iter->id);
		}
		printf(".\n");
	}


	return 0;
}
