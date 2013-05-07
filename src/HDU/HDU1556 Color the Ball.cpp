/*******************************************************************************
 # Author : Neo Fung
 # Email : neosfung@gmail.com
 # Last modified: 2012-01-21 21:42
 # Filename: HDU1556 Color the Ball.cpp
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
	int l,r,add,val;
}node[MAX*4];


void init()
{
	memset(node,'\0',sizeof(node));
}

void build(const int &t , const int &l,const int &r)
{
  if(l>=r) return;
	node[t].l=l;
	node[t].r=r;
  if(l==r-1)
    return;
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid,r);
}

void update(const int &t,const int &l,const int &r,const int &add)
{
  if(l>=r) return;
	if(node[t].l==l && node[t].r==r)
  {
		node[t].add+=add;
    node[t].val+=add*(r-l);
		return;
  }
	if(node[t].add )
	{
		node[R(t)].add += node[t].add;
    node[R(t)].val += node[t].add*(node[R(t)].r - node[R(t)].l);
    node[L(t)].add += node[t].add;    
    node[L(t)].val += node[t].add*(node[L(t)].r - node[L(t)].l);
		node[t].add=0;
	}
	int mid=(node[t].l+node[t].r)>>1;
	if(l>=mid)
		update(R(t),l,r,add);
	else if(r<=mid)
		update(L(t),l,r,add);
	else
	{
		update(L(t),l,mid,add);
		update(R(t),mid,r,add);
	}
	node[t].val=node[R(t)].val+node[L(t)].val;
}

int query(const int &t,const int &l,const int &r)
{
	if(node[t].l==l && node[t].r==r)
		return node[t].val;

  if(node[t].add )
  {
    node[R(t)].add += node[t].add;
    node[R(t)].val += node[t].add*(node[R(t)].r - node[R(t)].l);
    node[L(t)].add += node[t].add;    
    node[L(t)].val += node[t].add*(node[L(t)].r - node[L(t)].l);
    node[t].add=0;
  }

	int mid = (node[t].l+node[t].r)>>1;
	if(l>=mid)
		return query(R(t),l,r);
	else if(r<=mid)
		return query(L(t),l,r);
	else 
		return	query(L(t),l,mid)+query(R(t),mid,r);
}


int main(void)
{
#ifdef DEBUG  
  freopen("../stdin.txt","r",stdin);
  freopen("../stdout.txt","w",stdout); 
#endif  

  int n;
  int x,y;

  while(~scanf("%d",&n)&&n)
  {
	  init();
	  build(1,0,n+1);
	  for(int i=0;i<n;++i)
	  {
		  scanf("%d%d",&x,&y);
		  update(1,x,y+1,1);
	  }
	  for(int i=1;i<=n;++i)
		  printf("%d%c",query(1,i,i+1),i==n?'\n':' ');
  }

  return 0;
}
