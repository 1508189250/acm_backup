// #include "stdafx.h"
// #define DEBUG

#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <memory.h>
#include <float.h>
#include <math.h>
#include <stack>
#define EP 1e-10
#define MAX 30
using namespace std;
int n,pcou,wcou;

struct POINT{
	double x,y;
}point[MAX*5];

struct LINE{
	POINT a,b;
}line[MAX*3];

//叉积判断点线关系
double multiply (const POINT &a, const POINT &b, const POINT &c)    
{ 
	double x1 = b.x - a.x; 
	double	y1 = b.y - a.y; 
	double	x2 = c.x - b.x; 
	double	y2 = c.y - b.y; 
	return x1*y2 - x2*y1; 
} 

bool inline Euqal_Point(const POINT & p1,const POINT & p2)  
{  
	return((fabs(p1.x-p2.x)<EP)&&(fabs(p1.y-p2.y)<EP));  
}  

//确定两条线段是否相交  
bool intersect(const LINE  &u,const LINE &v)  
{  
	return(   (max(u.a.x,u.b.x)>=min(v.a.x,v.b.x))&&  
		(max(v.a.x,v.b.x)>=min(u.a.x,u.b.x))&&  
		(max(u.a.y,u.b.y)>=min(v.a.y,v.b.y))&&  
		(max(v.a.y,v.b.y)>=min(u.a.y,u.b.y))&&  
		(multiply(v.a,u.b,u.a)*multiply(u.b,v.b,u.a)>=0)&&  
		(multiply(u.a,v.b,v.a)*multiply(v.b,u.b,v.a)>=0));  
}  

//一种线段相交判断函数，当且仅当u,v相交并且交点不是u,v的端点时函数为true;  
bool segintersect(const LINE & u,const LINE &v)  
{  
	return((intersect(u,v))&&  
		 		(!Euqal_Point(u.a,v.a))&&  
		 		(!Euqal_Point(u.a,v.b))&&  
		 		(!Euqal_Point(u.b,v.a))&&  
		 		(!Euqal_Point(u.b,v.b)));  
}  

double inline distence(const POINT &lhs,const POINT &rhs)
{
	return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}

double map[4*MAX][4*MAX];

void buildmap()
{
		for(int i=0;i<pcou;++i)
			for(int j=0;j<pcou;++j)
				map[i][j]=DBL_MAX; 

		LINE ltemp;
		int flag;

		for(int i=0;i<pcou;++i)
		{
			ltemp.a=point[i];
			for(int j=i+1;j<pcou;++j)
			{
				if(point[j].x==point[i].x) continue;
				ltemp.b=point[j];
				flag=1;
				for(int k=0;k<wcou;++k)
					if(segintersect(line[k],ltemp))
					{
						flag=0;
						break;
					}
				if(flag)
					map[i][j]=distence(point[i],point[j]);
			}
		}
}

int main(void)
{
#ifdef DEBUG  
	freopen("data.txt","r",stdin);  
#endif  

	double x,y1,y2,y3,y4;

	while(scanf("%d",&n) &&n>=0)
	{
		point[0].x=0.0;
		point[0].y=5.0;
		pcou=1;
		wcou=0;

		for(int i=0;i<n;++i)
		{
			scanf("%lf %lf %lf %lf %lf",&x,&y1,&y2,&y3,&y4);
			line[wcou].a.x=x;
			line[wcou].a.y=0.0;
			point[pcou].x=x;
			point[pcou].y=y1;
			line[wcou++].b=point[pcou++];
			point[pcou].x=x;
			point[pcou].y=y2;
			line[wcou].a=point[pcou++];
			point[pcou].x=x;
			point[pcou].y=y3;
			line[wcou++].b=point[pcou++];
			point[pcou].x=x;
			point[pcou].y=y4;
			line[wcou].a=point[pcou++];
			line[wcou].b.x=x;
			line[wcou++].b.y=10.0;
		}
		point[pcou].x=10.0;
		point[pcou++].y=5.0;

		buildmap();
		for(int k=0;k<pcou;++k)
			for(int i=0;i<pcou;++i)
				for(int j=0;j<pcou;++j)
					map[i][j] = min(map[i][j],map[i][k]+map[k][j]);

		printf("%.2lf\n",map[0][pcou-1]);

	}

	return 0;
}