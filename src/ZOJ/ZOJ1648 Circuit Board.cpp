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
#define MAX 2010
#define EP 1e-10
using namespace std;

struct POINT{
	double x,y;
};

struct LINE{
	POINT a,b;
}line[MAX];

//����жϵ��߹�ϵ
double multiply (const POINT &a, const POINT &b, const POINT &c)    
{ 
	double x1 = b.x - a.x; 
	double	y1 = b.y - a.y; 
	double	x2 = c.x - b.x; 
	double	y2 = c.y - b.y; 
	return x1*y2 - x2*y1; 

} 

//ȷ�������߶��Ƿ��ཻ  
int   intersect(const LINE  &u,const LINE &v)  
{  
	return(   (max(u.a.x,u.b.x)>=min(v.a.x,v.b.x))&&  
		(max(v.a.x,v.b.x)>=min(u.a.x,u.b.x))&&  
		(max(u.a.y,u.b.y)>=min(v.a.y,v.b.y))&&  
		(max(v.a.y,v.b.y)>=min(u.a.y,u.b.y))&&  
		(multiply(v.a,u.b,u.a)*multiply(u.b,v.b,u.a)>=0)&&  
		(multiply(u.a,v.b,v.a)*multiply(v.b,u.b,v.a)>=0));  
}  

//�ж��������Ƿ����  
bool inline Euqal_Point(const POINT & p1,const POINT & p2)  
{  
	return((fabs(p1.x-p2.x)<EP)&&(fabs(p1.y-p2.y)<EP));  
}  

//һ���߶��ཻ�жϺ��������ҽ���u,v�ཻ���ҽ��㲻��u,v�Ķ˵�ʱ����Ϊtrue;  
bool segintersect(const LINE & u,const LINE &v)  
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
	int n;

	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;++i)
			scanf("%lf%lf%lf%lf",&line[i].a.x,&line[i].a.y,&line[i].b.x,&line[i].b.y);

		bool ans=false;
		for(int i=0;i<n&&!ans;++i)
			for(int j=i+1;j<n;++j)
				if(ans=intersect(line[i],line[j]))
					break;
		if(ans)
			printf("burned!\n");
		else
			printf("ok!\n");
	}

	return 0;
}
