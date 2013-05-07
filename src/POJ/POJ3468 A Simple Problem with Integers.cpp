/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-20 20:48
 # Filename: POJ3468 A Simple Problem with Integers.cpp
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

struct NODE_T
{
	int l,r;
	long long val,sum;
}node[MAX*4];

int val[MAX];

void init()
{
	memset(node,0,sizeof(node));
}

void build(const int &t,const int &l,const int &r)
{
	node[t].l=l;
	node[t].r=r;
	if(l==r-1)
	{
		node[t].sum = val[l];
		return;
	}
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
	node[t].sum=node[L(t)].sum+node[R(t)].sum;
}

void update(const int &t,const int &l,const int &r,const long long &val)
{
	if(node[t].l==l && node[t].r==r)
	{
		node[t].val+=val;
		node[t].sum+=val * (r-l);
		return;
	}
	if(node[t].val)
	{
		node[L(t)].val +=node[t].val;
		node[R(t)].val += node[t].val;
		node[L(t)].sum += node[t].val * (node[L(t)].r - node[L(t)].l);
		node[R(t)].sum += node[t].val * (node[R(t)].r - node[R(t)].l);
		node[t].val = 0;
	}
	int mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		update(R(t),l,r,val);
	else if(r<=mid)
		update(L(t),l,r,val);
	else
	{
		update(L(t),l,mid,val);
		update(R(t),mid,r,val);
	}
	node[t].sum = node[L(t)].sum+node[R(t)].sum;
}

long long query(const int &t,const int &l,const int &r)
{
	if(node[t].l==l &&node[t].r==r)
		return node[t].sum;
  if(node[t].val)
  {
    node[L(t)].val+=node[t].val;
    node[R(t)].val+=node[t].val;
    node[L(t)].sum+=node[t].val * (node[L(t)].r-node[L(t)].l);
    node[R(t)].sum+=node[t].val * (node[R(t)].r-node[R(t)].l);
    node[t].val=0;
  }

	int mid = (node[t].l+node[t].r)>>1;
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
  int n,m,x,y;
  long long z;
  char ch;

  while(~scanf("%d%d",&n,&m))
  {
	  for(int i=0;i<n;++i)
		  scanf("%d",&val[i]);
	  init();
	  build(1,0,n+1);
	  while(m--)
	  {
		  getchar();
		  scanf("%c",&ch);
		  if(ch=='Q')
		  {
			  scanf("%d%d",&x,&y);
			  printf("%lld\n",query(1,x-1,y));
		  }
		  else
		  {
			  scanf("%d%d%lld",&x,&y,&z);
        if(z)
          update(1,x-1,y,z);
		  }
	  }
  }

  return 0;
}
