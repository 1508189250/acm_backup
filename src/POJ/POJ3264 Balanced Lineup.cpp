/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-18 20:11
 # Filename: HDU1689 Just a Hook.cpp
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
#define MAX 100010
using namespace std;

struct NODE
{
	int l,r,max_val,min_val;
}node[MAX*4];

void init()
{
	memset(node,'\0',sizeof(node));
}

int height[MAX];

void build(const int &t , const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
  if(l==r-1)
  {
	  node[t].max_val=height[l];
	  node[t].min_val=height[l];
    return;
  }
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
	node[t].max_val = max(node[L(t)].max_val,node[R(t)].max_val);
	node[t].min_val = min(node[L(t)].min_val,node[R(t)].min_val);
}

int query_max(const int &t,const int &l,const int &r)
{
	if(node[t].l==l && node[t].r==r)
		return node[t].max_val;
	int mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		return query_max(R(t),l,r);
	else if(r<=mid)
		return query_max(L(t),l,r);
	else return max(query_max(L(t),l,mid),query_max(R(t),mid,r));
}

int query_min(const int &t,const int &l,const int &r)
{
	if(node[t].l==l && node[t].r==r)
		return node[t].min_val;
	int mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		return query_min(R(t),l,r);
	else if(r<=mid)
		return query_min(L(t),l,r);
	else return min(query_min(L(t),l,mid),query_min(R(t),mid,r));
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n,m;
  int x,y,z;
  height[0]=0;

  while(~scanf("%d %d",&n,&m))
  {
	  for(int i=1;i<=n;++i)
		  scanf("%d",&height[i]);
	  init();
	  build(1,0,n+1);
	  while(m--)
	  {
		  scanf("%d%d",&x,&y);
		  printf("%d\n",query_max(1,x,y+1)-query_min(1,x,y+1));
	  }
  }

  return 0;
}
