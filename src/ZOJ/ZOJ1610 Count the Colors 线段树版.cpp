/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-17 18:47
 # Filename: ZOJ1610 Count the Colors 线段树版.cpp
 # Description : 
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
#define MAX 8010
using namespace std;

struct NODE_T
{int l,r,color;}node[MAX*3];

int color[MAX],len[MAX];

void init()
{
	memset(node,'\0',sizeof(node));
	memset(color,-1,sizeof(color));
	memset(len,0,sizeof(len));
}

void build(const int &t,const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
	node[t].color=-1;
	if(l==r-1) return;
	int mid = (l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void Update(const int &t,const int &l,const int &r,const int &color)
{
	if(node[t].l>=l && node[t].r<=r)
	{
		node[t].color = color;
		return;
	}
	if(node[t].color == color)
		return;
	if(node[t].color>=0)
	{
		node[L(t)].color = node[t].color;
		node[R(t)].color =  node[t].color;
		node[t].color = -1;
	}
	int mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		Update(R(t),l,r,color);
	else if(r<=mid)
		Update(L(t),l,r,color);
	else
	{
		Update(L(t),l,mid,color);
		Update(R(t),mid,r,color);
	}
}

void compute(const int &t,const int &l,const int &r)
{
	if(node[t].color>=0)
	{
		for(int i=l;i<r;++i)
			color[i]=node[t].color;
		return;
	}
	if(node[t].l==node[t].r-1)
		return;
	int mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		compute(R(t),l,r);
	else if(r<=mid)
		compute(L(t),l,r);
	else
	{
		compute(L(t),l,mid);
		compute(R(t),mid,r);
	}
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int n,x,y,col;
  while(~scanf("%d",&n))
  {
	  init();
	  build(1,0,8000);
	  while(n--)
	  {
		  scanf("%d%d%d",&x,&y,&col);
		  Update(1,x,y,col);
	  }
	  compute(1,0,8000);
	  for(int i=0;i<MAX-1;++i)
		  if(color[i+1]!=color[i] && color[i]!=-1)
			  ++len[color[i]];

	  for(int i=0;i<MAX;++i)
		  if(len[i])
			  printf("%d %d\n",i,len[i]);
	  printf("\n");
  }

  return 0;
}
