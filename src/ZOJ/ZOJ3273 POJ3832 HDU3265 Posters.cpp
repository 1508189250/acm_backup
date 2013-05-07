/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-18 20:11
 # Filename: HDU1689 Just a Hook.cpp
 # Description : 线段树求矩形并
 ******************************************************************************/
#ifdef _MSC_VER
#define DEBUG
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
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MAX 200010
using namespace std;

struct NODE
{
	int l,r,length,cover;
}node[MAX*4];

struct LINE
{
	int x,y1,y2,flag;
}line[MAX*2];

int y_coord[MAX*2];

void add_line(const int &x1,const int &x2,const int &y1,const int &y2,int &cnt)
{
	line[cnt].x=x1;
	line[cnt].y1=y1;
	line[cnt].y2=y2;
	line[cnt++].flag=1;
	line[cnt].x=x2;
	line[cnt].y1=y1;
	line[cnt].y2=y2;
	line[cnt++].flag=-1;
}

bool inline cmp(const LINE &lhs,const LINE &rhs)
{
	return lhs.x<rhs.x;
}

void init()
{
	memset(node,0,sizeof(node));
}

void build(const int &t,const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
	if(l==r-1) 
		return;
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void len(const int &t)
{
	if(node[t].cover>0)
		node[t].length = y_coord[node[t].r]-y_coord[node[t].l];
	else if(node[t].l==node[t].r-1)
		node[t].length=0;
	else
		node[t].length = node[R(t)].length+node[L(t)].length;
}

void update(const int &t,const LINE &lne)
{
	if(y_coord[node[t].l]>=lne.y1 && y_coord[node[t].r]<=lne.y2)
	{
		node[t].cover+=lne.flag;
		len(t);
		return;
	}
	if(node[t].l==node[t].r-1) return;
	int mid = (node[t].l+node[t].r)>>1;
	if(lne.y1<=y_coord[mid])
		update(L(t),lne);
	if(lne.y2>y_coord[mid])
		update(R(t),lne);
	len(t);
}

__int64 solve(const int &n,const int &cnt)
{
	init();
	build(1,0,cnt-1);
	update(1,line[0]);
	__int64 sum=0ll;
	for(int i=1;i<n;++i)
	{
		sum+=(line[i].x-line[i-1].x)*1ll*node[1].length;
		update(1,line[i]);
	}
	return sum;
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
  int x1,y1,x2,y2,x3,y3,x4,y4;

  while(scanf("%d",&n) && n)
  {
	  int cnt=0,y_cnt=0;
	  for(int i=0;i<n;++i)
	  {
		  scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		  add_line(x1,x3,y1,y2,cnt);
		  add_line(x3,x4,y1,y3,cnt);
		  add_line(x3,x4,y4,y2,cnt);
		  add_line(x4,x2,y1,y2,cnt);
		  y_coord[y_cnt++]=y1;
		  y_coord[y_cnt++]=y2;
		  y_coord[y_cnt++]=y3;
		  y_coord[y_cnt++]=y4;
	  }
	  sort(line,line+cnt,cmp);
	  sort(y_coord,y_coord+y_cnt);
	  y_cnt=unique(y_coord,y_coord+y_cnt)-y_coord;
	  printf("%I64d\n",solve(cnt,y_cnt));
  }

  return 0;
}
