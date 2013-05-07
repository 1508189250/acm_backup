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
	int l,r,val;
}node[MAX*4];

void init()
{
	memset(node,'\0',sizeof(node));
}

void build(const int &t , const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
	node[t].val=1;
  if(l==r-1)
    return;
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void update(const int &t,const int &l,const int &r,const int &val)
{
	if(node[t].l==l && node[t].r==r)
  {
    node[t].val=val;
		return;
  }
	if(node[t].val>0)
	{
		node[R(t)].val = node[t].val;
		node[L(t)].val = node[t].val;
		node[t].val=-1;
	}
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
	if(node[t].val>0)
		return (node[t].r-node[t].l)*node[t].val;
	int mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		return query(R(t),l,r);
	else if(r<=mid)
		return query(L(t),l,r);
	else return query(L(t),l,mid)+query(R(t),mid,r);
}

int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int ncases,n,q;
  int x,y,z;

  scanf("%d",&ncases);
  for(int nc=1;nc<=ncases;++nc)
  {
	  scanf("%d",&n);
	  init();
	  build(1,1,n+1);
	  scanf("%d",&q);
	  while(q--)
	  {
		  scanf("%d%d%d",&x,&y,&z);
		  update(1,x,y+1,z);
	  }
	  printf("Case %d: The total value of the hook is %d.\n",nc,query(1,1,n+1));
  }

  return 0;
}
