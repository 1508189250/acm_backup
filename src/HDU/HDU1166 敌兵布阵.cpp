/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-18 18:23
 # Filename: HDU1166 敌兵布阵.cpp
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
#define MAX 50010
using namespace std;

struct NODE_T
{
	int l,r,sum;
}node[MAX*4];

void init()
{
	memset(node,'\0',sizeof(node));
}

void build(const int &t,const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
	node[t].sum=0;
	if(l==r-1)
		return;
	int mid = (l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void update(const int &t,const int &l,const int &r,const int &val)
{
	node[t].sum+=val;
	if(node[t].l==node[t].r-1)
		return;

  int mid=(node[t].l+node[t].r)>>1;
	if(l>=mid)
		update(R(t),l,r,val);
	else if(r<=mid)
		update(L(t),l,r,val);
	else
	{
		update(L(t),l,mid,val);
		update(R(t),mid,r,val);
	}
}

int query(const int &t,const int &l,const int &r)
{
	if(node[t].l==l && node[t].r==r)
		return node[t].sum;
	int mid=(node[t].l+node[t].r)>>1;
	if(l>=mid)
		return query(R(t),l,r);
	else if(r<=mid)
		return query(L(t),l,r);
	else 
		return query(L(t),l,mid)+query(R(t),mid,r);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  
  int ncases,n;
  int x,y;
  char str[10];

  scanf("%d",&ncases);
  for(int nc=1;nc<=ncases;++nc)
  {
	  printf("Case %d:\n",nc);
	  init();
	  scanf("%d",&n);
	  build(1,0,n+1);
	  for(int i=1;i<=n;++i)
	  {
		  scanf("%d",&x);
		  update(1,i,i+1,x);
	  }
    getchar();
	  while(scanf("%s",str) && str[0]!='E')
	  {
		  scanf("%d%d",&x,&y);
		  if(str[0]=='A')
			  update(1,x,x+1,y);
		  else if(str[0]=='S')
			  update(1,x,x+1,-y);
		  else
			  printf("%d\n",query(1,x,y+1));
	  }
  }

  return 0;
}
